// =========================================================
//HW#: HW6 DGRAPH
//Your name: Ramzi El-abdallah
//Complier:  g++ compiler
//File type: DGraph Client file
//==========================================================

#include <iostream>
#include <ctype.h>
#include "dgraph.h"

//Functions for Client File
void reportAdjacencyList(dgraph& myGraph);
void reportOutDegree(dgraph& myGraph);

int main()
{
  dgraph myGraph = dgraph();
  
  cout << "Loading data from file table.txt" << endl;
  myGraph.fillTable();
  
  string selection;
  while (selection != "q")
    {
      // Prompt for input
      cout << "Select one:" << endl;
      cout << "1. Find Adjacency List of a vertex" << endl;
      cout << "2. Find Out Degree of a vertex" << endl;
      cout << "3. Display the graph as a table" << endl;
      cout << "4. Quit" << endl;
      cout << "Choice: ";
      cin >> selection;
      
      
      if (selection == "1")
	{
	  reportAdjacencyList(myGraph);
	}
      else if (selection == "2")
	{
	  reportOutDegree(myGraph);
	}
      else if (selection == "3")
	{
	  cout << "Vertex\tDegree\tAdjacencyList" << endl;
	  myGraph.displayGraph();
	}
      else if (selection == "4")
	{
	  selection = "q";
	}
      else //For invalid selection
	{
	  cout << "Please select one of the above options." << endl;
	}
    }
  return(0);
}


//Purpose: Displays the adjacency list of a vertex that is inputed
//Parameters: Takes a dgraph reference
void reportAdjacencyList(dgraph& myGraph)
{
  slist adj_list = slist();
  
  cout << "Enter the vertex you would like to search for:" << endl;
  
  string selection;
  cin >> selection;
  
  char vertex_name = toupper(selection[0]);
  
  cout << "Searching for vertex " << vertex_name << endl;
  try
    {
      adj_list = myGraph.findAdjacencyList(vertex_name);
      cout << "The adjacency list for that vertex is:" << endl;
      adj_list.displayAll();
    }
  catch (dgraph::VertexNotFound)
    {
      cout << "ERROR: Vertex not found!" << endl;
    }
}

//Purpose: Displays the degree of a vertex that is inputed
//Parameters: Takes a dgraph reference
void reportOutDegree(dgraph& myGraph)
{
  cout << "Enter the vertex you would like to search for:" << endl;
  
  string selection;
  cin >> selection;
  
  char vertex_name = toupper(selection[0]);
  
  cout << "Searching for vertex " << vertex_name << endl;
  try
    {
      cout << "The out degree for that vertex is:" << endl;
      cout << myGraph.findOutDegree(vertex_name) << endl;
    }
  catch (dgraph::VertexNotFound)
    {
      cout << "ERROR: Vertex not found!" << endl;
    }
}
