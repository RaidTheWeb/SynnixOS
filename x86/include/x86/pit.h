#pragma once
#ifndef SNX_X86_PIT_H
#define SNX_X86_PIT_H

#include <basic.h>

/** @file
 * @brief Programmable Interval Timer 
 * 
 */

/**
 * @brief Boolean whether to ignore timer interrupts
 * 
 */
extern bool ignore_timer_interrupt;

/**
 * @brief Create periodic timer running at HZ (Hertz)
 * 
 * @param hz 
 * @return int 
 */
int pit_create_periodic(int hz);

/**
 * @brief Create a one shot timer using nanoseconds
 * 
 * @param nanoseconds 
 * @return int 
 */
int pit_create_oneshot(int nanoseconds);

/**
 * @brief Ignore PIT
 * 
 * @return int 
 */
int pit_ignore(void);

#endif
