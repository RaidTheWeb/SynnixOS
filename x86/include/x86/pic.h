#pragma once
#ifndef SNX_X86_PIC_H
#define SNX_X86_PIC_H

#include <basic.h>

/** @file
 * @brief x86 PIC header files
 * 
 */

/**
 * @brief PIC interrupts
 * 
 */
enum pic_interrupt {
    IRQ_TIMER = 0,
    IRQ_KEYBOARD = 1,
    IRQ_SERIAL2 = 3,
    IRQ_SERIAL1 = 4,
    IRQ_LPT2 = 5,
    IRQ_FLOPPY = 6,
    IRQ_LPT1 = 7,
    IRQ_RTC = 8,
    IRQ_MOUSE = 12,
    IRQ_FPU = 13,
    IRQ_ATA1 = 14,
    IRQ_ATA2 = 15,
};

/**
 * @brief Send an IRQ
 * 
 * @param irq 
 */
void pic_send_eoi(int irq);

/**
 * @brief Initialize PIC
 * 
 */
void pic_init();

/**
 * @brief Unmask IRQ (enum)
 * 
 * @param irq 
 */
void pic_irq_unmask(int irq);

/**
 * @brief Mask an IRQ (enum)
 * 
 * @param irq 
 */
void pic_irq_mask(int irq);

#endif
