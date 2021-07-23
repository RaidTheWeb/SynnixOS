.PHONY: mp_all mp_clean mp_install

mp_all: $(MP_ALL_TARGETS)

build-x86_64/libc.a: build-x86_64/libc/crt0.o build-x86_64/libc/crti.o build-x86_64/libc/crtn.o build-x86_64/libc/ctype.o build-x86_64/libc/entry.o build-x86_64/libc/errno.o build-x86_64/libc/fstdio.o build-x86_64/libc/fstdio_unlocked.o build-x86_64/libc/getopt.o build-x86_64/libc/locale.o build-x86_64/libc/malloc.o build-x86_64/libc/setjmp.o build-x86_64/libc/signal.o build-x86_64/libc/stdio.o build-x86_64/libc/stdlib.o build-x86_64/libc/string.o build-x86_64/libc/strtod.o build-x86_64/libc/synnixos.o build-x86_64/libc/syscall.o build-x86_64/libc/syscalls.o build-x86_64/libc/time.o build-x86_64/libc/todo.o build-x86_64/libc/unistd.o build-x86_64/libc/vector.o build-x86_64/libc/x86_64/synnixos.o 
	$(call MP_INFO,AR	libc.a)
	@ar rcs -o build-x86_64/libc.a build-x86_64/libc/crt0.o build-x86_64/libc/crti.o build-x86_64/libc/crtn.o build-x86_64/libc/ctype.o build-x86_64/libc/entry.o build-x86_64/libc/errno.o build-x86_64/libc/fstdio.o build-x86_64/libc/fstdio_unlocked.o build-x86_64/libc/getopt.o build-x86_64/libc/locale.o build-x86_64/libc/malloc.o build-x86_64/libc/setjmp.o build-x86_64/libc/signal.o build-x86_64/libc/stdio.o build-x86_64/libc/stdlib.o build-x86_64/libc/string.o build-x86_64/libc/strtod.o build-x86_64/libc/synnixos.o build-x86_64/libc/syscall.o build-x86_64/libc/syscalls.o build-x86_64/libc/time.o build-x86_64/libc/todo.o build-x86_64/libc/unistd.o build-x86_64/libc/vector.o build-x86_64/libc/x86_64/synnixos.o
build-x86_64/libc/crt0.o: libc/crt0.S
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,AS	crt0.o)
	@gcc  -MD -MF dep/libc/crt0.d -c libc/crt0.S -o build-x86_64/libc/crt0.o
build-x86_64/libc/crti.o: libc/crti.S
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,AS	crti.o)
	@gcc  -MD -MF dep/libc/crti.d -c libc/crti.S -o build-x86_64/libc/crti.o
build-x86_64/libc/crtn.o: libc/crtn.S
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,AS	crtn.o)
	@gcc  -MD -MF dep/libc/crtn.d -c libc/crtn.S -o build-x86_64/libc/crtn.o
build-x86_64/libc/ctype.o: libc/ctype.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	ctype.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/ctype.d -c libc/ctype.c -o build-x86_64/libc/ctype.o
build-x86_64/libc/entry.o: libc/entry.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	entry.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/entry.d -c libc/entry.c -o build-x86_64/libc/entry.o
build-x86_64/libc/errno.o: libc/errno.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	errno.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/errno.d -c libc/errno.c -o build-x86_64/libc/errno.o
build-x86_64/libc/fstdio.o: libc/fstdio.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	fstdio.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/fstdio.d -c libc/fstdio.c -o build-x86_64/libc/fstdio.o
build-x86_64/libc/fstdio_unlocked.o: libc/fstdio_unlocked.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	fstdio_unlocked.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/fstdio_unlocked.d -c libc/fstdio_unlocked.c -o build-x86_64/libc/fstdio_unlocked.o
build-x86_64/libc/getopt.o: libc/getopt.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	getopt.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/getopt.d -c libc/getopt.c -o build-x86_64/libc/getopt.o
build-x86_64/libc/locale.o: libc/locale.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	locale.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/locale.d -c libc/locale.c -o build-x86_64/libc/locale.o
build-x86_64/libc/malloc.o: libc/malloc.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	malloc.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/malloc.d -c libc/malloc.c -o build-x86_64/libc/malloc.o
build-x86_64/libc/setjmp.o: libc/setjmp.S
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,AS	setjmp.o)
	@gcc  -MD -MF dep/libc/setjmp.d -c libc/setjmp.S -o build-x86_64/libc/setjmp.o
build-x86_64/libc/signal.o: libc/signal.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	signal.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/signal.d -c libc/signal.c -o build-x86_64/libc/signal.o
build-x86_64/libc/stdio.o: libc/stdio.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	stdio.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/stdio.d -c libc/stdio.c -o build-x86_64/libc/stdio.o
build-x86_64/libc/stdlib.o: libc/stdlib.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	stdlib.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/stdlib.d -c libc/stdlib.c -o build-x86_64/libc/stdlib.o
build-x86_64/libc/string.o: libc/string.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	string.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/string.d -c libc/string.c -o build-x86_64/libc/string.o
build-x86_64/libc/strtod.o: libc/strtod.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	strtod.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/strtod.d -c libc/strtod.c -o build-x86_64/libc/strtod.o
build-x86_64/libc/synnixos.o: libc/synnixos.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	synnixos.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/synnixos.d -c libc/synnixos.c -o build-x86_64/libc/synnixos.o
build-x86_64/libc/syscall.o: libc/syscall.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	syscall.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/syscall.d -c libc/syscall.c -o build-x86_64/libc/syscall.o
build-x86_64/libc/syscalls.o: libc/syscalls.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	syscalls.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/syscalls.d -c libc/syscalls.c -o build-x86_64/libc/syscalls.o
build-x86_64/libc/time.o: libc/time.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	time.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/time.d -c libc/time.c -o build-x86_64/libc/time.o
build-x86_64/libc/todo.o: libc/todo.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	todo.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/todo.d -c libc/todo.c -o build-x86_64/libc/todo.o
build-x86_64/libc/unistd.o: libc/unistd.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	unistd.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/unistd.d -c libc/unistd.c -o build-x86_64/libc/unistd.o
build-x86_64/libc/vector.o: libc/vector.c
	@mkdir -p build-x86_64/libc
	@mkdir -p dep/libc
	$(call MP_INFO,CC	vector.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/vector.d -c libc/vector.c -o build-x86_64/libc/vector.o
build-x86_64/libc/x86_64/synnixos.o: libc/x86_64/synnixos.c
	@mkdir -p build-x86_64/libc/x86_64
	@mkdir -p dep/libc/x86_64
	$(call MP_INFO,CC	synnixos.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libc/x86_64/synnixos.d -c libc/x86_64/synnixos.c -o build-x86_64/libc/x86_64/synnixos.o
build-x86_64/libm.a: build-x86_64/libm/complex.o build-x86_64/libm/double.o build-x86_64/libm/random.o 
	$(call MP_INFO,AR	libm.a)
	@ar rcs -o build-x86_64/libm.a build-x86_64/libm/complex.o build-x86_64/libm/double.o build-x86_64/libm/random.o
build-x86_64/libm/complex.o: libm/complex.c
	@mkdir -p build-x86_64/libm
	@mkdir -p dep/libm
	$(call MP_INFO,CC	complex.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libm/complex.d -c libm/complex.c -o build-x86_64/libm/complex.o
build-x86_64/libm/double.o: libm/double.c
	@mkdir -p build-x86_64/libm
	@mkdir -p dep/libm
	$(call MP_INFO,CC	double.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libm/double.d -c libm/double.c -o build-x86_64/libm/double.o
build-x86_64/libm/random.o: libm/random.c
	@mkdir -p build-x86_64/libm
	@mkdir -p dep/libm
	$(call MP_INFO,CC	random.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libm/random.d -c libm/random.c -o build-x86_64/libm/random.o
build-x86_64/libelf.a: build-x86_64/libelf/elf-snx.o 
	$(call MP_INFO,AR	libelf.a)
	@ar rcs -o build-x86_64/libelf.a build-x86_64/libelf/elf-snx.o
build-x86_64/libelf/elf-snx.o: linker/elf-snx.c
	@mkdir -p build-x86_64/libelf
	@mkdir -p dep/libelf
	$(call MP_INFO,CC	elf-snx.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -fno-builtin -MD -MF dep/libelf/elf-snx.d -c linker/elf-snx.c -o build-x86_64/libelf/elf-snx.o
build-x86_64/libc.so: build-x86_64/libc_so/crt0.o build-x86_64/libc_so/crti.o build-x86_64/libc_so/crtn.o build-x86_64/libc_so/ctype.o build-x86_64/libc_so/entry.o build-x86_64/libc_so/errno.o build-x86_64/libc_so/fstdio.o build-x86_64/libc_so/fstdio_unlocked.o build-x86_64/libc_so/getopt.o build-x86_64/libc_so/locale.o build-x86_64/libc_so/malloc.o build-x86_64/libc_so/setjmp.o build-x86_64/libc_so/signal.o build-x86_64/libc_so/stdio.o build-x86_64/libc_so/stdlib.o build-x86_64/libc_so/string.o build-x86_64/libc_so/strtod.o build-x86_64/libc_so/synnixos.o build-x86_64/libc_so/syscall.o build-x86_64/libc_so/syscalls.o build-x86_64/libc_so/time.o build-x86_64/libc_so/todo.o build-x86_64/libc_so/unistd.o build-x86_64/libc_so/vector.o build-x86_64/libc_so/x86_64/synnixos.o 
	$(call MP_INFO,LD	libc.so)
	@~/.local/bin/x86_64-synnixos-gcc -nostdlib -fpic -shared -g -o build-x86_64/libc.so build-x86_64/libc_so/crt0.o build-x86_64/libc_so/crti.o build-x86_64/libc_so/crtn.o build-x86_64/libc_so/ctype.o build-x86_64/libc_so/entry.o build-x86_64/libc_so/errno.o build-x86_64/libc_so/fstdio.o build-x86_64/libc_so/fstdio_unlocked.o build-x86_64/libc_so/getopt.o build-x86_64/libc_so/locale.o build-x86_64/libc_so/malloc.o build-x86_64/libc_so/setjmp.o build-x86_64/libc_so/signal.o build-x86_64/libc_so/stdio.o build-x86_64/libc_so/stdlib.o build-x86_64/libc_so/string.o build-x86_64/libc_so/strtod.o build-x86_64/libc_so/synnixos.o build-x86_64/libc_so/syscall.o build-x86_64/libc_so/syscalls.o build-x86_64/libc_so/time.o build-x86_64/libc_so/todo.o build-x86_64/libc_so/unistd.o build-x86_64/libc_so/vector.o build-x86_64/libc_so/x86_64/synnixos.o 
build-x86_64/libc_so/crt0.o: libc/crt0.S
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,AS	crt0.o)
	@gcc  -MD -MF dep/libc_so/crt0.d -c libc/crt0.S -o build-x86_64/libc_so/crt0.o
build-x86_64/libc_so/crti.o: libc/crti.S
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,AS	crti.o)
	@gcc  -MD -MF dep/libc_so/crti.d -c libc/crti.S -o build-x86_64/libc_so/crti.o
build-x86_64/libc_so/crtn.o: libc/crtn.S
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,AS	crtn.o)
	@gcc  -MD -MF dep/libc_so/crtn.d -c libc/crtn.S -o build-x86_64/libc_so/crtn.o
build-x86_64/libc_so/ctype.o: libc/ctype.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	ctype.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/ctype.d -c libc/ctype.c -o build-x86_64/libc_so/ctype.o
build-x86_64/libc_so/entry.o: libc/entry.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	entry.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/entry.d -c libc/entry.c -o build-x86_64/libc_so/entry.o
build-x86_64/libc_so/errno.o: libc/errno.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	errno.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/errno.d -c libc/errno.c -o build-x86_64/libc_so/errno.o
build-x86_64/libc_so/fstdio.o: libc/fstdio.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	fstdio.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/fstdio.d -c libc/fstdio.c -o build-x86_64/libc_so/fstdio.o
build-x86_64/libc_so/fstdio_unlocked.o: libc/fstdio_unlocked.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	fstdio_unlocked.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/fstdio_unlocked.d -c libc/fstdio_unlocked.c -o build-x86_64/libc_so/fstdio_unlocked.o
build-x86_64/libc_so/getopt.o: libc/getopt.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	getopt.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/getopt.d -c libc/getopt.c -o build-x86_64/libc_so/getopt.o
build-x86_64/libc_so/locale.o: libc/locale.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	locale.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/locale.d -c libc/locale.c -o build-x86_64/libc_so/locale.o
build-x86_64/libc_so/malloc.o: libc/malloc.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	malloc.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/malloc.d -c libc/malloc.c -o build-x86_64/libc_so/malloc.o
build-x86_64/libc_so/setjmp.o: libc/setjmp.S
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,AS	setjmp.o)
	@gcc  -MD -MF dep/libc_so/setjmp.d -c libc/setjmp.S -o build-x86_64/libc_so/setjmp.o
build-x86_64/libc_so/signal.o: libc/signal.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	signal.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/signal.d -c libc/signal.c -o build-x86_64/libc_so/signal.o
build-x86_64/libc_so/stdio.o: libc/stdio.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	stdio.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/stdio.d -c libc/stdio.c -o build-x86_64/libc_so/stdio.o
build-x86_64/libc_so/stdlib.o: libc/stdlib.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	stdlib.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/stdlib.d -c libc/stdlib.c -o build-x86_64/libc_so/stdlib.o
build-x86_64/libc_so/string.o: libc/string.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	string.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/string.d -c libc/string.c -o build-x86_64/libc_so/string.o
build-x86_64/libc_so/strtod.o: libc/strtod.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	strtod.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/strtod.d -c libc/strtod.c -o build-x86_64/libc_so/strtod.o
build-x86_64/libc_so/synnixos.o: libc/synnixos.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	synnixos.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/synnixos.d -c libc/synnixos.c -o build-x86_64/libc_so/synnixos.o
build-x86_64/libc_so/syscall.o: libc/syscall.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	syscall.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/syscall.d -c libc/syscall.c -o build-x86_64/libc_so/syscall.o
build-x86_64/libc_so/syscalls.o: libc/syscalls.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	syscalls.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/syscalls.d -c libc/syscalls.c -o build-x86_64/libc_so/syscalls.o
build-x86_64/libc_so/time.o: libc/time.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	time.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/time.d -c libc/time.c -o build-x86_64/libc_so/time.o
build-x86_64/libc_so/todo.o: libc/todo.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	todo.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/todo.d -c libc/todo.c -o build-x86_64/libc_so/todo.o
build-x86_64/libc_so/unistd.o: libc/unistd.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	unistd.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/unistd.d -c libc/unistd.c -o build-x86_64/libc_so/unistd.o
build-x86_64/libc_so/vector.o: libc/vector.c
	@mkdir -p build-x86_64/libc_so
	@mkdir -p dep/libc_so
	$(call MP_INFO,CC	vector.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/vector.d -c libc/vector.c -o build-x86_64/libc_so/vector.o
build-x86_64/libc_so/x86_64/synnixos.o: libc/x86_64/synnixos.c
	@mkdir -p build-x86_64/libc_so/x86_64
	@mkdir -p dep/libc_so/x86_64
	$(call MP_INFO,CC	synnixos.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/libc_so/x86_64/synnixos.d -c libc/x86_64/synnixos.c -o build-x86_64/libc_so/x86_64/synnixos.o
build-x86_64/libk.a: build-x86_64/libk/ctype.o build-x86_64/libk/errno.o build-x86_64/libk/malloc.o build-x86_64/libk/setjmp.o build-x86_64/libk/signal.o build-x86_64/libk/stdio.o build-x86_64/libk/stdlib.o build-x86_64/libk/string.o build-x86_64/libk/x86_64/synnixos.o 
	$(call MP_INFO,AR	libk.a)
	@ar rcs -o build-x86_64/libk.a build-x86_64/libk/ctype.o build-x86_64/libk/errno.o build-x86_64/libk/malloc.o build-x86_64/libk/setjmp.o build-x86_64/libk/signal.o build-x86_64/libk/stdio.o build-x86_64/libk/stdlib.o build-x86_64/libk/string.o build-x86_64/libk/x86_64/synnixos.o
build-x86_64/libk/ctype.o: libc/ctype.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	ctype.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/ctype.d -c libc/ctype.c -o build-x86_64/libk/ctype.o
build-x86_64/libk/errno.o: libc/errno.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	errno.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/errno.d -c libc/errno.c -o build-x86_64/libk/errno.o
build-x86_64/libk/malloc.o: libc/malloc.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	malloc.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/malloc.d -c libc/malloc.c -o build-x86_64/libk/malloc.o
build-x86_64/libk/setjmp.o: libc/setjmp.S
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,AS	setjmp.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/setjmp.d -c libc/setjmp.S -o build-x86_64/libk/setjmp.o
build-x86_64/libk/signal.o: libc/signal.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	signal.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/signal.d -c libc/signal.c -o build-x86_64/libk/signal.o
build-x86_64/libk/stdio.o: libc/stdio.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	stdio.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/stdio.d -c libc/stdio.c -o build-x86_64/libk/stdio.o
build-x86_64/libk/stdlib.o: libc/stdlib.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	stdlib.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/stdlib.d -c libc/stdlib.c -o build-x86_64/libk/stdlib.o
build-x86_64/libk/string.o: libc/string.c
	@mkdir -p build-x86_64/libk
	@mkdir -p dep/libk
	$(call MP_INFO,CC	string.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/string.d -c libc/string.c -o build-x86_64/libk/string.o
build-x86_64/libk/x86_64/synnixos.o: libc/x86_64/synnixos.c
	@mkdir -p build-x86_64/libk/x86_64
	@mkdir -p dep/libk/x86_64
	$(call MP_INFO,CC	synnixos.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/libk/x86_64/synnixos.d -c libc/x86_64/synnixos.c -o build-x86_64/libk/x86_64/synnixos.o
build-x86_64/snxk.elf: build-x86_64/fs/char_devices.o build-x86_64/fs/directory.o build-x86_64/fs/fs.o build-x86_64/fs/membuf.o build-x86_64/fs/pipe.o build-x86_64/fs/procfs.o build-x86_64/fs/socket.o build-x86_64/kernel/debug.o build-x86_64/kernel/dmgr.o build-x86_64/kernel/elf.o build-x86_64/kernel/exec.o build-x86_64/kernel/irq.o build-x86_64/kernel/main.o build-x86_64/kernel/mman.o build-x86_64/kernel/mod.o build-x86_64/kernel/multiboot.o build-x86_64/kernel/pci.o build-x86_64/kernel/pmm.o build-x86_64/kernel/rand.o build-x86_64/kernel/ringbuf.o build-x86_64/kernel/serial.o build-x86_64/kernel/signal.o build-x86_64/kernel/spalloc.o build-x86_64/kernel/string.o build-x86_64/kernel/sync.o build-x86_64/kernel/sync_testbed.o build-x86_64/kernel/syscall.o build-x86_64/kernel/tarfs.o build-x86_64/kernel/tests.o build-x86_64/kernel/thread.o build-x86_64/kernel/timer.o build-x86_64/kernel/trace.o build-x86_64/kernel/tty.o build-x86_64/kernel/ubsan.o build-x86_64/kernel/uname.o build-x86_64/linker/elf-snx.o build-x86_64/linker/modld.o build-x86_64/x86/acpi.o build-x86_64/x86/apic.o build-x86_64/x86/boot.o build-x86_64/x86/cpu.o build-x86_64/x86/halt.o build-x86_64/x86/interrupt.o build-x86_64/x86/isrs.o build-x86_64/x86/pic.o build-x86_64/x86/pit.o build-x86_64/x86/uart.o build-x86_64/x86/vmm.o build-x86_64/libk.a
	$(call MP_INFO,LD	snxk.elf)
	@~/.local/bin/x86_64-synnixos-gcc -nostdlib -Tx86/link_hh.ld -zmax-page-size=0x1000 -g -Lbuild-x86_64 -o build-x86_64/snxk.elf build-x86_64/fs/char_devices.o build-x86_64/fs/directory.o build-x86_64/fs/fs.o build-x86_64/fs/membuf.o build-x86_64/fs/pipe.o build-x86_64/fs/procfs.o build-x86_64/fs/socket.o build-x86_64/kernel/debug.o build-x86_64/kernel/dmgr.o build-x86_64/kernel/elf.o build-x86_64/kernel/exec.o build-x86_64/kernel/irq.o build-x86_64/kernel/main.o build-x86_64/kernel/mman.o build-x86_64/kernel/mod.o build-x86_64/kernel/multiboot.o build-x86_64/kernel/pci.o build-x86_64/kernel/pmm.o build-x86_64/kernel/rand.o build-x86_64/kernel/ringbuf.o build-x86_64/kernel/serial.o build-x86_64/kernel/signal.o build-x86_64/kernel/spalloc.o build-x86_64/kernel/string.o build-x86_64/kernel/sync.o build-x86_64/kernel/sync_testbed.o build-x86_64/kernel/syscall.o build-x86_64/kernel/tarfs.o build-x86_64/kernel/tests.o build-x86_64/kernel/thread.o build-x86_64/kernel/timer.o build-x86_64/kernel/trace.o build-x86_64/kernel/tty.o build-x86_64/kernel/ubsan.o build-x86_64/kernel/uname.o build-x86_64/linker/elf-snx.o build-x86_64/linker/modld.o build-x86_64/x86/acpi.o build-x86_64/x86/apic.o build-x86_64/x86/boot.o build-x86_64/x86/cpu.o build-x86_64/x86/halt.o build-x86_64/x86/interrupt.o build-x86_64/x86/isrs.o build-x86_64/x86/pic.o build-x86_64/x86/pit.o build-x86_64/x86/uart.o build-x86_64/x86/vmm.o -lk -lgcc
build-x86_64/fs/char_devices.o: fs/char_devices.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	char_devices.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/char_devices.d -c fs/char_devices.c -o build-x86_64/fs/char_devices.o
build-x86_64/fs/directory.o: fs/directory.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	directory.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/directory.d -c fs/directory.c -o build-x86_64/fs/directory.o
build-x86_64/fs/fs.o: fs/fs.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	fs.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/fs.d -c fs/fs.c -o build-x86_64/fs/fs.o
build-x86_64/fs/membuf.o: fs/membuf.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	membuf.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/membuf.d -c fs/membuf.c -o build-x86_64/fs/membuf.o
build-x86_64/fs/pipe.o: fs/pipe.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	pipe.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/pipe.d -c fs/pipe.c -o build-x86_64/fs/pipe.o
build-x86_64/fs/procfs.o: fs/procfs.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	procfs.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/procfs.d -c fs/procfs.c -o build-x86_64/fs/procfs.o
build-x86_64/fs/socket.o: fs/socket.c
	@mkdir -p build-x86_64/fs
	@mkdir -p dep/fs
	$(call MP_INFO,CC	socket.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/fs/socket.d -c fs/socket.c -o build-x86_64/fs/socket.o
build-x86_64/kernel/debug.o: kernel/debug.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	debug.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/debug.d -c kernel/debug.c -o build-x86_64/kernel/debug.o
build-x86_64/kernel/dmgr.o: kernel/dmgr.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	dmgr.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/dmgr.d -c kernel/dmgr.c -o build-x86_64/kernel/dmgr.o
build-x86_64/kernel/elf.o: kernel/elf.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	elf.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/elf.d -c kernel/elf.c -o build-x86_64/kernel/elf.o
build-x86_64/kernel/exec.o: kernel/exec.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	exec.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/exec.d -c kernel/exec.c -o build-x86_64/kernel/exec.o
build-x86_64/kernel/irq.o: kernel/irq.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	irq.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/irq.d -c kernel/irq.c -o build-x86_64/kernel/irq.o
build-x86_64/kernel/main.o: kernel/main.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	main.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/main.d -c kernel/main.c -o build-x86_64/kernel/main.o
build-x86_64/kernel/mman.o: kernel/mman.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	mman.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/mman.d -c kernel/mman.c -o build-x86_64/kernel/mman.o
build-x86_64/kernel/mod.o: kernel/mod.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	mod.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/mod.d -c kernel/mod.c -o build-x86_64/kernel/mod.o
build-x86_64/kernel/multiboot.o: kernel/multiboot.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	multiboot.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/multiboot.d -c kernel/multiboot.c -o build-x86_64/kernel/multiboot.o
build-x86_64/kernel/pci.o: kernel/pci.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	pci.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/pci.d -c kernel/pci.c -o build-x86_64/kernel/pci.o
build-x86_64/kernel/pmm.o: kernel/pmm.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	pmm.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/pmm.d -c kernel/pmm.c -o build-x86_64/kernel/pmm.o
build-x86_64/kernel/rand.o: kernel/rand.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	rand.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/rand.d -c kernel/rand.c -o build-x86_64/kernel/rand.o
build-x86_64/kernel/ringbuf.o: kernel/ringbuf.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	ringbuf.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/ringbuf.d -c kernel/ringbuf.c -o build-x86_64/kernel/ringbuf.o
build-x86_64/kernel/serial.o: kernel/serial.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	serial.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/serial.d -c kernel/serial.c -o build-x86_64/kernel/serial.o
build-x86_64/kernel/signal.o: kernel/signal.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	signal.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/signal.d -c kernel/signal.c -o build-x86_64/kernel/signal.o
build-x86_64/kernel/spalloc.o: kernel/spalloc.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	spalloc.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/spalloc.d -c kernel/spalloc.c -o build-x86_64/kernel/spalloc.o
build-x86_64/kernel/string.o: kernel/string.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	string.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/string.d -c kernel/string.c -o build-x86_64/kernel/string.o
build-x86_64/kernel/sync.o: kernel/sync.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	sync.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/sync.d -c kernel/sync.c -o build-x86_64/kernel/sync.o
build-x86_64/kernel/sync_testbed.o: kernel/sync_testbed.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	sync_testbed.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/sync_testbed.d -c kernel/sync_testbed.c -o build-x86_64/kernel/sync_testbed.o
build-x86_64/kernel/syscall.o: kernel/syscall.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	syscall.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/syscall.d -c kernel/syscall.c -o build-x86_64/kernel/syscall.o
build-x86_64/kernel/tarfs.o: kernel/tarfs.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	tarfs.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/tarfs.d -c kernel/tarfs.c -o build-x86_64/kernel/tarfs.o
build-x86_64/kernel/tests.o: kernel/tests.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	tests.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/tests.d -c kernel/tests.c -o build-x86_64/kernel/tests.o
build-x86_64/kernel/thread.o: kernel/thread.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	thread.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/thread.d -c kernel/thread.c -o build-x86_64/kernel/thread.o
build-x86_64/kernel/timer.o: kernel/timer.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	timer.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/timer.d -c kernel/timer.c -o build-x86_64/kernel/timer.o
build-x86_64/kernel/trace.o: kernel/trace.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	trace.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/trace.d -c kernel/trace.c -o build-x86_64/kernel/trace.o
build-x86_64/kernel/tty.o: kernel/tty.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	tty.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/tty.d -c kernel/tty.c -o build-x86_64/kernel/tty.o
build-x86_64/kernel/ubsan.o: kernel/ubsan.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	ubsan.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/ubsan.d -c kernel/ubsan.c -o build-x86_64/kernel/ubsan.o
build-x86_64/kernel/uname.o: kernel/uname.c
	@mkdir -p build-x86_64/kernel
	@mkdir -p dep/kernel
	$(call MP_INFO,CC	uname.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/kernel/uname.d -c kernel/uname.c -o build-x86_64/kernel/uname.o
build-x86_64/linker/elf-snx.o: linker/elf-snx.c
	@mkdir -p build-x86_64/linker
	@mkdir -p dep/linker
	$(call MP_INFO,CC	elf-snx.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/linker/elf-snx.d -c linker/elf-snx.c -o build-x86_64/linker/elf-snx.o
build-x86_64/linker/modld.o: linker/modld.c
	@mkdir -p build-x86_64/linker
	@mkdir -p dep/linker
	$(call MP_INFO,CC	modld.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/linker/modld.d -c linker/modld.c -o build-x86_64/linker/modld.o
build-x86_64/x86/acpi.o: x86/acpi.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	acpi.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/acpi.d -c x86/acpi.c -o build-x86_64/x86/acpi.o
build-x86_64/x86/apic.o: x86/apic.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	apic.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/apic.d -c x86/apic.c -o build-x86_64/x86/apic.o
build-x86_64/x86/boot.o: x86/boot.asm
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,NASM	boot.o)
	@nasm -felf64 x86/boot.asm -o build-x86_64/x86/boot.o
build-x86_64/x86/cpu.o: x86/cpu.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	cpu.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/cpu.d -c x86/cpu.c -o build-x86_64/x86/cpu.o
build-x86_64/x86/halt.o: x86/halt.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	halt.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/halt.d -c x86/halt.c -o build-x86_64/x86/halt.o
build-x86_64/x86/interrupt.o: x86/interrupt.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	interrupt.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/interrupt.d -c x86/interrupt.c -o build-x86_64/x86/interrupt.o
build-x86_64/x86/isrs.o: x86/isrs.asm
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,NASM	isrs.o)
	@nasm -felf64 x86/isrs.asm -o build-x86_64/x86/isrs.o
build-x86_64/x86/pic.o: x86/pic.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	pic.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/pic.d -c x86/pic.c -o build-x86_64/x86/pic.o
build-x86_64/x86/pit.o: x86/pit.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	pit.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/pit.d -c x86/pit.c -o build-x86_64/x86/pit.o
build-x86_64/x86/uart.o: x86/uart.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	uart.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/uart.d -c x86/uart.c -o build-x86_64/x86/uart.o
build-x86_64/x86/vmm.o: x86/vmm.c
	@mkdir -p build-x86_64/x86
	@mkdir -p dep/x86
	$(call MP_INFO,CC	vmm.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/x86/vmm.d -c x86/vmm.c -o build-x86_64/x86/vmm.o
build-x86_64/crt0.o: build-x86_64/crt/crt0.o
	$(call MP_INFO,CP	crt0.o)
	@cp --preserve=timestamps build-x86_64/crt/crt0.o build-x86_64/crt0.o
build-x86_64/crt/crt0.o: libc/crt0.S
	@mkdir -p build-x86_64/crt
	@mkdir -p dep/crt
	$(call MP_INFO,AS	crt0.o)
	@~/.local/bin/x86_64-synnixos-gcc  -MD -MF dep/crt/crt0.d -c libc/crt0.S -o build-x86_64/crt/crt0.o
build-x86_64/sh: build-x86_64/sh-/eval.o build-x86_64/sh-/parse.o build-x86_64/sh-/readline.o build-x86_64/sh-/sh.o build-x86_64/sh-/token.o sysroot/usr/lib/libc.a sysroot/usr/lib/crt0.o
	$(call MP_INFO,LD	sh)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/sh build-x86_64/sh-/eval.o build-x86_64/sh-/parse.o build-x86_64/sh-/readline.o build-x86_64/sh-/sh.o build-x86_64/sh-/token.o 
build-x86_64/sh-/eval.o: sh/eval.c
	@mkdir -p build-x86_64/sh-
	@mkdir -p dep/sh-
	$(call MP_INFO,CC	eval.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/sh-/eval.d -c sh/eval.c -o build-x86_64/sh-/eval.o
build-x86_64/sh-/parse.o: sh/parse.c
	@mkdir -p build-x86_64/sh-
	@mkdir -p dep/sh-
	$(call MP_INFO,CC	parse.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/sh-/parse.d -c sh/parse.c -o build-x86_64/sh-/parse.o
build-x86_64/sh-/readline.o: sh/readline.c
	@mkdir -p build-x86_64/sh-
	@mkdir -p dep/sh-
	$(call MP_INFO,CC	readline.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/sh-/readline.d -c sh/readline.c -o build-x86_64/sh-/readline.o
build-x86_64/sh-/sh.o: sh/sh.c
	@mkdir -p build-x86_64/sh-
	@mkdir -p dep/sh-
	$(call MP_INFO,CC	sh.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/sh-/sh.d -c sh/sh.c -o build-x86_64/sh-/sh.o
build-x86_64/sh-/token.o: sh/token.c
	@mkdir -p build-x86_64/sh-
	@mkdir -p dep/sh-
	$(call MP_INFO,CC	token.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/sh-/token.d -c sh/token.c -o build-x86_64/sh-/token.o
build-x86_64/ld-snx.so: build-x86_64/ld-snx/syscall.o build-x86_64/ld-snx/syscalls.o build-x86_64/ld-snx/elf-snx.o build-x86_64/ld-snx/ldso.o build-x86_64/ld-snx/pltstub.o 
	$(call MP_INFO,LD	ld-snx.so)
	@~/.local/bin/x86_64-synnixos-gcc -nostdlib -fpic -shared -g -o build-x86_64/ld-snx.so build-x86_64/ld-snx/syscall.o build-x86_64/ld-snx/syscalls.o build-x86_64/ld-snx/elf-snx.o build-x86_64/ld-snx/ldso.o build-x86_64/ld-snx/pltstub.o 
build-x86_64/ld-snx/syscall.o: libc/syscall.c
	@mkdir -p build-x86_64/ld-snx
	@mkdir -p dep/ld-snx
	$(call MP_INFO,CC	syscall.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/ld-snx/syscall.d -c libc/syscall.c -o build-x86_64/ld-snx/syscall.o
build-x86_64/ld-snx/syscalls.o: libc/syscalls.c
	@mkdir -p build-x86_64/ld-snx
	@mkdir -p dep/ld-snx
	$(call MP_INFO,CC	syscalls.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/ld-snx/syscalls.d -c libc/syscalls.c -o build-x86_64/ld-snx/syscalls.o
build-x86_64/ld-snx/elf-snx.o: linker/elf-snx.c
	@mkdir -p build-x86_64/ld-snx
	@mkdir -p dep/ld-snx
	$(call MP_INFO,CC	elf-snx.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/ld-snx/elf-snx.d -c linker/elf-snx.c -o build-x86_64/ld-snx/elf-snx.o
build-x86_64/ld-snx/ldso.o: linker/ldso.c
	@mkdir -p build-x86_64/ld-snx
	@mkdir -p dep/ld-snx
	$(call MP_INFO,CC	ldso.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -fpic -shared -MD -MF dep/ld-snx/ldso.d -c linker/ldso.c -o build-x86_64/ld-snx/ldso.o
build-x86_64/ld-snx/pltstub.o: linker/pltstub.S
	@mkdir -p build-x86_64/ld-snx
	@mkdir -p dep/ld-snx
	$(call MP_INFO,AS	pltstub.o)
	@gcc  -MD -MF dep/ld-snx/pltstub.d -c linker/pltstub.S -o build-x86_64/ld-snx/pltstub.o
build-x86_64/file.ko: build-x86_64/modules/file.o
	$(call MP_INFO,CP	file.ko)
	@cp --preserve=timestamps build-x86_64/modules/file.o build-x86_64/file.ko
build-x86_64/modules/file.o: modules/file.c
	@mkdir -p build-x86_64/modules
	@mkdir -p dep/modules
	$(call MP_INFO,CC	file.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/modules/file.d -c modules/file.c -o build-x86_64/modules/file.o
build-x86_64/procmod.ko: build-x86_64/modules/procmod.o
	$(call MP_INFO,CP	procmod.ko)
	@cp --preserve=timestamps build-x86_64/modules/procmod.o build-x86_64/procmod.ko
build-x86_64/modules/procmod.o: modules/procmod.c
	@mkdir -p build-x86_64/modules
	@mkdir -p dep/modules
	$(call MP_INFO,CC	procmod.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -pedantic -ffreestanding -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2 -nostdlib -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -DSYNNIXOS_VERSION=\"$(SYNNIXOS_VERSION)\" -D__kernel__=1 -D_SNX=1 -mcmodel=kernel -fsanitize=undefined $(KERNEL_CFLAGS) -MD -MF dep/modules/procmod.d -c modules/procmod.c -o build-x86_64/modules/procmod.o
build-x86_64/ls: build-x86_64/user/ls.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	ls)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/ls build-x86_64/user/ls.o 
build-x86_64/user/ls.o: user/ls.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	ls.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/ls.d -c user/ls.c -o build-x86_64/user/ls.o
build-x86_64/column: build-x86_64/user/column.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	column)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/column build-x86_64/user/column.o 
build-x86_64/user/column.o: user/column.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	column.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/column.d -c user/column.c -o build-x86_64/user/column.o
build-x86_64/trace: build-x86_64/user/trace.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	trace)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/trace build-x86_64/user/trace.o 
build-x86_64/user/trace.o: user/trace.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	trace.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/trace.d -c user/trace.c -o build-x86_64/user/trace.o
build-x86_64/modsys: build-x86_64/user/modsys.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	modsys)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/modsys build-x86_64/user/modsys.o 
build-x86_64/user/modsys.o: user/modsys.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	modsys.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/modsys.d -c user/modsys.c -o build-x86_64/user/modsys.o
build-x86_64/step: build-x86_64/user/step.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	step)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/step build-x86_64/user/step.o -lelf
build-x86_64/user/step.o: user/step.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	step.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/step.d -c user/step.c -o build-x86_64/user/step.o
build-x86_64/false: build-x86_64/user/false.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	false)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/false build-x86_64/user/false.o 
build-x86_64/user/false.o: user/false.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	false.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/false.d -c user/false.c -o build-x86_64/user/false.o
build-x86_64/mmap: build-x86_64/user/mmap.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	mmap)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/mmap build-x86_64/user/mmap.o 
build-x86_64/user/mmap.o: user/mmap.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	mmap.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/mmap.d -c user/mmap.c -o build-x86_64/user/mmap.o
build-x86_64/rm: build-x86_64/user/rm.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	rm)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/rm build-x86_64/user/rm.o 
build-x86_64/user/rm.o: user/rm.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	rm.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/rm.d -c user/rm.c -o build-x86_64/user/rm.o
build-x86_64/cat: build-x86_64/user/cat.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	cat)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/cat build-x86_64/user/cat.o 
build-x86_64/user/cat.o: user/cat.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	cat.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/cat.d -c user/cat.c -o build-x86_64/user/cat.o
build-x86_64/init: build-x86_64/user/init.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	init)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/init build-x86_64/user/init.o 
build-x86_64/user/init.o: user/init.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	init.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/init.d -c user/init.c -o build-x86_64/user/init.o
build-x86_64/insmod: build-x86_64/user/insmod.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	insmod)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/insmod build-x86_64/user/insmod.o 
build-x86_64/user/insmod.o: user/insmod.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	insmod.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/insmod.d -c user/insmod.c -o build-x86_64/user/insmod.o
build-x86_64/kill: build-x86_64/user/kill.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	kill)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/kill build-x86_64/user/kill.o 
build-x86_64/user/kill.o: user/kill.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	kill.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/kill.d -c user/kill.c -o build-x86_64/user/kill.o
build-x86_64/chmod: build-x86_64/user/chmod.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	chmod)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/chmod build-x86_64/user/chmod.o 
build-x86_64/user/chmod.o: user/chmod.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	chmod.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/chmod.d -c user/chmod.c -o build-x86_64/user/chmod.o
build-x86_64/time: build-x86_64/user/time.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	time)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/time build-x86_64/user/time.o 
build-x86_64/user/time.o: user/time.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	time.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/time.d -c user/time.c -o build-x86_64/user/time.o
build-x86_64/strace: build-x86_64/user/strace.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	strace)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/strace build-x86_64/user/strace.o 
build-x86_64/user/strace.o: user/strace.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	strace.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/strace.d -c user/strace.c -o build-x86_64/user/strace.o
build-x86_64/sleep: build-x86_64/user/sleep.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	sleep)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/sleep build-x86_64/user/sleep.o 
build-x86_64/user/sleep.o: user/sleep.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	sleep.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/sleep.d -c user/sleep.c -o build-x86_64/user/sleep.o
build-x86_64/ab: build-x86_64/user/ab.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	ab)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/ab build-x86_64/user/ab.o 
build-x86_64/user/ab.o: user/ab.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	ab.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/ab.d -c user/ab.c -o build-x86_64/user/ab.o
build-x86_64/echo: build-x86_64/user/echo.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	echo)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/echo build-x86_64/user/echo.o 
build-x86_64/user/echo.o: user/echo.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	echo.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/echo.d -c user/echo.c -o build-x86_64/user/echo.o
build-x86_64/top: build-x86_64/user/top.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	top)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/top build-x86_64/user/top.o 
build-x86_64/user/top.o: user/top.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	top.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/top.d -c user/top.c -o build-x86_64/user/top.o
build-x86_64/rot13: build-x86_64/user/rot13.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	rot13)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/rot13 build-x86_64/user/rot13.o 
build-x86_64/user/rot13.o: user/rot13.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	rot13.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/rot13.d -c user/rot13.c -o build-x86_64/user/rot13.o
build-x86_64/xd: build-x86_64/user/xd.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	xd)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/xd build-x86_64/user/xd.o 
build-x86_64/user/xd.o: user/xd.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	xd.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/xd.d -c user/xd.c -o build-x86_64/user/xd.o
build-x86_64/create: build-x86_64/user/create.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	create)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/create build-x86_64/user/create.o 
build-x86_64/user/create.o: user/create.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	create.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/create.d -c user/create.c -o build-x86_64/user/create.o
build-x86_64/args: build-x86_64/user/args.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	args)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/args build-x86_64/user/args.o 
build-x86_64/user/args.o: user/args.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	args.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/args.d -c user/args.c -o build-x86_64/user/args.o
build-x86_64/uname: build-x86_64/user/uname.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	uname)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/uname build-x86_64/user/uname.o 
build-x86_64/user/uname.o: user/uname.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	uname.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/uname.d -c user/uname.c -o build-x86_64/user/uname.o
build-x86_64/true: build-x86_64/user/true.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	true)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/true build-x86_64/user/true.o 
build-x86_64/user/true.o: user/true.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	true.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/true.d -c user/true.c -o build-x86_64/user/true.o
build-x86_64/bf2: build-x86_64/user/bf2.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	bf2)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/bf2 build-x86_64/user/bf2.o 
build-x86_64/user/bf2.o: user/bf2.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	bf2.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/bf2.d -c user/bf2.c -o build-x86_64/user/bf2.o
build-x86_64/traceback: build-x86_64/user/traceback.o sysroot/usr/lib/libc.so sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a
	$(call MP_INFO,LD	traceback)
	@~/.local/bin/x86_64-synnixos-gcc -g -static -o build-x86_64/traceback build-x86_64/user/traceback.o 
build-x86_64/user/traceback.o: user/traceback.c
	@mkdir -p build-x86_64/user
	@mkdir -p dep/user
	$(call MP_INFO,CC	traceback.o)
	@~/.local/bin/x86_64-synnixos-gcc -std=c11 -Wall -Wextra -Werror -g -O2 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-sign-compare -Wno-address-of-packed-member $(CFLAGS) -Wno-builtin-declaration-mismatch -Wno-format $(USER_CFLAGS) -static -MD -MF dep/user/traceback.d -c user/traceback.c -o build-x86_64/user/traceback.o

sysroot/usr/lib/libc.a: build-x86_64/libc.a
	$(call MP_INFO,install	libc.a)
	@cp build-x86_64/libc.a sysroot/usr/lib/libc.a

sysroot/usr/lib/libm.a: build-x86_64/libm.a
	$(call MP_INFO,install	libm.a)
	@cp build-x86_64/libm.a sysroot/usr/lib/libm.a

sysroot/usr/lib/libelf.a: build-x86_64/libelf.a
	$(call MP_INFO,install	libelf.a)
	@cp build-x86_64/libelf.a sysroot/usr/lib/libelf.a

sysroot/usr/lib/libc.so: build-x86_64/libc.so
	$(call MP_INFO,install	libc.so)
	@cp build-x86_64/libc.so sysroot/usr/lib/libc.so

snxk.elf: build-x86_64/snxk.elf
	$(call MP_INFO,install	snxk.elf)
	@cp build-x86_64/snxk.elf snxk.elf

sysroot/usr/lib/crt0.o: build-x86_64/crt0.o
	$(call MP_INFO,install	crt0.o)
	@cp build-x86_64/crt0.o sysroot/usr/lib/crt0.o

sysroot/bin/sh: build-x86_64/sh
	$(call MP_INFO,install	sh)
	@cp build-x86_64/sh sysroot/bin/sh

sysroot/bin/ld-snx.so: build-x86_64/ld-snx.so
	$(call MP_INFO,install	ld-snx.so)
	@cp build-x86_64/ld-snx.so sysroot/bin/ld-snx.so

sysroot/bin/file.ko: build-x86_64/file.ko
	$(call MP_INFO,install	file.ko)
	@cp build-x86_64/file.ko sysroot/bin/file.ko

sysroot/bin/procmod.ko: build-x86_64/procmod.ko
	$(call MP_INFO,install	procmod.ko)
	@cp build-x86_64/procmod.ko sysroot/bin/procmod.ko

sysroot/bin/ls: build-x86_64/ls
	$(call MP_INFO,install	ls)
	@cp build-x86_64/ls sysroot/bin/ls

sysroot/bin/column: build-x86_64/column
	$(call MP_INFO,install	column)
	@cp build-x86_64/column sysroot/bin/column

sysroot/bin/trace: build-x86_64/trace
	$(call MP_INFO,install	trace)
	@cp build-x86_64/trace sysroot/bin/trace

sysroot/bin/modsys: build-x86_64/modsys
	$(call MP_INFO,install	modsys)
	@cp build-x86_64/modsys sysroot/bin/modsys

sysroot/bin/step: build-x86_64/step
	$(call MP_INFO,install	step)
	@cp build-x86_64/step sysroot/bin/step

sysroot/bin/false: build-x86_64/false
	$(call MP_INFO,install	false)
	@cp build-x86_64/false sysroot/bin/false

sysroot/bin/mmap: build-x86_64/mmap
	$(call MP_INFO,install	mmap)
	@cp build-x86_64/mmap sysroot/bin/mmap

sysroot/bin/rm: build-x86_64/rm
	$(call MP_INFO,install	rm)
	@cp build-x86_64/rm sysroot/bin/rm

sysroot/bin/cat: build-x86_64/cat
	$(call MP_INFO,install	cat)
	@cp build-x86_64/cat sysroot/bin/cat

sysroot/bin/init: build-x86_64/init
	$(call MP_INFO,install	init)
	@cp build-x86_64/init sysroot/bin/init

sysroot/bin/insmod: build-x86_64/insmod
	$(call MP_INFO,install	insmod)
	@cp build-x86_64/insmod sysroot/bin/insmod

sysroot/bin/kill: build-x86_64/kill
	$(call MP_INFO,install	kill)
	@cp build-x86_64/kill sysroot/bin/kill

sysroot/bin/chmod: build-x86_64/chmod
	$(call MP_INFO,install	chmod)
	@cp build-x86_64/chmod sysroot/bin/chmod

sysroot/bin/time: build-x86_64/time
	$(call MP_INFO,install	time)
	@cp build-x86_64/time sysroot/bin/time

sysroot/bin/strace: build-x86_64/strace
	$(call MP_INFO,install	strace)
	@cp build-x86_64/strace sysroot/bin/strace

sysroot/bin/sleep: build-x86_64/sleep
	$(call MP_INFO,install	sleep)
	@cp build-x86_64/sleep sysroot/bin/sleep

sysroot/bin/ab: build-x86_64/ab
	$(call MP_INFO,install	ab)
	@cp build-x86_64/ab sysroot/bin/ab

sysroot/bin/echo: build-x86_64/echo
	$(call MP_INFO,install	echo)
	@cp build-x86_64/echo sysroot/bin/echo

sysroot/bin/top: build-x86_64/top
	$(call MP_INFO,install	top)
	@cp build-x86_64/top sysroot/bin/top

sysroot/bin/rot13: build-x86_64/rot13
	$(call MP_INFO,install	rot13)
	@cp build-x86_64/rot13 sysroot/bin/rot13

sysroot/bin/xd: build-x86_64/xd
	$(call MP_INFO,install	xd)
	@cp build-x86_64/xd sysroot/bin/xd

sysroot/bin/create: build-x86_64/create
	$(call MP_INFO,install	create)
	@cp build-x86_64/create sysroot/bin/create

sysroot/bin/args: build-x86_64/args
	$(call MP_INFO,install	args)
	@cp build-x86_64/args sysroot/bin/args

sysroot/bin/uname: build-x86_64/uname
	$(call MP_INFO,install	uname)
	@cp build-x86_64/uname sysroot/bin/uname

sysroot/bin/true: build-x86_64/true
	$(call MP_INFO,install	true)
	@cp build-x86_64/true sysroot/bin/true

sysroot/bin/bf2: build-x86_64/bf2
	$(call MP_INFO,install	bf2)
	@cp build-x86_64/bf2 sysroot/bin/bf2

sysroot/bin/traceback: build-x86_64/traceback
	$(call MP_INFO,install	traceback)
	@cp build-x86_64/traceback sysroot/bin/traceback


mp_install: $(MP_ALL_INSTALL)

mp_clean:
	@echo "Clean magpie objects"
	@rm -f $(MP_ALL_OBJECTS)


MP_ALL_INSTALL_TARGETS := sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a sysroot/usr/lib/libc.so snxk.elf sysroot/usr/lib/crt0.o sysroot/bin/sh sysroot/bin/ld-snx.so sysroot/bin/file.ko sysroot/bin/procmod.ko sysroot/bin/ls sysroot/bin/column sysroot/bin/trace sysroot/bin/modsys sysroot/bin/step sysroot/bin/false sysroot/bin/mmap sysroot/bin/rm sysroot/bin/cat sysroot/bin/init sysroot/bin/insmod sysroot/bin/kill sysroot/bin/chmod sysroot/bin/time sysroot/bin/strace sysroot/bin/sleep sysroot/bin/ab sysroot/bin/echo sysroot/bin/top sysroot/bin/rot13 sysroot/bin/xd sysroot/bin/create sysroot/bin/args sysroot/bin/uname sysroot/bin/true sysroot/bin/bf2 sysroot/bin/traceback
MP_ALL_INSTALL := sysroot/usr/lib/libc.a sysroot/usr/lib/libm.a sysroot/usr/lib/libelf.a sysroot/usr/lib/libc.so build-x86_64/libk.a snxk.elf sysroot/usr/lib/crt0.o sysroot/bin/sh sysroot/bin/ld-snx.so sysroot/bin/file.ko sysroot/bin/procmod.ko sysroot/bin/ls sysroot/bin/column sysroot/bin/trace sysroot/bin/modsys sysroot/bin/step sysroot/bin/false sysroot/bin/mmap sysroot/bin/rm sysroot/bin/cat sysroot/bin/init sysroot/bin/insmod sysroot/bin/kill sysroot/bin/chmod sysroot/bin/time sysroot/bin/strace sysroot/bin/sleep sysroot/bin/ab sysroot/bin/echo sysroot/bin/top sysroot/bin/rot13 sysroot/bin/xd sysroot/bin/create sysroot/bin/args sysroot/bin/uname sysroot/bin/true sysroot/bin/bf2 sysroot/bin/traceback
MP_ALL_TARGETS := build-x86_64/libc.a build-x86_64/libm.a build-x86_64/libelf.a build-x86_64/libc.so build-x86_64/libk.a build-x86_64/snxk.elf build-x86_64/crt0.o build-x86_64/sh build-x86_64/ld-snx.so build-x86_64/file.ko build-x86_64/procmod.ko build-x86_64/ls build-x86_64/column build-x86_64/trace build-x86_64/modsys build-x86_64/step build-x86_64/false build-x86_64/mmap build-x86_64/rm build-x86_64/cat build-x86_64/init build-x86_64/insmod build-x86_64/kill build-x86_64/chmod build-x86_64/time build-x86_64/strace build-x86_64/sleep build-x86_64/ab build-x86_64/echo build-x86_64/top build-x86_64/rot13 build-x86_64/xd build-x86_64/create build-x86_64/args build-x86_64/uname build-x86_64/true build-x86_64/bf2 build-x86_64/traceback
MP_ALL_OBJECTS := build-x86_64/libc.a build-x86_64/libc/crt0.o build-x86_64/libc/crti.o build-x86_64/libc/crtn.o build-x86_64/libc/ctype.o build-x86_64/libc/entry.o build-x86_64/libc/errno.o build-x86_64/libc/fstdio.o build-x86_64/libc/fstdio_unlocked.o build-x86_64/libc/getopt.o build-x86_64/libc/locale.o build-x86_64/libc/malloc.o build-x86_64/libc/setjmp.o build-x86_64/libc/signal.o build-x86_64/libc/stdio.o build-x86_64/libc/stdlib.o build-x86_64/libc/string.o build-x86_64/libc/strtod.o build-x86_64/libc/synnixos.o build-x86_64/libc/syscall.o build-x86_64/libc/syscalls.o build-x86_64/libc/time.o build-x86_64/libc/todo.o build-x86_64/libc/unistd.o build-x86_64/libc/vector.o build-x86_64/libc/x86_64/synnixos.o build-x86_64/libm.a build-x86_64/libm/complex.o build-x86_64/libm/double.o build-x86_64/libm/random.o build-x86_64/libelf.a build-x86_64/libelf/elf-snx.o build-x86_64/libc.so build-x86_64/libc_so/crt0.o build-x86_64/libc_so/crti.o build-x86_64/libc_so/crtn.o build-x86_64/libc_so/ctype.o build-x86_64/libc_so/entry.o build-x86_64/libc_so/errno.o build-x86_64/libc_so/fstdio.o build-x86_64/libc_so/fstdio_unlocked.o build-x86_64/libc_so/getopt.o build-x86_64/libc_so/locale.o build-x86_64/libc_so/malloc.o build-x86_64/libc_so/setjmp.o build-x86_64/libc_so/signal.o build-x86_64/libc_so/stdio.o build-x86_64/libc_so/stdlib.o build-x86_64/libc_so/string.o build-x86_64/libc_so/strtod.o build-x86_64/libc_so/synnixos.o build-x86_64/libc_so/syscall.o build-x86_64/libc_so/syscalls.o build-x86_64/libc_so/time.o build-x86_64/libc_so/todo.o build-x86_64/libc_so/unistd.o build-x86_64/libc_so/vector.o build-x86_64/libc_so/x86_64/synnixos.o build-x86_64/libk.a build-x86_64/libk/ctype.o build-x86_64/libk/errno.o build-x86_64/libk/malloc.o build-x86_64/libk/setjmp.o build-x86_64/libk/signal.o build-x86_64/libk/stdio.o build-x86_64/libk/stdlib.o build-x86_64/libk/string.o build-x86_64/libk/x86_64/synnixos.o build-x86_64/snxk.elf build-x86_64/fs/char_devices.o build-x86_64/fs/directory.o build-x86_64/fs/fs.o build-x86_64/fs/membuf.o build-x86_64/fs/pipe.o build-x86_64/fs/procfs.o build-x86_64/fs/socket.o build-x86_64/kernel/debug.o build-x86_64/kernel/dmgr.o build-x86_64/kernel/elf.o build-x86_64/kernel/exec.o build-x86_64/kernel/irq.o build-x86_64/kernel/main.o build-x86_64/kernel/mman.o build-x86_64/kernel/mod.o build-x86_64/kernel/multiboot.o build-x86_64/kernel/pci.o build-x86_64/kernel/pmm.o build-x86_64/kernel/rand.o build-x86_64/kernel/ringbuf.o build-x86_64/kernel/serial.o build-x86_64/kernel/signal.o build-x86_64/kernel/spalloc.o build-x86_64/kernel/string.o build-x86_64/kernel/sync.o build-x86_64/kernel/sync_testbed.o build-x86_64/kernel/syscall.o build-x86_64/kernel/tarfs.o build-x86_64/kernel/tests.o build-x86_64/kernel/thread.o build-x86_64/kernel/timer.o build-x86_64/kernel/trace.o build-x86_64/kernel/tty.o build-x86_64/kernel/ubsan.o build-x86_64/kernel/uname.o build-x86_64/linker/elf-snx.o build-x86_64/linker/modld.o build-x86_64/x86/acpi.o build-x86_64/x86/apic.o build-x86_64/x86/boot.o build-x86_64/x86/cpu.o build-x86_64/x86/halt.o build-x86_64/x86/interrupt.o build-x86_64/x86/isrs.o build-x86_64/x86/pic.o build-x86_64/x86/pit.o build-x86_64/x86/uart.o build-x86_64/x86/vmm.o build-x86_64/crt0.o build-x86_64/crt/crt0.o build-x86_64/sh build-x86_64/sh-/eval.o build-x86_64/sh-/parse.o build-x86_64/sh-/readline.o build-x86_64/sh-/sh.o build-x86_64/sh-/token.o build-x86_64/ld-snx.so build-x86_64/ld-snx/syscall.o build-x86_64/ld-snx/syscalls.o build-x86_64/ld-snx/elf-snx.o build-x86_64/ld-snx/ldso.o build-x86_64/ld-snx/pltstub.o build-x86_64/file.ko build-x86_64/modules/file.o build-x86_64/procmod.ko build-x86_64/modules/procmod.o build-x86_64/ls build-x86_64/user/ls.o build-x86_64/column build-x86_64/user/column.o build-x86_64/trace build-x86_64/user/trace.o build-x86_64/modsys build-x86_64/user/modsys.o build-x86_64/step build-x86_64/user/step.o build-x86_64/false build-x86_64/user/false.o build-x86_64/mmap build-x86_64/user/mmap.o build-x86_64/rm build-x86_64/user/rm.o build-x86_64/cat build-x86_64/user/cat.o build-x86_64/init build-x86_64/user/init.o build-x86_64/insmod build-x86_64/user/insmod.o build-x86_64/kill build-x86_64/user/kill.o build-x86_64/chmod build-x86_64/user/chmod.o build-x86_64/time build-x86_64/user/time.o build-x86_64/strace build-x86_64/user/strace.o build-x86_64/sleep build-x86_64/user/sleep.o build-x86_64/ab build-x86_64/user/ab.o build-x86_64/echo build-x86_64/user/echo.o build-x86_64/top build-x86_64/user/top.o build-x86_64/rot13 build-x86_64/user/rot13.o build-x86_64/xd build-x86_64/user/xd.o build-x86_64/create build-x86_64/user/create.o build-x86_64/args build-x86_64/user/args.o build-x86_64/uname build-x86_64/user/uname.o build-x86_64/true build-x86_64/user/true.o build-x86_64/bf2 build-x86_64/user/bf2.o build-x86_64/traceback build-x86_64/user/traceback.o

include $(shell find dep -name '*.d')
