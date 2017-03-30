// =======================================================
// HW#: HW3P2 slist
// Your name: Ramzi El-abdallah
// Compiler:  g++ 
// File type: slist header file 
//=======================================================

#include "llist.h"

class slist : public llist
{
   public:
      // Purpose: slist constructor, calls parent constructor
      slist() : llist() {};
      slist(const slist&);
      
      // slist Destructor
      ~slist() {};

      // Purpose: Searches the list for an element passed by the client
      // Parameters: find is the item that is being searched for
      int search(el_t find) const;
      
      // Purpose: Replaces an element in a requested slot in the list
      // Parameters: Pass Elem(the replacement element), slot (index of element to be replaced)
      void replace(el_t Elem, int slot);
};
