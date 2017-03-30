// =========================================================
//HW#: HW6 DGRAPH
//Your name: Ramzi El-abdallah
//Complier:  g++ compiler
//File type: DGraph header file
//==========================================================


#include <iostream>
#include <string>
#include "slist.h"
#include "stack.h"

using namespace std;

//Max size of the table
const int MAX_SIZE = 20;


class dgraph
{
 protected:
  struct Gvertex
  {
    char name;
    int mark;
    int out_degree;
    slist adj_list;
  };
  
  Gvertex Gtable[MAX_SIZE];
  
  int count;
  
 public:
  // Public constructor/destructor.
  dgraph();
  ~dgraph();
  
  // Exception class
  class VertexNotFound {};
  
  // Member functions
  void fillTable();
  void displayGraph();
  void displayVisit();
  int findOutDegree(char vertex_name);
  slist findAdjacencyList(char vertex_name);
  void visit(int, char);
  bool isMarked(char);
};
