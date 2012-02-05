// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensor2.cpp)
//    This module describes a class of rank two tensors (matrices)
//    All of the elements in the tensors are of type "double"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;


// Private members of class:
//     double* vec;     Pointer to vector on free store
//     int rows;        Number of rows
//     int columns;     Number of columns


dTensor2::dTensor2(int numRows, int numColumns)
// Constructor
// POST: Create a matrix with n1 rows and n2 columns
{
  vec = new double[numRows*numColumns];
  rows = numRows;
  columns = numColumns;
}

dTensor2::dTensor2(const dTensor2& anotherdTensor2)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensor2
{
  int i;
  
  rows = anotherdTensor2.rows;
  columns = anotherdTensor2.columns;
  
  vec = new double[rows*columns];
  
  for (i=0; i<rows*columns; i++)
    { vec[i] = anotherdTensor2.vec[i]; }
}

dTensor2::~dTensor2()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensor2::get(int n1, int n2) const
// POST: Get (n1,n2)^(th) entry in tensor
{
  int k;
  k = (n1-1)*columns + (n2-1);
  
  return vec[k];
}

void dTensor2::set(int n1, int n2, double value)
// POST: Set (n1,n2)^(th) entry in tensor to "value"
{
  int k;
  k = (n1-1)*columns + (n2-1);

  vec[k] = value;
}

int dTensor2::getsize(int n) const
// POST: Returns value of "size" to user
{
  if (n==1)
    { return rows; }
  else
    { return columns; }
}
