// =======================================================
// HW#: HW3P2 slist
// Your name: Ramzi El-abdallah
// Compiler:  g++ 
// File type: slist cpp file 
//=======================================================

#include "slist.h"
#include <iostream>

//constructor
slist::slist(const slist& other)
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
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
