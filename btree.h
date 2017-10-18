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
  char fname[21];
  char lname[21];
}Node;

#define pmalloc (Node *) malloc(sizeof(Node));
Node * populate_tree(Node * tree);
void writeTree(Node * tree, char * filename);
void wHelper(Node * tree, FILE * file);
Node * delete(Node * tree, char * fname, char * lname);
Node * insert(Node * tree, char * fname, char * lname);
void printTree(Node * tree);
void freeTree(Node * tree);

extern Node * tree;

#endif
