all: bTree

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bTree: btree.o btdemo.o
	cc -o $@ $^

btree.o: btree.c node.h
	cc -c $(CFLAGS) btree.c

btdemo.o: btdemo.c node.h
	cc -c $(CLFAGS) btdemo.c

clean:
	rm -f *.o bTree *.*~

