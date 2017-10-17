#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
  int sel = 0;
  printf("Welcome to ACME Personnel Management System\n\n");
  while(sel != 6)
    {
      printf("Please select an option:\n");
      printf("1: Add employee\n");
      printf("2: Delete employee\n");
      printf("3: Print employees\n");
      printf("4: Read from file\n");
      printf("5: Write to file\n");
      printf("6: Exit program\n>>");
      sel = getchar();

      char *fname;
      char *lname;
      
      if(sel == 1)
	{
	  printf("Please enter first name:\n");
	  gets(fname);
	  printf("Please enter last name:\n");
	  gets(lname);

	  
	}
      else if(sel == 2)
	{
	}
      else if(sel == 3)
	{
	}
      else if(sel == 4)
	{
	}
      else if(sel == 5)
	{
	}
      else if(sel == 6)
	{
	  quit();
	}
      else
	{
	  printf("Invalid option. Please select an value from 1 through 6.\n");
	}
    }
  return 0;
}
