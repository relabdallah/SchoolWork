// =======================================================
// HW#: HW3P3 Extra Credit
// Your name: Ramzi El-abdallah
// Compiler:  g++ 
// File type: Extra Credit Client File
//=======================================================

#include <iostream>
#include "slist.h"

using namespace std;

//Purpose: Compares two lists to see if they are equivalent
//Parameters: Two lists passed by reference
void compare(slist& list1, slist& list2);

int main(){

  slist L1;
  slist L2;
  int count = 1;
  int temp;

  cout << "\nStep: " << count  << " L1 is empty and L2 is empty" << endl; count++;
  compare(L1, L2);
  
  cout << "\nStep: " << count << " - L1 is empty and L2 has 2 elements" <<  endl; count++;
  L2.addRear(1);
  L2.addRear(2);
  compare(L1, L2);
  
  cout << "\nStep: " << count << " - L1 has 2 elements and L2 is empty" << endl; count++;
  L1 = L2;
  L2.deleteRear(temp);
  L2.deleteRear(temp);
  compare(L1, L2);
  
  cout << "\nStep: " << count << " - L1 has 1,2,3 and L2 has 1,2,3" << endl; count++;
  L1.addRear(3);
  L2 = L1;
  compare(L1, L2);
  
  cout << "\nStep: " << count << " - L1 has 1,2,3 and L2 has 1,2" << endl; count++;
  L2.deleteRear(temp);
  compare(L1, L2);
  
  cout << "\nStep: " << count << " - L1 has 1,2,3 and L2 has 1,2,3,4" << endl; count++;
  L2.addRear(3);
  L2.addRear(4);
  compare(L1, L2);
  
  cout << "\nStep: " << count << " - L1 has 1,2,3 and L2 has 1,2,4" << endl; count++;
  L2.deleteIth(3, temp);
  compare(L1, L2);

  return 0;
}

//Purpose: Compares two lists to see if they are equivalent
//Parameters: Two lists passed by reference
void compare(slist& list1, slist& list2){
  cout << "Comparing List 1 with List 2" << endl;
  if (list1 == list2)
    cout << "Lists are the same." << endl;
  else
    cout << "Lists are not the same." << endl;
  
}
