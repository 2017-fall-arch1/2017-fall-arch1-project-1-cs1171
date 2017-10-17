#include "btree.h"

char * filename = "pms.txt";
Node * tree = NULL;

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
      memcpy(temp->lname,lname, 20);
      memcpy(temp->fname, fname, 20);
      return temp;
    }
  // left/right branch control
  // checks last name. if less adds to left, if greater
  // adds to right branch.
  if(strcmp(lname, tree->lname) < 0)
    {
     tree->left = insert(tree->left, fname, lname);
    }
  else if(strcmp(lname, tree->lname) > 0)
    {
      tree->right = insert(tree->right, fname, lname);
    }
  return tree;
}

// will print tree in-order
void printTree(Node * tree)
{
  int len;
  
  if(tree == NULL)
    {
      return;
    }
  
  printTree(tree->left);
  printf("Employee: %s%s", tree->fname, tree->lname);
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
Node * delete(Node * tree, char * fname, char * lname)
{
  Node * temp;

  if(tree == NULL)
    {
      printf("Tree is empty.");
      return NULL;
    }

  // traverse left
  if(strcmp(lname, tree->lname) < 0)
    {
     tree->left = delete(tree->left, fname, lname);
    }
  // traverse right
  else if(strcmp(lname, tree->lname) > 0)
    {
      tree->right = delete(tree->right, fname, lname);
    }
  // found employee
  else
    {
      // swim right leaf up
      if(tree->left == NULL)
	{
	  temp = tree->right;
	  free(tree);
	  tree = temp;
	}
      // swim leaf leaf up
      else if(tree->right == NULL)
	{
	  temp = tree->left;
	  free(tree);
	  tree = temp;
	}
      /* if left and right nodes are not null */
      else
	{
	  temp = tree->right;
	  Node * temp2 = NULL;
	  while(temp->left != NULL)
	    {
	      temp2 = temp;
	      temp = temp->left;
	    }
	  memcpy(temp->fname,tree->fname,20);
	  memcpy(temp->lname,tree->lname,20);
	  if(temp2 != NULL)
	    {
	      temp2->left = delete(temp2->left, temp2->left->fname, temp2->left->lname);
	    }
	  else
	    {
	      tree->right = delete(tree->right, tree->right->fname, tree->right->lname);
	    }
	}
    }
  return tree;
}
