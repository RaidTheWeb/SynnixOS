#pragma once
#ifndef SNX_X86_PIT_H
#define SNX_X86_PIT_H

#include <basic.h>

extern bool ignore_timer_interrupt;

int pit_create_periodic(int hz);
int pit_create_oneshot(int nanoseconds);
int pit_ignore(void);

#endif
