# This makefile is used as follows to regenerate files for the race program:
#   make coffee_shop.o   --  Regenerates coffee_shop.o by compiling
#   make register.o   --  Regenerates register.o by compiling
#   make register     --  Regenerates the executable register file by compiling
#   make              --  Same as "make register"
#

register: coffee_shop.o register.o
	gcc -g -Wall coffee_shop.o register.o -o register

coffee_shop.o: register.h coffee_shop.c
	gcc -g -Wall -c coffee_shop.c

register.o: register.h register.c
	gcc -g -Wall -c register.c

clean:
	rm -f coffee_shop.o register.o register

all: register