// =======================================================
// HW#: HW3P3 llist
// Your name: Ramzi El-abdallah
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: Return true if the list is empty, false otherwise
  //Parameters: No parameters
  bool isEmpty();
    
  //Purpose: Print all of the elements in the linked list
  //Parameters: No parameters
  void displayAll();

  //Purpose: Add an element to the front of the linked list
  //Parameters: Takes an element of type el_t
  void addFront(el_t NewNum);
    
  //Purpose: Add an element to the rear of the linked list
  //Parameters: Takes an element of type el_t
  void addRear(el_t NewNum);

  //Purpose: Removes an element from the front of the linked list
  //Parameters: Variable to store deleted element
  void deleteFront(el_t& delNum);
    
  //Purpose: Removes an element from the rear of the linked list
  //Parameters:Variable to store deleted element
  void deleteRear(el_t& delNum);
    
  //Purpose: Removes the element in the Ith position of the list
  //Parameters: Takes index of element to be deleted and Variable to store deleted element
  void deleteIth(int i, el_t& delNum);

  //Purpose: Adds element to the Ith position of list
  //Parameters: Takes in position to be added and item to be added
  void addbeforeIth(int i, el_t addNum);
    
};
