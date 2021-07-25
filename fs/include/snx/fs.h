#pragma once
#ifndef SNX_FS_H
#define SNX_FS_H

#include <basic.h>
#include <dirent.h>
#include <list.h>
#include <snx/dmgr.h>
#include <snx/ringbuf.h>
#include <snx/sync.h>
#include <snx/syscall.h>
#include <snx/syscall_consts.h>
#include <snx/tty.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

/** @file
 * @brief Virtual File System headers 
 * 
 */

/**
 * @brief File struct
 * 
 */
struct file;

/**
 * @brief Struct representing an opened file
 * 
 */
struct open_file;

/**
 * @brief Directory struct
 * 
 */
struct directory_file;

/**
 * @brief Thread struct
 * 
 */
struct thread;

/**
 * @brief File flags
 * 
 */
enum file_flags {
    FILE_NONBLOCKING = 0x01,
};

/**
 * @brief Various file operations
 * 
 */
struct file_ops {
    void (*open)(struct open_file *, const char *name);
    void (*close)(struct open_file *);
    void (*destroy)(struct file *);
    ssize_t (*read)(struct open_file *, void *, size_t);
    ssize_t (*write)(struct open_file *, const void *, size_t);
    off_t (*seek)(struct open_file *, off_t, int whence);
    ssize_t (*readdir)(struct open_file *, struct snx_dirent *, size_t);
    void (*clone)(struct open_file *parent, struct open_file *child);
    struct file *(*child)(struct file *, const char *name);
};

/**
 * @brief File struct
 * 
 */
struct file {
    enum file_type type;
    enum file_flags flags;
    enum file_mode mode;

    atomic_int refcnt;
    int signal_eof;
    int uid;
    int gid;
    off_t len;
    struct file_ops *ops;

    struct wq readq;
    struct wq writeq;
};

/**
 * @brief Struct representing an opened file
 * 
 */
struct open_file {
    struct file *file;
    enum file_mode mode;
    off_t off;

    // only used in procfs for now
    char *buffer;
    off_t buffer_size;   // total size
    off_t buffer_length; // in use
};

/**
 * @brief Poll file descripor
 * 
 */
struct pollfd {
    int fd;
    short events;
    short revents;
};

/**
 * @brief Polling types
 * 
 */
enum poll_type {
    POLLIN,
};

/**
 * @brief Directory struct
 * 
 */
extern struct directory_file *fs_root_node;

/**
 * @brief Initialize Virtual File System
 * 
 */
void vfs_init();
//void mount(struct file *n, char *path);

/**
 * @brief Put a file into a directory (can also be a directory)
 * 
 * @param child 
 * @param directory 
 */
void put_file_in_dir(struct file *child, struct file *directory);

/**
 * @brief Clone an open file
 * 
 * @param ofd 
 * @return struct open_file* 
 */
struct open_file *clone_open_file(struct open_file *ofd);

/**
 * @brief Resolve a relative path
 * 
 * @param root 
 * @param filename 
 * @return struct file* 
 */
struct file *fs_resolve_relative_path(struct file *root, const char *filename);


/**
 * @brief Resolve directory
 * 
 * @param root 
 * @param filename 
 * @return struct file* 
 */
struct file *fs_resolve_directory_of(struct file *root, const char *filename);

/**
 * @brief Get file
 * 
 * @param filename 
 * @return struct file* 
 */
struct file *fs_path(const char *filename);
// void vfs_print_tree(struct file *root, int indent);

/**
 * @brief Delete a file and free all resources
 * 
 */
void destroy_file(struct file *);

/**
 * @brief Close an open file
 * 
 * @return sysret 
 */
sysret do_close_open_file(struct open_file *);

/**
 * @brief Get file basename
 * 
 * @param path 
 * @return const char* 
 */
const char *basename(const char *path);

/**
 * @brief Open a file
 * 
 * @param basename 
 * @param flags 
 * @param mode 
 * @return sysret 
 */
sysret do_open(struct file *, const char *basename, int flags, int mode);

/**
 * @brief Directory struct
 * 
 */
struct directory_file {
    struct file file;
    list entries;
};

/**
 * @brief Node struct in directory
 * 
 */
struct directory_node {
    struct file *file;
    const char *name;
    list siblings;
};

/**
 * @brief File operations
 * 
 */
extern struct file_ops directory_ops;

/**
 * @brief Read directory
 * 
 * @param ofd 
 * @param buf 
 * @param count 
 * @return ssize_t 
 */
ssize_t directory_readdir(struct open_file *ofd, struct snx_dirent *buf,
                          size_t count);

/**
 * @brief Create a directory
 * 
 * @param directory 
 * @param name 
 * @return struct file* 
 */
struct file *make_directory(struct file *directory, const char *name);

/**
 * @brief Replace a directory
 * 
 * @param directory 
 * @param new 
 * @param name 
 * @return struct file* 
 */
struct file *make_directory_inplace(struct file *directory, struct file *new,
                                    const char *name);

/**
 * @brief Initialize file system root
 * 
 * @return struct file* 
 */
struct file *fs_root_init(void);

/**
 * @brief Add file to directory
 * 
 * @param directory 
 * @param file 
 * @param name 
 * @return sysret 
 */
sysret add_dir_file(struct file *directory, struct file *file,
                    const char *name);

/**
 * @brief Remove file from directory
 * 
 * @param directory 
 * @param name 
 * @return struct file* 
 */
struct file *remove_dir_file(struct file *directory, const char *name);

/**
 * @brief Get directory child
 * 
 * @param directory 
 * @param name 
 * @return struct file* 
 */
struct file *directory_child(struct file *directory, const char *name);

/**
 * @brief Delete a directory and all associated resources
 * 
 * @param directory 
 */
void directory_destroy(struct file *directory);

/**
 * @brief Create a PROC directory
 * 
 * @param directory 
 * @return struct file* 
 */
struct file *make_procdir(struct file *directory);


/**
 * @brief Memory buffer file struct
 * 
 */
struct membuf_file {
    struct file file;
    void *memory;
    off_t capacity;
};

/**
 * @brief Create a file object
 * 
 * @param directory 
 * @param name 
 * @param mode 
 * @return struct file* 
 */
struct file *create_file(struct file *directory, const char *name, int mode);

/**
 * @brief Make tar file
 * 
 * @param filename 
 * @param perm 
 * @param len 
 * @param data 
 * @return struct file* 
 */
struct file *make_tar_file(const char *filename, int perm, size_t len,
                           void *data);

/**
 * @brief TTY file struct
 * 
 */
struct tty_file {
    struct file file;
    struct tty tty;
};

/**
 * @brief Write serial COM
 * 
 * @param n 
 * @param data_ 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_serial_write(struct open_file *n, const void *data_, size_t len);

/**
 * @brief Read serial COM
 * 
 * @param n 
 * @param data_ 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_serial_read(struct open_file *n, void *data_, size_t len);


/**
 * @brief Make procfile
 * 
 * @param name 
 * @param generate 
 * @param argument 
 */
void make_procfile(const char *name,
                   void (*generate)(struct open_file *ofd, void *arg),
                   void *argument);

/**
 * @brief But data into proc file
 * 
 * @param ofd 
 * @param format 
 * @param ... 
 */
void proc_sprintf(struct open_file *ofd, const char *format, ...);

/**
 * @brief UNIX-like Socket struct
 * 
 */
struct socket_file {
    struct file file;
    struct socket_ops *ops;
    enum socket_mode mode;
    enum socket_domain domain;
    enum socket_type type;
    enum socket_protocol protocol;
};

/**
 * @brief UNIX-like socket operations
 * 
 */
struct socket_ops {
    struct socket_file *(*alloc)(void);
    void (*init)(struct socket_file *);
    int (*bind)(struct socket_file *, const struct sockaddr *, socklen_t);
    ssize_t (*recv)(struct open_file *, void *, size_t, int flags);
    ssize_t (*send)(struct open_file *, const void *, size_t, int flags);
    ssize_t (*recvfrom)(struct open_file *, void *, size_t, int flags,
                        struct sockaddr *, socklen_t *);
    ssize_t (*sendto)(struct open_file *, const void *, size_t, int flags,
                      const struct sockaddr *, socklen_t);
    int (*listen)(struct open_file *, int backlog);
    int (*accept)(struct open_file *, struct sockaddr *, socklen_t *);
    int (*connect)(struct open_file *, const struct sockaddr *, socklen_t);
    void (*close)(struct open_file *);
};

/**
 * @brief /dev/zero read
 * 
 * @param n 
 * @param data 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_zero_read(struct open_file *n, void *data, size_t len);

/**
 * @brief /dev/null read (read nothing)
 * 
 * @param n 
 * @param data 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_null_read(struct open_file *n, void *data, size_t len);

/**
 * @brief /dev/null write (destroy input data)
 * 
 * @param n 
 * @param data 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_null_write(struct open_file *n, const void *data, size_t len);

/**
 * @brief /dev/inc read
 * 
 * @param n 
 * @param data_ 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_inc_read(struct open_file *n, void *data_, size_t len);

/**
 * @brief /dev/rtw read
 * 
 * @param n 
 * @param data 
 * @param len 
 * @return ssize_t 
 */
ssize_t dev_rtw_read(struct open_file *n, void *data, size_t len);

#endif // SNX_FS_H
