.PHONY: all clean
.SUFFIXES:

all: ngos.iso

MP_INFO = $(info $(1))
MKISO ?= grub-mkrescue
PARALLEL ?= $(shell nproc)
SYNNIXOS_VERSION ?= 0.1.0
export SYNNIXOS_VERSION

include build.mk

clean: build.mk mp_clean
	rm -rf dep/*
	rm -rf sysroot
	rm -f init.tar
	rm -f ngk.elf
	rm -f ngos.iso

AUTOGENERATED := \
	kernel/include/ng/autogenerated_syscall_consts \
	kernel/include/ng/autogenerated_syscalls.h \
	kernel/autogenerated_syscalls.inc  \
	libc/include/autogenerated_syscall_names.inc \
	libc/include/autogenerated_syscalls.h \
	libc/autogenerated_syscalls.inc \

sysroot: $(shell find . -name '*.h') $(shell find user -not -name '*.c')
	./scripts/install_headers.bash

build.mk: scripts/magpie_build.rb scripts/generate_makefile.rb
	./scripts/generate_makefile.rb

$(AUTOGENERATED): SYSCALLS ERRNOS
	./scripts/generate_syscalls.rb

init.tar: sysroot $(MP_ALL_INSTALL_TARGETS) $(shell find sysroot)
	$(call MP_INFO,TAR	$@)
	@cd sysroot; tar --sort=name -cf ../$@ *

ngos.iso: sysroot init.tar ngk.elf kernel/grub.cfg
	$(call MP_INFO,ISO	$@)
	@mkdir -p isodir/boot/grub
	@cp kernel/grub.cfg isodir/boot/grub
	@cp ngk.elf isodir/boot/ngk
	@cp init.tar isodir/boot/initfs
	@$(MKISO) -o $@ isodir/
	@rm -rf isodir
