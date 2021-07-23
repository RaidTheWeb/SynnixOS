#pragma once
#ifndef SNX_SIGNAL_H
#define SNX_SIGNAL_H

#include <basic.h>
#include <snx/cpu.h>
#include <snx/syscall_consts.h>
#include <signal.h>

/** @file
 * @brief Helpers around threading and signals 
 * 
 */

/**
 * @brief Thread structure
 * 
 */
struct thread;

extern const unsigned char signal_handler_return[];

/**
 * @brief Context structure for signals
 * 
 */
struct signal_context {
    int state;
    void *sp;
    void *bp;
    char *stack;
    uintptr_t ip;
};

/**
 * @brief Simulate a signal trip to a Process via PID
 * 
 * @param pid 
 * @param signal 
 * @return int 
 */
int signal_send(pid_t pid, int signal);

/**
 * @brief Simulate a signal trip to a Process Group via PGID
 * 
 * @param pgid 
 * @param signal 
 * @return int 
 */
int signal_send_pgid(pid_t pgid, int signal);

/**
 * @brief Simulate a signal trip to a thread via struct
 * 
 * @param th 
 * @param signal 
 * @return int 
 */
int signal_send_th(struct thread *th, int signal);

/**
 * @brief Cause a signal in current process/thread/process group
 * 
 * @param signal 
 */
void signal_self(int signal);

/**
 * @brief Handle incoming queued signals
 * 
 * @return int 
 */
int handle_pending_signals(void);

/**
 * @brief Handle a signal via a singal handler
 * 
 * @param signal 
 */
void handle_signal(int signal, sighandler_t);

/**
 * @brief Call a signal
 * 
 * @param signal 
 */
void do_signal_call(int signal, sighandler_t);

#endif
