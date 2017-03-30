/*
HW: HW2P1
Name: Ramzi El-abdallah
Compiler Used: g++ Compiler
File Type: Binary Search Demo
*/

#include <iostream>

using namespace std;

int binarySearch(int array1[], int find, int first, int last);

//Purpose of Program: To conduct a binary search of a sorted  array of integers
//Algorithm Design: Uses a recursive binary search to quickly find an integer

int main()
{
  int myArray[] = {1,3,5,7,9,11,13,15,17,19};  //array set by user
  int searchFor, location;                     //searchFor number to search for and location=number returned from function
  int myfirst = 0;                                   //sets myfirst to first element of array
  int mylast = (sizeof (myArray)/ sizeof(int)) - 1;  //sets mylast to last element of array
  
  cout << "What number are you looking for?" << endl;
  cin >> searchFor;                                    //gets number to search for
  
  location = binarySearch(myArray, searchFor, myfirst, mylast);  //calls function to search for passing the array
  
  switch (location){                                  //checks location to see if item was found
  case -1:
    cout << "Your number was not found." << endl;     //if not found will output this message
    break;
  default:
    cout << "Your number was found in position " << location + 1 << endl;  //if found will output this message
  }
  
  return 0;
}

//Retrunts the location in the array of the found item else returns -1
int binarySearch(int array1[], int find, int first, int last)
{
  int middle = (first + last)/2;    //Sets middle to the center of array using
                                    //first and last element that were passed
  
  if(first == last && find != array1[middle])    //if first and last element are the same, last element reached
    return -1;                                   //returns -1 if item is not found

  cout << "Checking in slot " << middle + 1 << endl;  //displays slot that is being checked
  if(find == array1[middle]) return middle;           //if object to find is located, return middle
  else if(find < array1[middle]) last = middle - 1;   //if less than middle, set last to middle - 1, perform search again
  else if(find > array1[middle]) first = middle + 1;  //if if greater than middle, set first to middle + 1, perform search again
  return binarySearch(array1, find, first, last);     //recursive call
}
