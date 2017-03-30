//Ramzi El-abdallah
//Assignment 2: Fork Process
//CS433
//September 29, 2016

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv){

  int num = atoi(argv[1]);	//value to hold command line input
  int size = strlen(argv[1]);//gets length of command line input
  
  //Checks to see if first character of input is "-" to see if it is negative
  if (argv[1][0] == '-')
    {
      fprintf(stderr, "Invalid Entry: Negative Number.\n");
      return 0;
    }
  
  //loops through the string and checks for non numerical input using isdigit()
  for(int i=0; i < size; i++)
    {
      if(isdigit(argv[1][i]) == 0)
	{
	  fprintf(stderr, "Invalid Entry: Non-Integer Digit Encountered.\n");
	  return 0;
	} 
    }
  
  pid_t pid;
  pid = fork();
  
  //Child Process failed to start
  if(pid < 0)
    {
      fprintf(stderr, "Fork Failed.\n");
      return 1;
    }
  
  //Child Process Execution
  else if(pid == 0)
    {
      printf("%d", num);
      while(num != 1){
	if(num%2 != 0)
	  {
	    num = (num*3)+1;
	  }
	else if(num%2 == 0)
	  {
	    num = num/2;
	  }
	printf(", %d",num);
      }
      printf("\n");
    }
  
  //Parent Process
  else
    {
      wait(NULL);
      printf("Child Process Complete.\n");
    }

  return 0;
}
