// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

/* note that Gtable[i].adjacnentOnes is a slist, so you can use
   any slist function on it

Hint on filltable::

Set up fin stream to read from table.txt
while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
{ fin >> Gtable[coutUsed].outDegree;
  // Then for the outDegree times do the following: (use a for-loop)
  {
     fin >> X;
     (Gtable[coutUsed].adjacentOnes).addRear(x); 
                      // this uses a slist function from HW3
  }//end of for
  // increment the countUsed
}//end of while
close fin

Hint on displaygraph::

Make the following couts better with labels.
for (int i = 0; i < coutUsed; i++}
{  
    cout << Gtable[i].vertexname << endl;
    cout << Gtable[i].outdegree << endl;
    (Gtable[i].adjacentOnes).displayAll();
}  

Instruction on findOutDegree and findAdjacency::

For this HW, you must use a loop.
Do not go through all the slots of the table
Just go through the used slots.

*/

