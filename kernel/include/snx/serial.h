#pragma once
#ifndef SNX_SERIAL_H
#define SNX_SERIAL_H

#include <basic.h>

void serial_init(void);
void serial_write(const char c);
void serial_write_str(const char *buf, size_t len);
char serial_read(void);
void serial2_write(const char c);
void serial2_write_str(const char *buf, size_t len);
char serial2_read(void);

#endif
