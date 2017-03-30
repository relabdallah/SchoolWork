//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Ramzi Elabdallah
//Complier:  g++ compiler
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: Create an application for computing postfix expressions
//Algorithm: Push numbers onto the stack until an operator is
// reached in which the numbers are popped off an then computed
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
  int result;

  char temp1;
  char temp2;
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  if(item >= '0' && item  <= '9')
	    {
	      postfixstack.push(item);
	    }
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(temp1);
	      postfixstack.pop(temp2);

	      box1 = (int)temp1;
	      box2 = (int)temp2;
	      //cases for different operators follow:
	      if (item == '-') result = (box2-48)-(box1-48);
	      if (item == '+') result = (box2-48)+(box1-48);
	      if (item == '*') result = (box2-48)*(box1-48);
	      postfixstack.push((char)(result + 48));
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cerr << "Error has occured: Stack has overflowed"; exit(1); }
      catch (stack::Underflow) // for too few operands
	{cerr << "Error has occured: Stack has underflowed"; exit(1); }
      catch (char const* errorcode) // for invalid item
	{ }
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  cout << "The result of the expression is " << result << endl;
  postfixstack.pop(temp1);
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
    if(postfixstack.isEmpty() == false)
     {
       cerr << "Error: Incomplete expression." << endl;
     }

}// end of the program
