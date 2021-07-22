#pragma once
#ifndef SNX_IRQ_H
#define SNX_IRQ_H

#include <basic.h>
#include <list.h>
#include <snx/cpu.h>

struct irq_handler {
    list_n node;
    void (*handler_func)(interrupt_frame *, void *);
    void *impl;
};

void irq_install(int irq, void (*fn)(interrupt_frame *, void *), void *);
void irq_handler(interrupt_frame *);

#endif
