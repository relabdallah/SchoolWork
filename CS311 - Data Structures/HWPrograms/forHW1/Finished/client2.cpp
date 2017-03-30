//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Ramzi Elabdallah
//Complier:  g++ compiler
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: To generate all strings using A, B, C
//Algorithm: 
int main()
{
  // A, B, C in the queue
  queue q1;
  q1.add("A");
  q1.add("B");
  q1.add("C");
  string temp;
  string strloop[] = {"A","B","C"};

  while(true)
    {
      try
	{
	  for(int i = 0; i < 3; i++)
	    {
	      for(int j = 0; j < 3; j++)
		{
		  temp = strloop[i]+strloop[j];
		  q1.add(temp);
		}
	      q1.displayAll();
	    }
	  q1.displayAll();
        }
      catch(queue::Overflow)
	{
	  cerr << "ERROR: The queue has overflowed" << endl;
	  exit(EXIT_FAILURE);
	}
      catch(queue::Underflow)
	{
	  cerr << "ERROR: The queue has underflowed" << endl;
	  exit(EXIT_FAILURE);
	}
    }
  return 0;
}

