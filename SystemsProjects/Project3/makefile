# This makefile is used as follows to regenerate files for the race program:
#   make coffee_shop.o   --  Regenerates coffee_shop.o by compiling
#   make register.o   --  Regenerates register.o by compiling
#   make coffee_shop.o -- Regenerates coffee_shop.o by compiling
#   make register     --  Regenerates the executable register file by compiling
#   make              --  Same as "make register"
#

rational_math: rational.o test_rational.o
	gcc -g -Wall rational.o test_rational.o -o rational_math

rational.o: rational.h rational.c
	gcc -g -Wall -c rational.c

test_rational.o: rational.h test_rational.c
	gcc -g -Wall -c test_rational.c

clean:
	rm -f rational.o test_rational.o rational_math

all: rational_math input.txt output.txt