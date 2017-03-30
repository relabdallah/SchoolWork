// ====================================================
//HW#: HW3P1 llist
//Your name: Ramzi El-abdallah
//Complier:  g++ compiler
//File type: llist implementation file
//=====================================================

#include <iostream>
#include "llist.h"

using namespace std;

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist(){
  Count = 0;
  Front = NULL;
  Rear = NULL;
}

  
//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
llist::~llist(){
  Node *temp;
  while (this->Front) // While we still have an element
    {
      temp = this->Front; // Store the current front in temp
      this->Front = this->Front->Next; // Move forward once
      delete temp; // Delete the prior front
    }
  Count = 0;
}

bool llist::isEmpty(){
  if (Count == 0)
    return true;
  else
    return false;
}
  // - return true if Front and Rear are both pointing to NULL and Count is 0.
  // - (all 3 conditions must be checked)

void llist::displayAll(){
  if (Front == NULL){
    cout << "[empty]" << endl;
    return;
  }
  int tempCount = Count; //tempCount created so count is not updated
  Node *disp = Front;
  while(tempCount != 0){ //goes through linked list and displays elements 
    cout << "[" << disp->Elem << "]";
    disp = disp->Next;
    tempCount--;
  }
  cout << endl;
}
//- Special case: if the list is empty, display [ empty ] ).
//- Regular: 
//displays each element of the list horizontally starting from Front in [ ].

void llist::addRear(el_t NewNum){
  if(Count == 0){  //case that list is empty
    Node *addNode = new Node;
    addNode->Elem = NewNum;
    addNode->Next = NULL;
    Front = Rear = addNode;
  }
  else{ 
    Rear->Next = new Node; // new Node to add to rear
    Rear = Rear->Next;     //makes new Node rear
    Rear->Elem = NewNum;   // adds element
    Rear->Next = NULL;     
  }
  Count++;
} 
/*
//2 cases:
// - Special case: if this is going to be the very first node, you must
//create a new node and make Front and Rear point to it. Place NewNum and
//Count is updated.
//- Regular: adds a new node at the rear and puts NewNum in the Elem field
//of this new node. Count is updated.
//Regular case:
//  Rear->Next = new Node;
//Rear = Rear->Next;
//Rear->Elem = NewNum;
//Rear->Next = NULL;
*/

void llist::addFront(el_t NewNum){
  if(Count == 0){
    Node *addNode = new Node;
    addNode->Elem = NewNum;
    addNode->Next = NULL;
    Front = Rear = addNode;
  }
  else{
    Node *x;
    x = new Node;
    x->Next = Front;
    Front = x;
    Front->Elem = NewNum;
  }
  Count++;
}
/*
2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum and
   Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.
  Regular case:
  Node *x;
  x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;
*/

void llist::deleteFront(el_t& OldNum){
  if(Count == 0)
    throw Underflow();
  else if(Count == 1){
    OldNum = Front->Elem;
    Node *Second = Front;
    Front = Front->Next;
    Rear = Front;
    delete Second;
  }
  else{
    OldNum = Front->Elem;
    Node *Second;
    Second = Front->Next;
    delete Front;
    Front = Second;
  }
  Count--;
}
/*
3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
*/

void llist::deleteRear(el_t& OldNum){
  if(Count == 0)   //case for empty linked list
    throw Underflow();
  else if(Count == 1){
    OldNum = Front->Elem;
    Node *Second = Front;
    Front = Front->Next;
    Rear = Front;
    delete Second;
    Count--;
  }
  else{
    OldNum = Rear->Elem;
    Node *p = Front;
  while(p->Next->Next != NULL)
    p = p->Next;
  delete p->Next;
  p->Next = NULL;
  Rear = p;
  Count--;
  }
}

/*
 3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p;
*/

void llist::deleteIth(int I, el_t& OldNum){
  if (I < 1 || I > Count){
      throw OutOfRange();
    }
  else if (isEmpty()){
      throw Underflow();
    }
  else if (I == 1){
      deleteFront(OldNum);
    }
  else if (I == Count){
      deleteRear(OldNum);
    }
  else{
    int index = 1;
    Node *search;
    Node *holder;
    holder = Front;
    search = Front;
    while(index != I){
      holder = search;
      search = search->Next;
      index++;
    }
    holder->Next = search->Next;
    OldNum = search->Elem;
    delete search;
    Count--;
  }
}
/*
4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
*/

void llist::addbeforeIth(int I, el_t newNum){
  
  if (I < 1 || I > Count + 1){
    throw OutOfRange();
  }
  else if (I == 1){
    addFront(newNum);
  }
  else if (I == Count+1){
    addRear(newNum);
  }
  else{
    int index = 1;
    Node *search;
    Node *holder;
    holder = Front;
    search = Front;
    while(index != I){
      holder = search;
      search = search->Next;
      index++;
    }
    Node *temp = new Node;
    temp->Next = search;
    temp->Elem = newNum;
    holder->Next = temp;
    Count++;
  }
}
/*
4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
*/
