//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Ramzi Elabdallah
//Complier:  g++ compiler
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  count = 0;
  front = 0;
  rear = 0;
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0) return true;
  else return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if (count == MAX_SIZE) return true;
  else return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t elem)
{
  if(isFull())
    throw Overflow();
  else
    {
      el[rear] = elem;
      count++;
      rear = (rear + 1) % MAX_SIZE;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& elem)
{
  if(isEmpty())
    throw Underflow();
  else
    {
      elem = el[front];
      count--;
      front = (front + 1) % MAX_SIZE;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& elem)
{
  if(isEmpty())
    throw Underflow();
  else
    {
      elem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return(count);
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
  if(isEmpty())
    cout << "[empty]" << endl;
  else
    {
      int i = front;
      cout << "[";

      do
	{
	  cout << el[i] << ", ";
	  i = (i+1) % MAX_SIZE;
	} while(i != rear);
      cout << "]" << endl;
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
  if(isEmpty())
    throw Underflow();
  else if(getSize() == 1)  //nothing to do
    {}
  else
    {
      el_t gtbElem;   //local variable
      remove(gtbElem);
      add(gtbElem);
    }
}





