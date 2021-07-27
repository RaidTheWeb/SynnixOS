#include <serial.h>
#include <stdio.h>

int main(int argc, const char**argv) {
    char chr = comgetb(COM1);
    printf("Got Char: %c", chr);
    return 0;
}