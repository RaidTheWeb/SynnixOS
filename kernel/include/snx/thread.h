#pragma once
#ifndef SNX_THREAD_H
#define SNX_THREAD_H

#include <elf.h>
#include <list.h>
#include <snx/dmgr.h>
#include <snx/fs.h>
#include <snx/signal.h>
#include <snx/trace.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>

extern list all_threads;

typedef char fp_ctx[512] __ALIGN(16);

enum mm_flags {
    MM_FILE = (1 << 1),
    MM_SHARED = (1 << 2),
};

struct mm_region {
    uintptr_t base;
    uintptr_t top;
    enum mm_flags flags;
    struct file *file;
};
#define NREGIONS 32

#define COMM_SIZE 32
#define PROC_MAGIC 0x434f5250 // 'PROC'
struct process {
    pid_t pid;
    pid_t pgid;
    char comm[COMM_SIZE];

    unsigned int magic; // PROC_MAGIC

    phys_addr_t vm_root;

    int uid;
    int gid;

    int exit_intention; // tells threads to exit
    int exit_status;    // tells parent has exitted

    struct process *parent;

    struct dmgr fds;
    list children;
    list threads;

    list_n siblings;

    uintptr_t mmap_base;
    struct mm_region mm_regions[NREGIONS];

    elf_md *elf_metadata;
};

enum thread_state {
    TS_INVALID,
    TS_PREINIT, // allocated, not initialized
    TS_STARTED, // initialized, not yet run
    TS_RUNNING, // able to run
    TS_BLOCKED, // generically unable to progress, probably a mutex
    TS_WAIT,    // waiting for children to die
    TS_IOWAIT,  // waiting for IO (network)
    TS_TRWAIT,  // waiting for trace(2) parent.
    TS_SLEEP,   // sleeping
    TS_DEAD,
};

enum thread_flags {
    TF_SYSCALL_TRACE = (1 << 0),  // sys_strace
    TF_IN_SIGNAL = (1 << 1),      // do_signal_call / sys_sigreturn
    TF_IS_KTHREAD = (1 << 2),     // informational
    TF_USER_CTX_VALID = (1 << 3), // c_interrupt_shim
    TF_QUEUED = (1 << 4),         // thread_enqueue / next_runnable_thread
    TF_ONCPU = (1 << 5),          // thread_switch
    TF_STOPPED = (1 << 6),        // SIGSTOP / SIGCONT
    TF_SYSCALL_TRACE_CHILDREN = (1 << 7),
};

#define THREAD_MAGIC 0x44524854 // 'THRD'

struct thread {
    pid_t tid;
    struct process *proc;

    unsigned int magic; // THREAD_MAGIC

    volatile enum thread_state state;
    enum thread_flags flags;
    enum thread_state nonsig_state; // original state before signal

    char *kstack;

    jmp_buf kernel_ctx;
    interrupt_frame *user_ctx;

    void (*entry)(void *);
    void *entry_arg;

    struct file *cwd;

    pid_t wait_request;
    struct process *wait_result;
    struct thread *wait_trace_result;

    list tracees;
    list_n trace_node;
    struct thread *tracer;
    enum trace_state trace_state;
    int trace_report;
    int trace_signal;

    list_n all_threads;
    list_n runnable;
    list_n freeable;
    list_n process_threads;
    list_n wait_node;

    struct timer_event *wait_event;

    uintptr_t user_sp;
    jmp_buf signal_ctx;

    sighandler_t sighandlers[32];
    sigset_t sig_pending;
    sigset_t sig_mask;

    long n_scheduled;

    // in kernel_ticks
    long time_ran;
    long last_scheduled;
    long long tsc_ran;
    long long tsc_scheduled;

    int irq_disable_depth;

    fp_ctx fpctx;
};

typedef struct thread gdb_thread_t;

extern struct thread *running_thread;
extern struct process *running_process;

void return_from_interrupt(void);
void set_kernel_stack(void *);
void threads_init(void);
struct process *process_by_id(pid_t pid);
struct thread *thread_by_id(pid_t tid);
void bootstrap_usermode(const char *init_filename);
// struct process *new_user_process(void);

struct thread *kthread_create(void (*)(void *), void *);
struct thread *thread_sched(bool irqs_disabled);
void thread_block(void);
void thread_block_irqsdisabled(void);
// void thread_yield(void);
// noreturn void thread_done(void);

void thread_switch(struct thread *restrict new, struct thread *restrict old);
noreturn void thread_switch_nosave(struct thread *new);
noreturn void kthread_exit(void);
// noreturn void do_thread_exit(int exit_status);
// noreturn void do_process_exit(int exit_status);

void block_thread(struct list *threads);

// void wake_blocked_thread(struct thread *th);
// void wake_blocked_threads(struct list *threads);
void wake_waitq_one(list *waitq);
void wake_waitq_all(list *waitq);

void kill_process_group(pid_t pgid);
void kill_process(struct process *p, int reason);

void kill_pid(pid_t pid);
void thread_enqueue(struct thread *);
void thread_enqueue_at_front(struct thread *);
void drop_thread(struct thread *);
struct thread *process_thread(struct process *);
void sleep_thread(int ms);
bool user_map(virt_addr_t base, virt_addr_t top);

sysret do_execve(struct file *, interrupt_frame *, const char *filename,
                 char *const argv[], char *const envp[]);

#endif
