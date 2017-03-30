/*
HW#: HW2P2
Name: Ramzi El-abdallah
Compiler used: g++ compiler
File Type: Combine client file
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Declaring the methods of the file
void combine(vector<int> & A, vector<int> & B, vector<int> & R, int totalSize);
int convertString(const string & s, vector <int> & v );


int main()
{
  vector <int> L1, L2, L3; //Declaring vectors that will hold integers
  string input, input2;    //input and input 2 will hold the user input
  int L1size, L2size;      //Will hold the size of vectors L1 and L2
  
  cout << "Enter integers into L1 in increasing order separated by a space: " << endl;
  getline(cin, input);
  L1size = convertString(input, L1);  //converts string into integers and places them into vector
  
  cout << "Enter integers into L2 in increasing order separated by a space: " << endl;
  getline(cin, input2);
  L2size = convertString(input2, L2);

  int size = L1size + L2size;  //size of L3 vector
  combine(L1, L2, L3, size);   //calls combine function

  cout << " The combined vector is: [";

  for (int i = 0; i < L3.size(); i++)    //loop to print out contents of combined vector L3
    {
      cout << L3[i] << " ";
    }
  cout << "]" << endl;

  return 0;
}


//Purpose: Takes in 2 sorted vectors and sorts them into a combined sorted vector
//Parameters: The vectors that need to be sorted A and B, and the vector R they are going into
//            and the size that vector R will be. All vectors are passed by reference
void combine(vector<int> & A, vector<int> & B, vector<int> & R, int totalSize)
{
  int ia = 0, ib = 0, ir = 0; // index for each vector

  while(ia < A.size() && ib < B.size())
    {
      cout << "Comparing " << A[ia] << " and " << B[ib] << endl; //Dispays which elements are being compared
      
      if(A[ia] < B[ib]){            //if element in A is less than element in B, pushes element onto R
	R.push_back(A[ia]);
	ia++;                       //increments the indexes
	ir++;
      }
      else{
	R.push_back(B[ib]);         //if element in B is less than element in A, pushes element onto R
	ib++;
	ir++;
      }
    }
      if (A.size() == ia){
	for(int i = R.size(); i < totalSize; i++){    //adds the remaining elements of A or B if on of them is empty
	R.push_back(B[ib]);
	ib++;
	ir++;}
      }
      if (B.size() == ib){
	for(int i = R.size(); i < totalSize; i++){
	R.push_back(A[ia]);
	ia++;
	ir++;}
	}
    

}

//Purpose: Method that streams through a string and pulls out integers into a vector
//Parameters: A string and a vector are passed by reference and size of vector is returned
int convertString(const string & str1, vector <int> & v )
{
    istringstream is(str1);
    int n;
    while( is >> n ) //as it finds itegers in the string it is pushing them onto the vector
      {
    	v.push_back( n );
      }
    return v.size();
}
