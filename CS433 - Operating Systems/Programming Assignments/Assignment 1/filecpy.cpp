// ====================================================
// Ramzi El-abdallah
// Programming Assignment 1
// Description: Simple File Copy Using System Calls
// September 15, 2016
// CS433 - Operating Systems Sect. 42361
//=====================================================


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 1000

int main(int argc, char **argv)
{
  
  int fd1, fd2; //File Descriptors for the read and write files
  char buffer[BUF_SIZE]; //Character array to hold data from read file, size determined by BUF_SIZE

  //Checks to see if command was entered correctly, if not prints error to screen
  if(argc != 3)
    {
      fprintf(stderr, "Invalid command.\n");
      return 0;
    }

  //Assigns first file to it's file descriptor and sets it as read only
  //Open returns -1 if file not found and error is printed to screen
  fd1 = open(argv[1], O_RDONLY);
  if(fd1 == -1)
    {
      fprintf(stderr, "Error: File not found.\n");
      return 0;
    }

  //Creates and opens second file, assigns it to it's file descriptor. Sets as write only.
  //Open returns -1 if file not found and error is printed to screen
  fd2 = open(argv[2], O_WRONLY | O_CREAT, 1000);
  if(fd2 == -1)
    {
      fprintf(stderr, "Error: Cannot creat file.\n");
      return 0;
    }

  //Sizes of fd1 and fd2
  ssize_t sizeFd1, sizeFd2;

  //Loop the writes from the buffer to the new file
  //Stays reading and writing until there is nothing left to read
  while((sizeFd1 = read (fd1, &buffer, BUF_SIZE)) > 0)
    {
      sizeFd2 = write (fd2, &buffer, (ssize_t) sizeFd1);
      if(sizeFd2 != sizeFd1)
	{
	  fprintf(stderr, "Error writing file.\n");
	  return 0;
	}
    }

  //Closes both files
  close (fd1);
  close (fd2);
  
  return 0;
}
