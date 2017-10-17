#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

Node *NAlloc()
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = node->right = NULL;
  return node;
}

void bfree(Node *node)
{
  
}

void delete(Node *node)
{
  
}

Node* insert(Node *root, char *fname, char *lname)
{
  Node *temp = NAlloc();
  temp->fname = fname;
  temp->lname = lname;

  if(root == NULL)
    {
      root = temp;
    }
  else
    {
      Node * current = root;

      while(current != NULL)
	{
	  if(strcmp(lname,current->lname) < 0)
	    {
	      current = current->left;
	    }
	  else if(strcmp(lname,current->lname) > 0)
	    {
	      current = current->right;
	    }
	}
      
      if(strcmp(lname,current->lname) < 0)
	{
	  current->left = temp;
	}
      else
	{
	  current->right = temp;
	}
    }

  return root;
}

// will print in-order
void print(Node *node)
{
  if(node == NULL)
    {
      printf("Tree is empty!\n");
      return;
    }

  printf("Employee: %s, %s", node->lname, node->fname);

  print(node->left);
  print(node->right);
}
