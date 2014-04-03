
CFLAGS = -O3 -Wall -ansi

all: bfuck

bfuck: bfuck.o
	$(LINK.c) -o bfuck bfuck.o

clean:
	rm -f *.o bfuck
