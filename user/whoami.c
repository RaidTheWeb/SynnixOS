#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char* user = getenv("USER");
    printf("%s\n", user);
    return 0;
}