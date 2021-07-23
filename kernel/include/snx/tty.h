#pragma once
#ifndef SNX_TTY_H
#define SNX_TTY_H

#include <basic.h>
#include <snx/fs.h>
#include <stdlib.h>
#include <sys/ttyctl.h>

/** @file 
 * @brief Terminal interface helpers
 * 
 */

/**
 * @brief Base TTY struct
 * 
 */
struct tty {
    int initialized;
    int push_threshold;
    int buffer_index;
    pid_t controlling_pgrp;

    void (*print_fn)(const char *data, size_t len);

    char buffer[1024];

    int buffer_mode;
    int echo;

    struct ringbuf ring;
};

/**
 * @brief TTY File for serial COM1
 * 
 */
extern struct tty_file dev_serial;

/**
 * @brief TTY File for serial COM2
 * 
 */
extern struct tty_file dev_serial2;

/**
 * @brief Write character to serial based TTY
 * 
 * @param tty_file 
 * @param c 
 * @return int 
 */
int write_to_serial_tty(struct tty_file *tty_file, char c);

#endif
