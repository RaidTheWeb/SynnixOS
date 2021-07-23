#include <basic.h>
#include <assert.h>
#include <ctype.h>
#include <elf.h>
#include <snx/debug.h>
#include <snx/fs.h>
#include <snx/memmap.h>
#include <snx/string.h>
#include <snx/syscall.h>
#include <snx/thread.h>
#include <stdlib.h>

/** @file
 * @brief Execute Process Helpers
 * 
 */

struct args_size {
    size_t count;
    size_t strlen;
};

static struct args_size size_args(char *const args[]) {
    size_t i = 0, arg_count, string_len = 0;
    while (args[i]) {
        string_len += strlen(args[i]) + 1;
        i += 1;
    }
    arg_count = i;

    return (struct args_size){arg_count, string_len};
}

static size_t partial_copy_args(char **addrs, char *strings, char *const args[],
                                size_t count) {
    size_t str_offset = 0;
    for (size_t i = 0; i < count; i++) {
        strcpy(strings + str_offset, args[i]);
        addrs[i] = strings + str_offset;
        str_offset += strlen(args[i]) + 1;
    }
    return str_offset;
}

char *const *exec_concat_args(char *const a1[], char *const a2[]) {
    struct args_size s1 = size_args(a1);
    struct args_size s2 = size_args(a2);
    size_t arg_count = s1.count + s2.count;
    size_t string_len = s1.strlen + s2.strlen;

    char **out = malloc((arg_count + 1) * sizeof(char *) + string_len);
    char *strings = (char *)out + (arg_count + 1) * sizeof(char *);

    size_t string_offset = partial_copy_args(out, strings, a1, s1.count);
    partial_copy_args(out + s1.count, strings + string_offset, a2, s2.count);
    out[arg_count] = 0;
    return out;
}

char *const *exec_copy_args(char **out, char *const args[]) {
    if (!args) return NULL;
    struct args_size size = size_args(args);
    if (!out) out = malloc((size.count + 1) * sizeof(char *) + size.strlen);
    char *strings = (char *)out + (size.count + 1) * sizeof(char *);
    partial_copy_args(out, strings, args, size.count);
    out[size.count] = 0;
    return out;
}

/**
 * @brief Parses args
 */
size_t exec_parse_args(char **addrs, size_t len, char *str, size_t str_len) {
    size_t arg_i = 0;
    for (size_t i = 0; str[i] && i < str_len; i++) {
        if (str[i] == ' ') str[i] = 0;
        if (i == 0 || (str[i - 1] == 0 && !isspace(str[i]))) {
            if (arg_i >= len) return arg_i;
            addrs[arg_i++] = &str[i];
        }
    }
    return arg_i;
}

size_t argc(char *const args[]) {
    if (!args) return 0;
    size_t i;
    for (i = 0; args[i]; i++) {}
    return i;
}

// LOAD ELF

elf_md *exec_open_elf(struct file *file) {
    if (file->type != FT_BUFFER) return NULL;
    struct membuf_file *membuf_file = (struct membuf_file *)file;
    void *buffer = membuf_file->memory;

    elf_md *e = elf_parse(buffer, file->len);
    return e;
}

bool exec_load_elf(elf_md *e, bool image) {
    elf_load(e);
    return 0;
}

/**
 * @brief Clear memory maps and reinitialize the critial ones
 */
void exec_memory_setup(void) {
    for (int i = 0; i < NREGIONS; i++) {
        running_process->mm_regions[i].base = 0;
    }
    user_map(USER_STACK - 0x100000, USER_STACK);
    user_map(USER_ARGV, USER_ARGV + 0x2000);
    user_map(USER_ENVP, USER_ENVP + 0x2000);
    user_map(SIGRETURN_THUNK, SIGRETURN_THUNK + 0x1000);
    memcpy((void *)SIGRETURN_THUNK, signal_handler_return, 0x10);
}

const char *exec_shebang(struct file *file) {
    if (file->type != FT_BUFFER) return false;
    struct membuf_file *membuf_file = (struct membuf_file *)file;
    char *buffer = membuf_file->memory;
    if (file->len > 2 && buffer[0] == '#' && buffer[1] == '!') {
        return buffer + 2;
    }
    return NULL;
}

const char *exec_interp(elf_md *e) {
    const Elf_Phdr *interp = elf_find_phdr(e, PT_INTERP);
    if (!interp) return NULL;
    return (char *)e->buffer + interp->p_offset;
}

static void exec_frame_setup(interrupt_frame *frame) {
    memset(frame, 0, sizeof(struct interrupt_frame));

    frame->ds = 0x20 | 3;
    frame->cs = 0x18 | 3;
    frame->ss = 0x20 | 3;
    frame->flags = INTERRUPT_ENABLE;

    frame->user_sp = USER_STACK - 16;
    frame->bp = USER_STACK - 16;
}

sysret do_execve(struct file *file, struct interrupt_frame *frame,
                 const char *filename, char *const argv[], char *const envp[]) {
    if (running_process->pid == 0) {
        printf("WARN: an attempt was made to `execve` the kernel. Ignoring!\n");
        return -EINVAL;
    }

    if (!(file->mode & USR_EXEC)) return -ENOEXEC;

    const char *path_tmp;
    char *const *stored_args = {0};
    char interp_buf[256] = {0};
    uintptr_t loadp = 0;

    exec_memory_setup();
    strncpy(running_process->comm, basename(filename), COMM_SIZE);

    if ((path_tmp = exec_shebang(file))) {

        strncpyto(interp_buf, path_tmp, 256, '\n');
        char *interp_args[8] = {0};
        exec_parse_args(interp_args, 8, interp_buf, 256);
        stored_args = exec_concat_args(interp_args, argv);

        file = fs_path(interp_args[0]);
        if (!file) return -ENOENT;
    } else {
        stored_args = exec_copy_args(NULL, argv);
    }

    elf_md *e = exec_open_elf(file);
    if (!e) return -ENOEXEC;
    running_process->elf_metadata = e;

    if ((path_tmp = exec_interp(e))) {
        printf("[Debug] Loading interpreter: %s\n", path_tmp);
        struct file *interp = fs_path(path_tmp);

        elf_md *interp_md = exec_open_elf(interp);
        if (!interp_md) return -ENOEXEC;

        bool err = exec_load_elf(interp_md, false);
        if (!err) return -ENOEXEC;
    }

    bool err = exec_load_elf(e, true);
    if (err) return -ENOEXEC;

    exec_frame_setup(frame);
    running_process->mmap_base = USER_MMAP_BASE;

    char **user_argv = (char **)USER_ARGV;
    exec_copy_args(user_argv, stored_args);

    frame->ip = (uintptr_t)e->imm_header->e_entry;
    FRAME_ARGC(frame) = argc(stored_args);
    FRAME_ARGV(frame) = (uintptr_t)user_argv;

    free((void *)stored_args);
    return 0;
}
