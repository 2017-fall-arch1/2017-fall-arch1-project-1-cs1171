This directory contains files which will:

1. Allow the creation of a binary search tree.
2. Allow the maniuplation of the tree, including adding nodes,
   printing in-order, deletion of nodes, and deletion of tree.
3. A main file which will provide a user interface to
   add and delete employees from tree. Will also read
   and write employee names to a file.


btree.h: provides definitions for node creation, deletion,
freeing all nodes, and printing all nodes. It also has
a definition for the Node struct. I used llist.h as a template
for my node.h file.

btree.c: has the actual code for the definitions created
in btree.h.

main.c: cotains the code for a user interface which allows
the addition and deletion of employee names to a btree. Also
can read/write names to a text file.

Makefile: 'make' will compile all files into 'project1'.
Running project1 will start the program. The user interface
will list options: 1: to add an employee, 2: to delete an
employee, 3: to print tree, 4: to load names from file,
5: to write names to file, 0: to exit program.

'make clean' will delete everything created by 'make'
(.o files and project1).