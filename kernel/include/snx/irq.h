#pragma once
#ifndef SNX_IRQ_H
#define SNX_IRQ_H

#include <basic.h>
#include <list.h>
#include <snx/cpu.h>

/** @file
 * @brief Interrupt definitions 
 * 
 */

/**
 * @brief Define interrupt handler struct
 * 
 */
struct irq_handler {
    list_n node;
    void (*handler_func)(interrupt_frame *, void *);
    void *impl;
};

/**
 * @brief Install an `irq`
 * 
 * @param irq 
 * @param fn 
 */
void irq_install(int irq, void (*fn)(interrupt_frame *, void *), void *);
/**
 * @brief Handler for an interrupt frame
 * 
 */
void irq_handler(interrupt_frame *);

#endif
