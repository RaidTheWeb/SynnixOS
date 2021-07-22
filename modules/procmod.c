#include <basic.h>
#include <snx/fs.h>
#include <snx/mod.h>
#include <stdio.h>
#include <stdlib.h>

void module_procfile(struct open_file *ofd, void *_) {
    proc_sprintf(ofd, "Hello there :)\n");
}

int modinit(struct mod *_) {
    make_procfile("mod", module_procfile, NULL);
    return MODINIT_SUCCESS;
}

struct modinfo modinfo = {
    .name = "procmod",
    .init = modinit,
};
