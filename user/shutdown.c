#include <stdio.h>
#include <synnixos.h>

int main(int argc, const char** argv) {
    printf("Shutting down...\n");
    shutdown();
    return 0;
}