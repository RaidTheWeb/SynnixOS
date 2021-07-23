#include <basic.h>
#include <elf.h>
#include <snx/fs.h>
#include <snx/multiboot.h>
#include <snx/multiboot2.h>
#include <snx/panic.h>
#include <snx/pci.h>
#include <snx/pmm.h>
#include <snx/serial.h>
#include <snx/tarfs.h>
#include <snx/tests.h>
#include <snx/thread.h>
#include <snx/timer.h>
#include <snx/vmm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <x86/cpu.h>
#include <x86/pic.h>

struct tar_header *initfs;

void mb_pm_callback(phys_addr_t mem, size_t len, int type) {
    int pm_type;
    if (type == MULTIBOOT_MEMORY_AVAILABLE) {
        pm_type = PM_REF_ZERO;
    } else {
        pm_type = PM_LEAK;
    }
    pm_set(mem, mem + len, pm_type);
}

void proc_test(struct open_file *ofd, void *_) {
    proc_sprintf(ofd, "Hello World\n");
}

void procfs_init() {
    extern void timer_procfile(struct open_file *, void *);
    extern void proc_syscalls(struct open_file *, void *);
    extern void proc_mods(struct open_file *, void *);
    make_procfile("test", proc_test, NULL);
    make_procfile("timer", timer_procfile, NULL);
    make_procfile("mem", pm_summary, NULL);
    make_procfile("syscalls", proc_syscalls, NULL);
    make_procfile("mods", proc_mods, NULL);
}

extern char _kernel_phy_base;
extern char _kernel_phy_top;

const char *banner =
    "\n"
    "********************************\n"
    "\n"
    "           SynnixOS             \n"
    "Version: " SYNNIXOS_VERSION  "\n"
    "\n"
    "********************************\n"
    "\n";

noreturn void kernel_main(uint32_t mb_magic, uintptr_t mb_info) {
    long tsc = rdtsc();

    phys_addr_t kernel_base = (phys_addr_t)&_kernel_phy_base;
    phys_addr_t kernel_top = (phys_addr_t)&_kernel_phy_top;
    assert(kernel_top < 0x200000); // update boot.asm page mappings

    heap_init(global_heap, early_malloc_pool, EARLY_MALLOC_POOL_LEN);

    vmm_early_init();
    install_isrs();
    pic_init();

    pic_irq_unmask(0); // Timer
    pic_irq_unmask(4); // Serial
    pic_irq_unmask(3); // Serial COM2

    serial_init();

    if (mb_magic != MULTIBOOT2_BOOTLOADER_MAGIC)
        panic("Bootloader does not appear to be multiboot2.");
    mb_init(mb_info);
    mb_mmap_print();
    mb_mmap_enumerate(mb_pm_callback);

    pm_set(0, 0x1000, PM_LEAK);
    pm_set(kernel_base, kernel_top, PM_LEAK);

    printf("kernel: %10zx - %10zx\n", kernel_base, kernel_top);

    size_t memory = mb_mmap_total_usable();
    size_t megabytes = memory / MB;
    size_t kilobytes = (memory - (megabytes * MB)) / KB;
    printf("mmap: total usable memory:");
    printf("%zu (%zuMB + %zuKB)\n", memory, megabytes, kilobytes);
    printf("mb: kernel command line '%s'\n", mb_cmdline());
    printf("mb: bootloader is '%s'\n", mb_bootloader());

    struct initfs_info initfs_info = mb_initfs_info();
    initfs = (struct tar_header *)(initfs_info.base + VMM_KERNEL_BASE);
    printf("mb: user init at %#zx - %#zx\n", initfs, initfs_info.top);
    pm_set(initfs_info.base, initfs_info.top, PM_LEAK);

    // FIXME: the elf metadata ends up here, outside of the end of the
    // file for some reason.
    pm_set(kernel_top, initfs_info.base, PM_LEAK);

    size_t initfs_len = initfs_info.top - initfs_info.base;
    uintptr_t initfs_v = initfs_info.base + VMM_KERNEL_BASE;
    uintptr_t initfs_p = initfs_info.base;

    vmm_unmap_range(initfs_v, initfs_len);
    vmm_map_range(initfs_v, initfs_p, initfs_len, 0); // init is read-only

    

    init_timer();
    vfs_init(initfs_info.top - initfs_info.base);
    threads_init();
    load_kernel_elf(mb_elf_tag());
    pci_enumerate_bus_and_print();
    procfs_init();
    run_all_tests((rdtsc() - tsc));
    bootstrap_usermode("/bin/init");

    printf(banner);
    timer_enable_periodic(HZ);

    printf("threads: usermode thread installed\n");
    printf("initialization took: %li\n", rdtsc() - tsc);
    printf("cpu: allowing irqs\n");
    enable_irqs();

    while (true) asm volatile("hlt");
    panic("kernel_main tried to return!");
}
