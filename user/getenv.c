#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc < 1) {
        printf("usage: %s [name]", argv[0]);
        return 0;
    }

    printf("%s=%s\n", argv[1], getenv(argv[1]));
    return 0;
}