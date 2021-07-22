#pragma once
#ifndef SNX_SIGNAL_H
#define SNX_SIGNAL_H

#include <basic.h>
#include <snx/cpu.h>
#include <snx/syscall_consts.h>
#include <signal.h>

struct thread;

extern const unsigned char signal_handler_return[];

struct signal_context {
    int state;
    void *sp;
    void *bp;
    char *stack;
    uintptr_t ip;
};

int signal_send(pid_t pid, int signal);
int signal_send_pgid(pid_t pgid, int signal);
int signal_send_th(struct thread *th, int signal);
void signal_self(int signal);

int handle_pending_signals(void);
void handle_signal(int signal, sighandler_t);

void do_signal_call(int signal, sighandler_t);

#endif
