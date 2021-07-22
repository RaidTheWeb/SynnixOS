.PHONY: all clean
.SUFFIXES:

all: synnixos.iso

MP_INFO = $(info $(1))
MKISO ?= grub-mkrescue
PARALLEL ?= $(shell nproc)
SYNNIXOS_VERSION ?= $(shell cat version)
export SYNNIXOS_VERSION

include build.mk

clean: build.mk mp_clean
	rm -rf dep/*
	rm -rf sysroot
	rm -f init.tar
	rm -f snxk.elf
	rm -f synnixos.iso

AUTOGENERATED := \
	kernel/include/snx/autogenerated_syscall_consts \
	kernel/include/snx/autogenerated_syscalls.h \
	kernel/autogenerated_syscalls.inc  \
	libc/include/autogenerated_syscall_names.inc \
	libc/include/autogenerated_syscalls.h \
	libc/autogenerated_syscalls.inc \

help:
	@echo "Build tools for SynnixOS"
	@echo "Help:"
	@echo ""
	@echo "all				build all"
	@echo "build.mk			generate makefile for building"
	@echo "sysroot				create sysroot and migrate executables and header files"
	@echo "init.tar			build initfs"
	@echo "synnixos.iso			build ISO file"

sysroot: $(shell find . -name '*.h') $(shell find user -not -name '*.c')
	./scripts/install_headers.bash

build.mk: scripts/magpie_build.rb scripts/generate_makefile.rb
	./scripts/generate_makefile.rb

$(AUTOGENERATED): SYSCALLS ERRNOS
	./scripts/generate_syscalls.rb

init.tar: sysroot $(MP_ALL_INSTALL_TARGETS) $(shell find sysroot)
	$(call MP_INFO,TAR	$@)
	@cd sysroot; tar --sort=name -cf ../$@ *

synnixos.iso: sysroot init.tar snxk.elf kernel/grub.cfg
	$(call MP_INFO,ISO	$@)
	@mkdir -p isodir/boot/grub
	@cp kernel/grub.cfg isodir/boot/grub
	@cp snxk.elf isodir/boot/snxk
	@cp init.tar isodir/boot/initfs
	@$(MKISO) -o $@ isodir/
	@rm -rf isodir
