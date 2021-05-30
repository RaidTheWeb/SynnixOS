#include <ctype.h>
#include <stdio.h>

static char dump_byte_char(char c) {
    return isprint(c) ? c : '.';
}

static void print_byte_char_line(char *c) {
    for (int i = 0; i < 16; i++) { printf("%c", dump_byte_char(c[i])); }
}

static int hexdump(size_t len, char ptr[len], size_t base_addr) {
    char *p = ptr;
    char *line = ptr;

    for (int i = 0; i < len; i++) {
        if (i % 16 == 0) printf("%08lx: ", base_addr + i);
        printf("%02hhx ", p[i]);
        if (i % 16 == 7) printf(" ");
        if (i % 16 == 15) {
            printf("   ");
            print_byte_char_line(line);
            line = p + i + 1;
        }
    }
    return 0;
}


int main(int argc, char **argv) {
    ssize_t n = 0;
    size_t offset = 0;
    char buffer[16] = {0};
    setvbuf(stdin, NULL, _IOFBF, 0);
    while ((n = fread(buffer, 1, 16, stdin)) > 0) {
        hexdump(n, buffer, offset);
        offset += n;
        printf("\n");
    }
}
