// =========================================================
//HW#: HW7P2 DGRAPH
//Your name: Ramzi El-abdallah
//Complier:  g++ compiler
//File type: Client File
//==========================================================


#include <iostream>
#include "dgraph.h"

using namespace std;

void checkVisit(dgraph& graph, stack& stk, char vertexData, int& visitMark);
void checkAdjacent(dgraph& graph, stack& stk, char vertexData);

int main()
{
  /*
  char vertex1;  // Receive characters from pop
  int visitMark = 1;  // Track the visit order number
  
  dgraph graph1; //Primary table
  stack stack1;  //Stack to hold Adjcenct vertices

  //filling the table with table.txt
  cout << "*Now filling table*" << endl;
  graph1.fillTable();

  //Displaying table before DFS
  graph1.displayGraph();

  //Begins DFS with A
  cout << endl << "Beginning with A" << endl;
  checkVisit(graph1, stack1, 'A', visitMark);
  
  //While loop goes through stack and checks elements untill the stack is empty
  
  while(!stack1.isEmpty())

  {

    stack1.pop(vertex1);  //Pops the top element off the stack, stores it into vertex_elem

    cout << endl << "Pop " << vertex1;  //Displays popped element

    //Checks is marked in CheckVisit method
    //Elements get pushed and popped until stack is empty and DFS is complete
    checkVisit(graph1, stack1, vertex1, visitMark);

  } 

  //Display the Graph with visit numbers for all vertices.

  cout << endl << "Elements and their Visit Numbers" << endl;
  graph1.displayVisit();

  cout << "Goodbye!" << endl;
  */

  char vertex1;  
  int visitMark = 1;  
  
  dgraph dg1;  
  stack vtx1;
  
  
  cout << "*Now filling table*" << endl; 
  dg1.fillTable();

  cout << "\nDisplaying graph before DFS begins...." << endl;
  dg1.displayGraph();
  
  cout << "\n\nBegin DFS with A...." << endl;
  checkVisit(dg1, vtx1, 'A', visitMark);

  
  while(!vtx1.isEmpty())
  {
    vtx1.pop(vertex1);  
    cout << "\nPop " << vertex1; 
    checkVisit(dg1, vtx1, vertex1, visitMark);
  }
  
  cout << "\n\nDisplaying graph for all vertices by order of visit..." << endl;
  dg1.displayVisit();
  
  cout << "\nThanks! It's been a great semester." << endl;
  
  return 0;
}

void checkVisit(dgraph& graph, stack& stk, char vertexData, int& visitMark)
{
  if(!graph.isMarked(vertexData))
  {    
    graph.visit(visitMark, vertexData);
    cout << "Adding Mark." << endl;
    visitMark++;

    // Test if the vertex has any adjacencies
    checkAdjacent(graph, stk, vertexData);
  }

  else
  {
    cout << endl << "Element " << vertexData << " has been visited already." << endl;
  }
}

//Checks for adjacencies and pushes thos elements onto the stack
void checkAdjacent(dgraph& graph, stack& stk, char vertexData)

{
  //Out Degree from findOutDegree()
  int outDegree = 0;
  
  //List to store adjacency list
  slist alist = graph.findAdjacencyList(vertexData); 

  // Check if adjacency list is empty. If not, then push list onto stack.
  if(!alist.isEmpty())
  {
    outDegree = graph.findOutDegree(vertexData)-1; // Determine the start index
    cout << "Pushing " << vertexData << "adjacent list onto stack" << endl;

    //While is is not empty
    while(outDegree>=0)
    {
      //Pushes adjacent verticies onto stack
      stk.push(alist.getElement(outDegree)); 
      outDegree--;
    }

    cout << endl << "Updated Stack after " << vertexData << endl;
    stk.displayAll();
  }

  else
  {
    cout << "No adjacent vertices" << endl;
  }
}
