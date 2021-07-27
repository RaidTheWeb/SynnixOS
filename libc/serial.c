#include <serial.h>
#include <syscall.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int computb(int port, char b) {
    serial_write(COM1, b);
    return 0;
}

int computs(int port, const char* buffer, size_t len) {
    for(size_t i = 0; i < len; i++) computb(port, buffer[i]);
    return 0;
}

char comgetb(int port) {
    return (char)serial_read(port);
}