#include <basic.h>
#include <snx/fs.h>
#include <snx/mod.h>
#include <snx/thread.h>
#include <snx/timer.h>
#include <stdio.h>

ssize_t my_file_read(struct open_file *ofd, void *buf, size_t len) {
    for (size_t i = 0; i < len; i++) { ((char *)buf)[i] = (char)i; }
    return (ssize_t)len;
}

struct file_ops my_file_ops = {
    .read = my_file_read,
};

void file_init(struct file *f, enum file_type type, struct file_ops *ops) {
    f->type = type;
    f->ops = ops;

    f->refcnt = 1;
    wq_init(&f->readq);
    wq_init(&f->writeq);
}

struct my_file {
    struct file file;
};

void make_my_file(const char *name) {
    struct file *dev_file = fs_path("/dev");
    struct directory_file *dev = (struct directory_file *)dev_file;
    struct my_file *my_file = zmalloc(sizeof(struct my_file));

    file_init(&my_file->file, FT_CHARDEV, &my_file_ops);
    my_file->file.mode = USR_READ;
    add_dir_file(dev_file, &my_file->file, name);
}

int init(struct mod *_) {
    printf("Hello World from this kernel module!\n");
    make_my_file("modfile");
    return MODINIT_SUCCESS;
}

__USED struct modinfo modinfo = {
    .name = "file",
    .init = init,
};
