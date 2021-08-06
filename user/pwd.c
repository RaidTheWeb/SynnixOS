#include <unistd.h>
#include <stdio.h>

int main(int argc, const char** argv) {
    char cwdbuffer[256];
    getcwd(cwdbuffer, 256);
    printf("%s\n", cwdbuffer);
    return 0;
}