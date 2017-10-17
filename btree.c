#include "btree.h"

char * filename = "pms.txt";

// add employee to file
void addToFile(char * first_name, char * last_name)
{
  FILE * file = fopen(filename, "a");

  // catch any file errors
  if(!file)
    {
      printf("%s\n", strerror(errno));
      exit(1);
    }
  printf("Adding employee to file...\n\n");
  fprintf(file, "%s", first_name);
  fprintf(file, "%s", last_name);
  fclose(file);
}

// test all functions
int test_everything()
{
  Node * tree = NULL;
  tree = populate_tree(tree);
  printTree(tree);
  freeTree(tree);
}

// read from file and pass to tree creator
Node * populate_tree(Node * tree)
{
  FILE *file = fopen(filename, "rt");
  Node * current = NULL;
  
  // catch any file errors
  if(!file)
    {
      printf("Error opening file\n%s\n", strerror(errno));
      exit(1);
    }
  current = pmalloc;
  // reading names
  while(fscanf(file, "%20s", current->fname) > 0)
    {
      fscanf(file, "%20s", current->lname);
      // testing fscanf
      // printf("%s %s\n", current->first_name, current->last_name);
      tree = insert(tree, current->fname, current->lname);
    }

  fclose(file);
  
  return tree;
}

// add nodes to binary tree
Node * insert(Node * tree, char * fname, char * lname)
{
  if(tree == NULL)
    {
      Node * temp;
      temp = pmalloc;
      temp->fname = fname;
      temp->lname = lname;
      return temp;
    }
  // left/right branch control
  // checks last name. if less adds to left, if greater
  // adds to right branch.
  if(strcmp(lname, tree->lname) < 0)
    {
      printf("GOING LEFT\n");
      tree->left = insert(tree->left, fname, lname);
    }
  else if(strcmp(lname, tree->lname) > 0)
    {
      printf("GOING RIGHT\n");
      tree->right = insert(tree->right, fname, lname);
    }
  return tree;
}

// will print tree in-order
void printTree(Node * tree)
{
  if(tree == NULL)
    {
      return;
    }
  printTree(tree->left);
  printf("%s %s", tree->fname, tree->lname);
  printTree(tree->right);
}

// frees nodes from memory
void freeTree(Node * tree)
{
  if(tree == NULL)
    {
      return;
    }
  freeTree(tree->left);
  free(tree);
  freeTree(tree->right);
}

// remove employee from tree
Node * removeEmployee(Node * tree, char * fname, char * lname)
{
  
}
