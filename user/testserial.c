#include <serial.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char**argv) {
    char *chr = comgetse(COM1);
    printf("\nGot String: %s\n", chr);
    free(chr);
    return 0;
}