OSCC = ~/.local/bin/x86_64-synnixos-gcc
SYSUSR = ../../sysroot/usr/bin/

CFLAGS ?= -g -static -Wl,--allow-multiple-definition
CC ?= gcc

local:
	$(CC) $(CFLAGS) -o calc main.c calculator.c -lm

snx:
	$(OSCC) $(CFLAGS) -o calc main.c calculator.c -lm
	cp calc $(SYSUSR)