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

void bfree(Node *root)
{
  bfree(root->left);
  free(root);
  bfree(root->right);
}

Node* delete(Node *root, char *fname, char *lname)
{
  if(root == NULL)
    {
      printf("Tree is empty.");
      return NULL;
    }

  Node *current;

  // traverse left
  if(strcmp(lname, root->lname) < 0)
    {
      root->left = delete(root->left, fname, lname);
    }
  // traverse right
  else if(strcmp(lname, root->lname) > 0)
    {
      root->right = delete(root->right, fname, lname);
    }
  // found lname, check fname
  else if(strcmp(lname,root->lname) == 0)
    {
      // traverse left
      if(strcmp(fname,root->fname) < 0)
	{
	  root->left = delete(root->left, fname, lname);
	}
      // traverse right
      else if(strcmp(fname,root->fname) > 0)
	{
	  root->right = delete(root->right, fname, lname);
	}
      // found node
      else if(strcmp(lname,root->lname) == 0 && strcmp(fname,root->fname) == 0)
	{
	  if(root->left == NULL)
	    {
	      current = root->right;
	      free(root);
	      root = current;
	    }
	  else if(root->right == NULL)
	    {
	      current = root->left;
	      free(root);
	      root = current;
	    }

	  /* if there are both left and right nodes */
	  else
	    {
	      current = root->right;
	      Node *temp;
	      
	      while(current->left != NULL)
		{
		  temp = current; // temporary holder for parent node
		  current = current->left; // node to swim up
		}

	      /* leaf swims up */
	      root->fname = current->fname;
	      root->lname = current->lname;

	      /* left node being deleted  */
	      if(temp != NULL)
		{
		  temp->left = delete(temp->left, temp->left->fname, temp->left->lname);
		}
	      /* right node being deleted */
	      else
		{
		  root->right = delete(root->right, root->right->fname, root->right->lname);
		}
	    }
	}
      else
	{
	  printf("Employee not found.\n");
	}
    }
  return root;
}

Node* insert(Node *root, char *fname, char *lname)
{
  if(root == NULL)
    {
      Node * temp = NAlloc();
      temp->fname = fname;
      temp->lname = lname;
      root = temp;
    }
  else
    {
      Node * current = root;

      while(current != NULL)
	{
	  if(strcmp(lname,current->lname) < 0)
	    {
	      current->left = insert(current->left, fname, lname);
	    }
	  else if(strcmp(lname,current->lname) > 0)
	    {
	      current->right = insert(current->right, fname, lname);
	    }
	  else if(strcmp(lname,current->lname) == 0)
	    {
	      if(strcmp(fname,current->fname) < 0)
		{
		  current->left = insert(current->left, fname, lname);
		}
	      else if(strcmp(fname, current->fname) > 0)
		{
		  current->right = insert(current->right, fname, lname);
		}
	    }
	}
    }
  
  return root;
}

// will print in-order
void print(Node *root)
{
  if(root == NULL)
    {
      printf("Tree is empty!\n");
      return;
    }
  else
    {
      inOrder(root);
    }
}

 void inOrder(Node *root)
 {
   inOrder(root->left);
   printf("Employee: %s, %s", root->lname, root->fname);
   inOrder(root->right);
 }
