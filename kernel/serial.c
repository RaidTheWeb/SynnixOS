#include <basic.h>
#include <stdio.h>
#include <snx/syscall.h>

#if X86
#include <x86/uart.h>
#else
#error "unimplementled"
#endif // X86

void serial_init() {
    x86_uart_init();
}

// Serial COM1

void serial_write(const char c) {
    x86_uart_write_byte(COM1, c);
}

void serial_write_str(const char *buf, size_t len) {
    x86_uart_write(COM1, buf, len);
}

char serial_read(const char c) {
    return x86_uart_read_byte(COM1);
}

// Serial COM2

void serial2_write(const char c) {
    x86_uart_write_byte(COM2, c);
}

void serial2_write_str(const char *buf, size_t len) {
    x86_uart_write(COM2, buf, len);
}

char serial2_read(const char c) {
    return x86_uart_read_byte(COM2);
}

// Serial COM3

void serial3_write(const char c) {
    x86_uart_write_byte(COM3, c);
}

void serial3_write_str(const char *buf, size_t len) {
    x86_uart_write(COM3, buf, len);
}

char serial3_read(const char c) {
    return x86_uart_read_byte(COM3);
}

// Serial COM4

void serial4_write(const char c) {
    x86_uart_write_byte(COM4, c);
}

void serial4_write_str(const char *buf, size_t len) {
    x86_uart_write(COM4, buf, len);
}

char serial4_read(const char c) {
    return x86_uart_read_byte(COM4);
}

sysret sys_serial_write(int com, int b) {
    switch(com) {
        case COM1:
            serial_write((char)b);
            break;
        case COM2:
            serial2_write((char)b);
            break;
        case COM3:
            serial3_write((char)b);
            break;
        case COM4:
        default:
            serial4_write((char)b);
            break;
    }
    return 0;
}

sysret sys_serial_read(int com) {
    switch(com) {
        case COM1:
            return serial_read('e');
            break;
        case COM2:
            return serial2_read('e');
            break;
        case COM3:
            return serial3_read('e');
            break;
        case COM4:
        default:
            return serial4_read('e');
            break;
    }
}