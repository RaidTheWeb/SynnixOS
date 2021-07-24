#pragma once
#ifndef _SETJMP_H_
#define _SETJMP_H_

#include <basic.h>
#include <stdnoreturn.h>

/** @file
 * @brief Jumping 
 * 
 */

#if X86_64
/**
 * @brief Jump buffer
 * 
 */
union __jmp_buf {
    struct {
        unsigned long rbx;
        unsigned long bp;
        unsigned long r12;
        unsigned long r13;
        unsigned long r14;
        unsigned long r15;
        unsigned long sp;
        unsigned long ip;
    } __regs;
    unsigned long __array[8];
};
#endif

/**
 * @brief Typedef jump buffer
 * 
 */
typedef union __jmp_buf jmp_buf[1];

__RETURNS_TWICE
int _setjmp(jmp_buf);

__RETURNS_TWICE
/**
 * @brief Set jump buffer
 * 
 * @return int 
 */
int setjmp(jmp_buf);

/**
 * @brief Long jump
 * 
 * @return noreturn 
 */
noreturn void longjmp(jmp_buf, int);

/**
 * @brief Long jump
 * 
 * @return noreturn 
 */
noreturn void _longjmp(jmp_buf, int);

#endif // _SETJMP_H_
