exec = test.out
sources = $(wildcard src/*.c)
sources += $(wildcard ../src/*.c)
sources_no_main := $(filter-out ../src/main.c, $(sources))
objects = $(sources_no_main:.c=.o)
flags = -g -Wall -I../../cmocka/include -ldl -lm -lcmocka


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
