//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: **
//Complier:  **
//File type: **
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
}

// PURPOSE: returns true if queue is full, otherwise false
bool isFull()
{}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void add(el_t newElem)
{}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void remove(el_t& removedElem)
{}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void frontElem(el_t& theElem)
{}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int getSize()
{}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void displayAll()
{}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void goToBack()
{// ** comment a local variable
}





