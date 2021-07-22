#pragma once
#ifndef SNX_SYSCALL_H
#define SNX_SYSCALL_H

#include <basic.h>
#include <snx/cpu.h>
#include <snx/string.h>
#include <snx/syscall_consts.h>
#include <stddef.h>
#include <stdint.h>

#define SYSCALL_TABLE_SIZE 128

typedef intptr_t sysret;

void syscall_entry(int);
void syscall_exit(int);

int syscall_register(int num, const char *name, sysret (*)(), const char *debug,
                     unsigned ptr_mask);

sysret do_syscall(interrupt_frame *);

#endif
