//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: **
//Complier:  **
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: **
//Algorithm: **
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)

	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') result = box2-box1;
	      // ** also do the + and * cases 
	      // ** Finally push the result
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{** }
      catch (stack::Underflow) // for too few operands
	{** }
      catch (char const* errorcode) // for invalid item
	{** }
      // go back to the loop after incrementing i
      **
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
   **
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
   **

}// end of the program
