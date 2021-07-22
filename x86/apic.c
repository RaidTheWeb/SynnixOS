#include <basic.h>
#include <snx/vmm.h>
#include <x86/apic.h>
#include <x86/cpu.h>

static size_t lapic_addr;
static size_t ioapic_addr;

int enable_apic(size_t addr) {
    lapic_addr = addr;
    wrmsr(IA32_APIC_BASE, lapic_addr | APIC_ENABLE);

    vmm_map(lapic_addr, lapic_addr, PAGE_WRITEABLE); // move to some sane place

    volatile uint32_t *lapic_spiv = (volatile uint32_t *)(lapic_addr + 0xF0);
    *lapic_spiv |= 0x100; // enable bit in spurrious interrupt vector

    return 0;
}

void ioapic_write(uint8_t offset, uint32_t value) {
    // TODO: fix race condition!
    // if we get an interrupt in between these it could break shit

    *(volatile uint32_t *)(ioapic_addr) = offset;       // register select
    *(volatile uint32_t *)(ioapic_addr + 0x10) = value; // value
}

uint32_t ioapic_read(uint8_t offset) {
    // See write for the problem with this approach

    *(volatile uint32_t *)(ioapic_addr) = offset;      // register select
    return *(volatile uint32_t *)(ioapic_addr + 0x10); // value
}

void enable_ioapic(size_t addr) {}

int enable_lapic_timer(int per_second) {
    return 0;
}
