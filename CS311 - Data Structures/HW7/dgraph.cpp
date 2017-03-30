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

void dgraph::displayVisit()
{
  for(int i = 1; i <= count; i++)
  {
    for(int j = 0; j < count; j++)
    {
      if(Gtable[j].mark == i)
      {
        cout << "Vertex Name: " << Gtable[j].name;
        cout << "\t\tVisit Number: " << Gtable[j].mark << endl;
      }
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

// This function assigns a visit number to a given element. 
void dgraph::visit(int elem, char vertex_name)
{
  for(int i=0; i< count; i++)
  {
    if(Gtable[i].name == vertex_name) // Check if the Key matches the Name
    {
      Gtable[i].mark = elem; // Assign a value to visit
    }
  }
}
  
// This function returns true if vertex passed was already visited  
bool dgraph::isMarked(char vertex_name)
{
  for(int i = 0; i < count; i++)
    {
      if(vertex_name == Gtable[i].name) // Check if the Key matches the Name
	{
	  if(Gtable[i].mark != 0) // Check if a value for visit exists
	    {
	      return true;
	    }
	  else
	    {
	      return false;
	    }
	}
    }
  cout << vertex_name << " not found." << endl;
  return false;
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
