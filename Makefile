
all: bfuck

bfuck: bfuck.o
	gcc -o bfuck bfuck.o

bfuck.o: bfuck.c
	gcc -c bfuck.c

clean:
	rm *.o bfuck

