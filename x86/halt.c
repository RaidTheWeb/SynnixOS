#include <basic.h>
#include <snx/cpu.h>
#include <x86/interrupt.h>

noreturn void halt() {
    while (true) {
        disable_irqs();
        asm volatile("hlt");
    }
}
