// =======================================================
// HW#: HW3P3 slist
// Your name: Ramzi El-abdallah
// Compiler:  g++ 
// File type: slist cpp file 
//=======================================================

#include "slist.h"
#include <iostream>

// non-member functions
//Purpose: Checks if two lists are equivalent
//Parameters: Takes in two lists passed by referece
bool operator==(const slist& left, const slist& right)
{
  if (left.Count != right.Count) //If they are not same length return false
    {
      return false;
    }

  //Pointers to current nodes
  Node *lCurr = left.Front;
  Node *rCurr = right.Front;
  
  while (lCurr)
    {
      if (lCurr->Elem != rCurr->Elem) //if current element is not equal, return false
	{
	  return false;
	}
      else                            //sets current pointer to next node
	{
	  lCurr = lCurr->Next;
	  rCurr = rCurr->Next;
	}
    }
  return true; //once all element are equal, return true
}

bool operator!=(const slist& left, const slist& right)
{
  return !(left == right);
}

// Member functions, operators, and constructors
// Constructs 
slist::slist(const slist& other)
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
  this->operator=(other);
}

slist& slist::operator =(const slist& other)
{
  if (&other != this) // No self duplicates
    {
      int foo = 0;
      while (!this->isEmpty())
	{
	  this->deleteRear(foo);
	}
      Node *lCurr = NULL, *lPrior = NULL;
      Node *rCurr = other.Front;
      
      Front = NULL; // In case it's empty
      while (rCurr)
	{
	  lCurr = new Node; 
	  lCurr->Elem = rCurr->Elem;
	  lCurr->Next = NULL;
	  
	  if (lPrior)
	    {
	      lPrior->Next = lCurr;
	    }
	  else // First node
	    {
	      Front = lCurr;
	    }
	  
	  Count++;
	  lPrior = lCurr;
	  rCurr = rCurr->Next;
	}
      Rear = lCurr;
      
    }
  return *this;
}

// Purpose: Searches the list for an element passed by the client
// Parameters: find is the item that is being searched for
int slist::search(el_t find) const
{
  Node *temp = Front; //temporary node that goes through the list
  int index = 1;
  while (temp)        //while temp has a value
    {
      if (temp->Elem == find) //if the element in the current node is equal to find, return index
	{
	  return index;
	}
      temp = temp->Next;  //goes to next node
      index++;            //incriment index
    }
  return 0;
}

// Purpose: Replaces an element in a requested slot in the list
// Parameters: Pass Elem(the replacement element), slot (index of element to be replaced)
void slist::replace(el_t Elem, int slot)
{
  if (slot < 1 || slot > Count)  //if the slot is larger or smaller than size of list, throw error
    {
      throw OutOfRange();
    }
  else if (isEmpty()) //throws underflow if list is empty
    {
      throw Underflow();
    }
  else
    {
      int index = 1;
      Node *temp = Front;
      while (index != slot)  //finds the slot to be replaced
	{
	  temp = temp->Next;
	  index++;
	}
      temp->Elem = Elem;  //replaces the element with new element
    }
}
