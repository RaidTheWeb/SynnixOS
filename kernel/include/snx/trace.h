#pragma once
#ifndef SNX_TRACE_H
#define SNX_TRACE_H

#include <signal.h>
#include <sys/trace.h>


/** @file
 * @brief Syscall trace helpers
 * 
 */

/**
 * @brief Enumeration for different trace commands
 * 
 */
enum trace_command {
    TR_TRACEME, // Trace syscall
    TR_ATTACH, // Attach to syscall

    TR_GETREGS, // Get registers
    TR_SETREGS, // Set registers

    TR_READMEM, // Read memory
    TR_WRITEMEM, // Write to memory

    TR_SINGLESTEP, // Take single step
    TR_SYSCALL, // Generic syscall
    TR_CONT, // CONT
    TR_DETACH, // Detach from syscall
};

#define TRACE_SIGNAL_CONTINUE 0
#define TRACE_SIGNAL_SUPPRESS 1

#define TRACE_SYSCALL_ENTRY (1 << 16)
#define TRACE_SYSCALL_EXIT (2 << 16)
#define TRACE_SIGNAL (3 << 16)
#define TRACE_NEW_TRACEE (4 << 16)
#define TRACE_TRAP (5 << 16)

#ifdef __kernel__

enum trace_state {
    TRACE_RUNNING,

    TRACE_SYSCALL,
    TRACE_SYSEMU,
    TRACE_SINGLESTEP,

    TRACE_SYSCALL_ENTER_STOP,
    TRACE_SYSCALL_EXIT_STOP,
    TRACE_SIGNAL_DELIVERY_STOP,
    TRACE_TRAPPED,
};

void trace_syscall_entry(struct thread *tracee, int syscall);
void trace_syscall_exit(struct thread *tracee, int syscall);
int trace_signal_delivery(int signal, sighandler_t);
void trace_report_trap(int interrupt);

#endif

#endif
