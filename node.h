/* Used llist.h as a template for my btree defs */

#ifndef btree_included		/* prevent multiple inclusion */
#define btree_included


/* a leaf for the btree */
typedef struct Node {
  struct Node *left;
  struct Node *right;
  char *fname;
  char *lname;
} Node;

/* create a new leaf */
Node *NAlloc();

/* free memory associated with btree, discarding all items it contains */
void bfree(Node *root);

/* append a leaf to btree */
Node * insert(Node *root, char *fname, char *lname);

/* Delete all elements from btree */
Node * delete(Node *root, char *fname, char *lname);

/* print btree */
void print(Node *root);

/* inOrder printing */
void inOrder(Node *root);

#endif	/* included */
