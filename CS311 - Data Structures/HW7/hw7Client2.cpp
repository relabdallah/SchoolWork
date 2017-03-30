// =========================================================
//HW#: HW7P2 DGRAPH
//Your name: Ramzi El-abdallah
//Complier:  g++ compiler
//File type: Client File
//==========================================================

#include <iostream>
#include "dgraph.h"

using namespace std;

void checkVisit(dgraph& graphRef, stack& stackRef, char vertexData, int& visitMark);
void checkAdjacent(dgraph& graphRef, stack& stackRef, char vertexData);

int main()
{
  char vertexElem;  
  int visitMark = 1;  
  
  dgraph graph1;  
  stack stack1;
  
  
  cout << "*Now filling table*" << endl; 
  graph1.fillTable();

  cout << "Displaying table before DFS" << endl;
  graph1.displayGraph();
  
  cout << "\nBeginning DFS with A" << endl;
  checkVisit(graph1, stack1, 'A', visitMark);

  
  while(!stack1.isEmpty())
  {
    stack1.pop(vertexElem);  
    cout << "\nPop " << vertexElem << endl; 
    checkVisit(graph1, stack1, vertexElem, visitMark);
  }
  
  cout << "\nDisplaying graph verticies and their visit number:" << endl;
  graph1.displayVisit();
  
  cout << "Goodbye" << endl;
  return 0;
}


//Checks if Vertex has been marked and visited before
void checkVisit(dgraph& graphRef, stack& stackRef, char vertexData, int& visitMark){
  if(!graphRef.isMarked(vertexData))
    {
      graphRef.visit(visitMark, vertexData);
      cout << " - Adding Mark." << endl;
      visitMark++;
      
      //Test if the vertex has any adjacencies
      checkAdjacent(graphRef, stackRef, vertexData);
    }
  else
    {
      cout << " - Element " << vertexData << " has been visited already." << endl;
    }
}

//Checks for adjacencies and pushes those elements onto the stack
void checkAdjacent(dgraph& graphRef, stack& stackRef, char vertexData)
{
  //Out Degree from findOutDegree()
  int outDegree = 0;
  
  //List to store adjacency list
  slist alist = graphRef.findAdjacencyList(vertexData);
  
  // Check if adjacency list is empty. If not, then push list onto stack.
  if(!alist.isEmpty())
  {
    outDegree = graphRef.findOutDegree(vertexData)-1; // Gets start index
    cout << "Pushing " << vertexData << " adjacent list onto stack." << endl;

    //While stack is not empty
    while(outDegree>=0)
    {
      //Pushes adjacent verticies onto stack
      stackRef.push(alist.getElement(outDegree)); 
      outDegree--;
    }
    cout << "Updateing stack after " << vertexData << endl;
    stackRef.displayAll();
  }
  else
  {
    cout << "No adjacent vertices." << endl;
  }
}
