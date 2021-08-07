CC = ~/.local/bin/x86_64-synnixos-gcc
CFLAGS = -static -O0 -std=c11 -Wl,--allow-multiple-definition
SYSUSR ?= ~/SynnixOS/sysroot/usr/bin/

all: ape

.PHONY: ape

ape: ape.c api/ape.c
	$(CC) $(CFLAGS) -Iapi -o $@ ape.c api/ape.c -lm
	cp ape $(SYSUSR)

clean:
	rm -f ape *.o *.dSYM