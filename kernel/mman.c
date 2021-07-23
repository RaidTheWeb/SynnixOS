// #define DEBUG
#include <basic.h>
#include <errno.h>
#include <snx/debug.h>
#include <snx/fs.h>
#include <snx/memmap.h>
#include <snx/mman.h>
#include <snx/syscall.h>
#include <snx/thread.h>
#include <snx/vmm.h>
#include <stdio.h>

// KERNEL RESERVE MEMORY

char *kernel_reservable_vma = (char *)KERNEL_RESERVABLE_SPACE;

void *vmm_reserve(size_t len) {
    len = round_up(len, 0x1000);

    void *res = kernel_reservable_vma;
    kernel_reservable_vma += len;

    vmm_create_unbacked_range((uintptr_t)res, len, PAGE_WRITEABLE);
    return res;
}

void *high_vmm_reserve(size_t len) {
    return vmm_reserve(len);
}

sysret sys_mmap(void *addr, size_t len, int prot, int flags, int fd,
                off_t offset) {
    len = round_up(len, 0x1000);

    if (addr != NULL) return -ETODO;
    if (!(flags & MAP_PRIVATE)) return -ETODO;

    uintptr_t new_alloc = running_process->mmap_base;
    user_map(new_alloc, new_alloc + len);
    running_process->mmap_base += len;

    if (!(flags & MAP_ANONYMOUS)) {
        struct open_file *ofd = dmgr_get(&running_process->fds, fd);
        if (!ofd) return -EBADF;
        struct file *file = ofd->file;
        if (file->type != FT_BUFFER) return -ENODEV;
        struct membuf_file *membuf_file = (struct membuf_file *)file;
        size_t to_copy = min(len, file->len);
        memcpy((void *)new_alloc, membuf_file->memory, to_copy);
    }

    return new_alloc;
}

sysret sys_munmap(void *addr, size_t length) {
    // nop, TODO
    return 0;
}
