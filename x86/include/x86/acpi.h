#pragma once
#ifndef SNX_X86_ACPI_H
#define SN_X86_ACPI_H

#include <basic.h>

#define RSDP_SIGNATURE "RSD PTR "
#define RSDT_SIGNATURE "RSDT"
#define FADT_SIGNATURE "FACP"
#define SSDT_SIGNATURE "SSDT"
#define MADT_SIGNATURE "APIC"

/** @file
 * @brief ACPI support headers 
 * 
 */

/**
 * @brief Convenience enumeration
 * 
 */
enum {
    RSDT,
    FADT,
    SSDT,
    MADT,
};

/**
 * @brief ACPI RDDP type struct
 * 
 */
typedef struct __PACKED acpi_rsdp {
    char signature[8];
    unsigned char checksum;
    char oem_id[6];
    unsigned char revision;
    uint32_t rsdt_address;
} acpi_rsdp;

/**
 * @brief ACPI header type struct
 * 
 */
typedef struct __PACKED acpi_header {
    char signature[4];
    uint32_t length;
    unsigned char revision;
    unsigned char checksum;
    char oem_id[6];
    char oem_table_id[8];
    uint32_t oem_revision;
    uint32_t creator_id;
    uint32_t creator_revision;
} acpi_header;

/**
 * @brief ACPI RSDT type struct
 * 
 */
typedef struct __PACKED acpi_rsdt {
    acpi_header header;
    uint32_t table_ptr[];
} acpi_rsdt;

#define MADT_LAPIC_FLAG_PROCESSOR_ENABLED 1
typedef struct __PACKED acpi_madt_lapic {
    unsigned char processor_id;
    unsigned char id;
    uint32_t flags;
} acpi_madt_lapic;

typedef struct __PACKED acpi_madt_ioapic {
    unsigned char id;
    unsigned char _reserved_0;
    uint32_t address;
    uint32_t interrupt_base;
} acpi_madt_ioapic;

typedef struct __PACKED acpi_madt_iso {
    unsigned char bus_source;
    unsigned char irq_source;
    uint32_t global_system_interrupt;
    uint16_t flags;
} acpi_madt_iso;

typedef struct __PACKED acpi_madt_nmi {
    unsigned char processor_id;
    uint16_t flags;
    unsigned char LINT_number;
} acpi_madt_nmi;

typedef struct __PACKED acpi_madt_lapic_address {
    uint16_t _reserved_0;
    uint64_t address;
} acpi_madt_lapic_address;

typedef struct __PACKED acpi_madt_entry {
    unsigned char type;
    unsigned char length;
    union {
        acpi_madt_lapic lapic;
        acpi_madt_ioapic ioapic;
        acpi_madt_iso iso;
        acpi_madt_nmi nmi;
        acpi_madt_lapic_address lapic_address;
    };
} acpi_madt_entry;

#define MADT_FLAG_PIC_INSTALLED 1

#define MADT_ENTRY_LAPIC 0
#define MADT_ENTRY_IOAPIC 1
#define MADT_ENTRY_ISO 2
#define MADT_ENTRY_NMI 4
#define MADT_ENTRY_LAPIC_ADDRESS 5

typedef struct __PACKED madt {
    acpi_header header;
    uint32_t lapic_address;
    uint32_t flags;
    acpi_madt_entry entries[];
} acpi_madt;

/**
 * @brief Get the rsdt
 * 
 * @param rsdp 
 * @return acpi_rsdt* 
 */
acpi_rsdt *acpi_get_rsdt(acpi_rsdp *rsdp);
/**
 * @brief Get ACPI table ID
 * 
 * @param table_id 
 * @return void* 
 */
void *acpi_get_table(int table_id);

/**
 * @brief Print ACPI header to stdout
 * 
 * @param header 
 */
void acpi_print_header(acpi_header *header);

/**
 * @brief Print ACPI table to stdout
 * 
 * @param table 
 */
void acpi_print_table(acpi_header *table);

#endif
