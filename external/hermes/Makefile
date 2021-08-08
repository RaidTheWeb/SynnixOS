exec = hermes.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -std=c99 -static
cc = ~/.local/bin/x86_64-synnixos-gcc
sysusr = ~/SynnixOS/sysroot/usr

$(exec): $(objects)
	$(cc) $(objects) $(flags) -o $(exec)

libhermes.a: $(objects)
	ar rcs $@ $^

%.o: %.c include/%.h
	$(cc) -c $(flags) $< -o $@

install:
	make
	make libhermes.a
	mkdir -p $(sysusr)/include/hermes
	cp -r ./src/include/* $(sysusr)/include/hermes/.
	cp ./libhermes.a $(sysusr)/lib/.
	cp ./hermes.out $(sysusr)/bin/hermes

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm src/*.o

lint:
	clang-tidy src/*.c src/include/*.h
