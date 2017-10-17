#include "btree.h"

int main()
{
  char sentinel = '6';
  char * name1 = (char *) malloc(sizeof(21));
  char * name2 = (char *) malloc(sizeof(21));
  // Node * tree = NULL;
  
  do
    {
      printf("Welcome to ACME Solutions Personnel Management System\n");
      printf("\nPlease select one of the following options:\n");
      printf("1: Add employee to list\n");
      printf("2: Remove employee from list\n");
      printf("3: List all employees\n");
      printf("4: Read employees from file\n");
      printf("5: Write employees to file\n");
      printf("0: Exit program\n");
      
      sentinel = getchar();
      
      switch(sentinel)
	{
	case '0':
	  getchar();
	  printf("Thank you, goodbye.\n");
	  break;
	  
	case '1':
	  getchar();
	  printf("Please enter employee first name:\n");
	  fgets(name1, 21, stdin);
	  printf("Please enter employee last name:\n");
	  fgets(name2, 21, stdin);
	  tree = insert(tree, name1, name2);
	  break;

	case '2':
	  printf("Please enter employee first name:\n");
	  getchar();
	  fgets(name1, 21, stdin);
	  printf("Please enter employee last name:\n");
	  fgets(name2, 21, stdin);
	  tree = delete(tree, name1, name2);
	  printf("Deleting employee...\n");
	  
	  break;

	case '3':
	  getchar();
	  printTree(tree);
	  printf("\n");
	  break;

	case '4':
	  tree = populate_tree(tree);
	  break;

	case '5':
	  break;

	default:
	  break;
	}
    }while(sentinel != '0');
}
