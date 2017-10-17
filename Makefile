all: project1

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

project1: btree.o main.o
	cc -o $@ $^

btree.o: btree.c btree.h
	cc -c $(CFLAGS) btree.c

main.o: main.c btree.h
	cc -c $(CLFAGS) main.c

clean:
	rm -f *.o project1 *.*~
