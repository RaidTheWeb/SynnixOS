#include <basic.h>
#include <errno.h>
#include <snx/string.h>
#include <snx/syscall.h>
#include <sys/utsname.h>
#include <snx/fs.h>

/** @file
 * @brief Uname helpers 
 * 
 */

#if X86_64
#define UNAME_ARCH "x86_64"
#endif

#ifndef SYNNIXOS_VERSION
#define SYNNIXOS_VERSION "Null"
#endif

extern 

char* getHostname() {
    // pretty happy with this, maybe might add some improvements...? - @RaidTheWeb
    struct file *file = fs_path("/etc/hostname");
    struct membuf_file *membuf_file = (struct membuf_file*)file;
    char* buffer = membuf_file->memory;
    return buffer;
}

sysret sys_uname(struct utsname *n) {
    if (!n) return -EINVAL;
    memset(n, 0, sizeof(struct utsname));
    strcpy((char*)&n->sysname, "SynnixOS");
    strcpy((char*)&n->nodename, getHostname());
    strcpy((char*)&n->release, SYNNIXOS_VERSION);
    strcpy((char*)&n->version, SYNNIXOS_VERSION);
    strcpy((char*)&n->machine, UNAME_ARCH);
    return 0;
}
