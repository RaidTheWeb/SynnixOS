#pragma once
#ifndef _SYNNIXOS_H_
#define _SYNNIXOS_H_

#include <basic.h>
#include <snx/cpu.h>
#include <snx/syscall_consts.h>
#include <stdnoreturn.h>
#include <sys/types.h>
#include <syscall_types.h>

/** @file
 * @brief SynnixOS native Library
 * 
 */

extern const char *syscall_names[];

noreturn int haltvm(int exit_code);
long xtime();
pid_t create(const char *executable);
int procstate(pid_t destination, enum procstate flags);
int fault(enum fault_type type);

#if X86_64

void print_registers(interrupt_frame *);

#endif

int syscall_trace(pid_t pid, int state);
int top(int show_threads);
int load_module(int fd);
int sleepms(int milliseconds);
int totalmem();
int freemem();
int leakedmem();

int shutdown();

void redirect_output_to(char *const argv[]);

#endif
