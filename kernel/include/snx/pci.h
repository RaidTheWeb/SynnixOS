
#pragma once
#ifndef SNX_PCI_H
#define SNX_PCI_H

#include <basic.h>

/** @file
 * @brief PCI Support
 * 
 */

#define PCI_1 0x00
#define PCI_2 0x01
#define PCI_3 0x02

typedef uint32_t pci_address_t;

pci_address_t pci_pack_addr(int bus, int slot, int func, int offset);
void pci_print_addr(pci_address_t);

uint32_t pci_config_read(pci_address_t);
void pci_config_write(pci_address_t, uint32_t value);
void pci_print_device_info(pci_address_t);
pci_address_t pci_find_device_by_id(uint16_t vendor, uint16_t device);
void pci_device_callback(uint16_t vendor, uint16_t device,
                         void (*)(pci_address_t));

void pci_enumerate_bus_and_print();

const char *pci_device_type(unsigned char class, unsigned char subclass,
                            unsigned char prog_if);

#endif
