#include <iostream>
#include "dgraph.h"

using namespace std;

void checkVisit(dgraph& graph, stack& stk, char vertexData, int& visitMark);
void checkAdjacent(dgraph& graph, stack& stk, char vertexData);

int main(){

  char vertex1; //Holds the characters when popped
  int visitMark = 1; //Track the visit order number

  dgraph dg1; //Primary table
  stack vtx1; //Track the visit order number

  //Filling the table with table.txt
  cout << "*Now filling table*" << endl;
  dg1.fillTable();

  //Displaying table before DFS
  dg1.displayGraph();

  
  //Begin DFS with A
  cout << endl << "Beginning with A" << endl;
  checkVisit(dg1, vtx1, 'A', visitMark);
  /*
  //While loop goes through stack and checks elements until the stack is empty
  while(!stack1.isEmpty())
    {
      stack1.pop(vertex_elem); //Pops the top element off the stack, stores it into vertex_elem

      cout << endl << "Pop " << vertex_elem << endl; //Displays popped element

      //Checks is marked in checkVisit method
      //Elements get pushed and popped until stack is empty and DFS is complete
      checkVisit(graph1, stack1, vertex_elem, visitMark);
    }
  */

  while(!vtx1.isEmpty())
  {
    vtx1.pop(vertex1);  
    cout << "\nPop " << vertex1; 
    checkVisit(dg1, vtx1, vertex1, visitMark);
  }

  
  //Display Graph with visit numbers for all verticies
  cout << endl << "Elements and their Visit Numbers:" << endl;
  dg1.displayVisit();

    cout << "\nThanks! It's been a great semester." << endl;

  return 0;
}

//Checks if Vertex has been marked and visited before
void checkVisit(dgraph& graph, stack& stk, char vertexData, int& visitMark){
  if(!graph.isMarked(vertexData))
    {
      graph.visit(visitMark, vertexData);
      cout << "Adding Mark." << endl;
      visitMark++;

      //Test if the vertex has any adjacencies
      checkAdjacent(graph, stk, vertexData);
    }
  else
    {
      cout << "Element " << vertexData << " has been visited already." << endl;
    }
}

//Checks for adjacencies and pushes those elements onto the stack
void checkAdjacent(dgraph& graph, stack& stk, char vertexData){

  //Out Degree from findOutDegree()
  int outDegree = 0;

  //List to store adjacency list
  slist alist = graph.findAdjacencyList(vertexData);

  //Check if adjacency list is empty. If not, then push onto stack
  if(!alist.isEmpty())
    {
      outDegree = graph.findOutDegree(vertexData)-1; //Determine the start index
      cout << "Pusing " << vertexData << " adjacent list onto stack" << endl;

      //While stack is not empty
      while(outDegree >= 0)
	{
	  //Pushes adjacent verticies onto stack
	  stk.push(alist.getElement(outDegree));
	  outDegree--;
	}
      cout << endl << "Updateing stack after " << vertexData << endl;
      stk.displayAll();
    }
  else
    {
      cout << "No adjacent verticies." << endl;
    }
}
