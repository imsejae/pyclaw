// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (itensor2.cpp)
//    This module describes a class of rank two tensors (matrices)
//    All of the elements in the tensors are of type "int"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;


// Private members of class:
//     int* vec;        Pointer to vector on free store
//     int rows;        Number of rows
//     int columns;     Number of columns


iTensor2::iTensor2(int numRows, int numColumns)
// Constructor
// POST: Create a matrix with n1 rows and n2 columns
{
  vec = new int[numRows*numColumns];
  rows = numRows;
  columns = numColumns;
}

iTensor2::iTensor2(const iTensor2& anotheriTensor2)
// Copy constructor
// POST: New tensor created with size and contents same as anotheriTensor2
{
  int i;
  
  rows = anotheriTensor2.rows;
  columns = anotheriTensor2.columns;
  vec = new int[rows*columns];
  
  for (i=0; i<rows*columns; i++)
    { vec[i] = anotheriTensor2.vec[i]; }
}

iTensor2::~iTensor2()
// Destructor
// POST: iTensor no longer exists
{
  delete[] vec;
}

const int& iTensor2::get(int n1, int n2) const
// POST: Get (n1,n2)^(th) entry in tensor
{
  int k;
  k = (n1-1)*columns + (n2-1);
  
  return vec[k];
}

void iTensor2::set(int n1, int n2, int value)
// POST: Set (n1,n2)^(th) entry in tensor to "value"
{
  int k;
  k = (n1-1)*columns + (n2-1);

  vec[k] = value;
}

int iTensor2::getsize(int n) const
// POST: Returns value of "size" to user
{
  if (n==1)
    { return rows; }
  else
    { return columns; }
}
