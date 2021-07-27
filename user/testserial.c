#include <serial.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char**argv) {
    char *chr = comgets(COM1);
    printf("Got String: %s", chr);
    free(chr);
    return 0;
}