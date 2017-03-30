//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: **
//Complier:  **
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.
  
Destructor  
- while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."

bool llist::isEmpty()
  - return true if Front and Rear are both pointing to NULL and Count is 0.
  - (all 3 conditions must be checked)

void llist::displayAll()
  - Special case: if the list is empty, display [ empty ] ).
  - Regular: 
    displays each element of the list horizontally starting from Front in [ ].
  
void llist::addRear(el_t NewNum) 
2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;

void llist::addFront(el_t NewNum)
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

void llist::deleteFront(el_t& OldNum)
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

void llist::deleteRear(el_t& OldNum)
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

void llist::deleteIth(int I, el_t& OldNum)
4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>

void llist::addbeforeIth(int I, el_t newNum)
4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>

