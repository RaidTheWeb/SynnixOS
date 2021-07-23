#pragma once
#ifndef SNX_TIMER_H
#define SNX_TIMER_H

#include <basic.h>
#include <snx/cpu.h>

/** @file
 * @brief Kernel-Space PIT-based timer 
 * 
 */

/**
 * @brief Timer Event struct
 * 
 */
struct timer_event;

/**
 * @brief Convert seconds into ticks (HZ)
 * 
 * @param s 
 * @return int 
 */
int seconds(int s);

/**
 * @brief Convert milliseconds into ticks (HZ)
 * 
 * @param ms 
 * @return int 
 */
int milliseconds(int ms);

/**
 * @brief Enable periodic timer at `hz` Hertz
 * 
 * @param hz 
 */
void timer_enable_periodic(int hz);

/**
 * @brief Initialize timer
 * 
 */
void init_timer(void);

/**
 * @brief Create timer event
 * 
 * @param delta_t 
 * @param fn 
 * @param fn_name 
 * @param extra_data 
 * @return struct timer_event* 
 */
struct timer_event *insert_timer_event(uint64_t delta_t, void (*fn)(void *),
                                       const char *fn_name, void *extra_data);

/**
 * @brief Delete a timer event
 * 
 */
void drop_timer_event(struct timer_event *);

/**
 * @brief Timer handler interrupt
 * 
 */
void timer_handler(interrupt_frame *, void *);

/**
 * @brief Insert a timer event (shorthand)
 * 
 */
#define insert_timer_event(delta_t, fn, data)                                  \
    insert_timer_event(delta_t, fn, __func__, data)

#ifdef __kernel__

extern uint64_t kernel_timer;

#endif // __kernel__

#endif
