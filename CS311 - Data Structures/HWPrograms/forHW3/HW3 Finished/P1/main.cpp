#include <iostream>
#include "llist.h"

using namespace std;

int main()
{
  llist test;
  int num;
  int hold =  10;
  cout << "enter a number" << endl;
  cin >> num;
   test.addFront(num);
  test.displayAll();
  return 0;
}
