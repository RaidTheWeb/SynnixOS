#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc == 1) {
        printf("usage: %s [name]\n", argv[0]);
        return 0;
    }

    char* result = getenv(argv[1]);
    if(result == NULL) {
        fprintf(stderr, "enviroment value does not exist\n");
        return 1;
    }

    printf("%s=%s\n", argv[1], result);
    return 0;
}