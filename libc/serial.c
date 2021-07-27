#include <serial.h>
#include <syscall.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

char* comgets(int port) {
    char *buffer = NULL, *tmp = NULL;
    size_t in = 0, size = 0;
    char ch = -1;
    while(ch) {
        ch = comgetb(port);
        if(ch == '\r' || ch == '\n')
            ch = 0;

        if (size <= in) {
            size += 2;
            tmp = realloc(buffer, size);
            if(!tmp) {
                free(buffer);
                buffer = NULL;
                break;
            }
            buffer = tmp;
        }

        buffer[in++] = ch;
    }
    return buffer;
}

char* comgetse(int port) {
    char *buffer = NULL, *tmp = NULL;
    size_t in = 0, size = 0;
    char ch = -1;
    while(ch) {
        ch = comgetb(port);
        if(ch == '\r' || ch == '\n')
            ch = 0;

        if (size <= in) {
            size += 2;
            tmp = realloc(buffer, size);
            if(!tmp) {
                free(buffer);
                buffer = NULL;
                break;
            }
            buffer = tmp;
        }
        putc(ch, stdout);
        buffer[in++] = ch;
    }
    return buffer;
}