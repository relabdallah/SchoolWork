// =========================================================
//HW#: HW6 DGRAPH
//Your name: Ramzi El-abdallah
//Complier:  g++ compiler
//File type: DGraph implementation file
//==========================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dgraph.h"

using namespace std;

void dgraph::fillTable()
{
  // Open the file
  ifstream file("table.txt");
  string line;
  
  int i = 0; // Counter to loop through the Gtable array.
  
  // Loop over the file, one line at a time.
  while(getline(file, line))
    {
      char vert_name;
      int out_degree;
      char adj_vertex;
      
      slist adj_list = slist();
      
      // this lets us easily output whitespace delimited 'formatted' text into variables.
      stringstream listream(line);
      
      listream >> vert_name;
      listream >> out_degree;
      
      // everything left in listream (if anything!) is an adjacent vertex
      while(listream >> adj_vertex)
	{
	  adj_list.addRear(adj_vertex);
	}
      
      // Fills in Gvertex with data
      Gvertex vert;
      vert.name = vert_name;
      vert.out_degree = out_degree;
      vert.adj_list = adj_list; // Calls copy constructor of slist.
      
      Gtable[i] = vert;
      i++;
      count++;
    }
  // When the loop ends, we've read every line of the file.
  // file (an ifstream object) closes automatically at the end of fillTable()
}

//Purpose: Loops through to display graph
void dgraph::displayGraph()
{
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (Gtable[i].name != '\0')
	{
	  cout << Gtable[i].name << '\t';
	  cout << Gtable[i].out_degree << '\t';
	  Gtable[i].adj_list.displayAll();  // Note, calls slist's displayAll()
	}
    }
}

//Purpose: Searches for vertex and returns out degree
//Parameters: Takes in the vertex to be searched for
int dgraph::findOutDegree(char vertex_name)
{
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (vertex_name == Gtable[i].name)
	{
	  return(Gtable[i].out_degree);
	}
    }
  throw(dgraph::VertexNotFound()); //Exception if vertex not found
}

//Purpose: Searches for vertex and returns copy of adjacency list
//Parameters: Takes in the vertex to be searched for
slist dgraph::findAdjacencyList(char vertex_name)
{
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (vertex_name == Gtable[i].name)
	{
	  return(Gtable[i].adj_list);
	}
    }
  throw(dgraph::VertexNotFound()); //Exception if vertex not found
}

//Constructor initiates the dgraph
dgraph::dgraph()
{
  count = 0;
  
  for (int i = 0; i < MAX_SIZE; i++)
    {
      Gtable[i].name = '\0';
      Gtable[i].mark = 0;
      Gtable[i].out_degree = 0;
    }
}

// Destructor
dgraph::~dgraph()
{
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (Gtable[i].name != '\0')
	{
	  // the slist destructor, iteratively destroys every item in the list
	  Gtable[i].adj_list.~slist(); 
	}
    }
}
