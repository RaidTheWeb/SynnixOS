#include <basic.h>
#include <errno.h>
#include <snx/string.h>
#include <snx/syscall.h>
#include <sys/utsname.h>

#if X86_64
#define UNAME_ARCH "x86_64"
#endif

sysret sys_uname(struct utsname *n) {
    if (!n) return -EINVAL;
    memset(n, 0, sizeof(struct utsname));
    strcpy((char *)&n->sysname, "synnixos");
    strcpy((char *)&n->nodename, "snx");
    strcpy((char *)&n->release, SYNNIXOS_VERSION);
    strcpy((char *)&n->version, "v");
    strcpy((char *)&n->machine, UNAME_ARCH);
    return 0;
}
