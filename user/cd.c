#include <unistd.h>

int main(int argc, const char** argv) {
    if(argc != 1)
        chdir(argv[1]);
    else {
        char cwd[256];
        getcwd(cwd, 256);
        chdir(cwd);
    }
    return 0;
}