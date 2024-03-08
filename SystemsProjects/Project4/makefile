# This makefile is used as follows to regenerate files for the race program:
#   make test_rational.o   --  Regenerates test_rational.o by compiling
#   make rational.o   --  Regenerates rational.o by compiling
#   make coffee_shop.o -- Regenerates coffee_shop.o by compiling
#   make register     --  Regenerates the executable register file by compiling
#   make              --  Same as "make register"
#

run_simulation: shopQueue.o simulation.o
	g++ -g -Wall shopQueue.o simulation.o -o run_simulation

shopQueue.o: customer.h shopQueue.h shopQueue.cpp
	g++ -g -Wall -c shopQueue.cpp

simulation.o: customer.h shopQueue.h simulation.cpp
	g++ -g -Wall -c simulation.cpp

clean:
	rm -f shopQueue.o simulation.o run_simulation

all: run_simulation 