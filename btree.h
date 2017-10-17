#ifndef btree
#define btree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

typedef struct Node
{
  struct Node *left;
  struct Node *right;
  char * fname;
  char * lname;
}Node;

#define pmalloc (Node *) malloc(sizeof(Node));
Node * populate_tree(Node * tree);
void addToFile(char * fname, char * lname);
Node * removeEmployee(Node * tree, char * fname, char * lname);
Node * insert(Node * tree, char * fname, char * lname);
// Node * newNode(char * fname, char * lname);
void printTree(Node * tree);
void freeTree(Node * tree);

#endif
