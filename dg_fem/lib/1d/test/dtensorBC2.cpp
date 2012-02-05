// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensorBC2.cpp)
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
//     int mbc;         Number of ghost cells


dTensorBC2::dTensorBC2(int numRows, int numColumns, int numBC)
// Constructor
// POST: Create a matrix with n1 rows and n2 columns
{
  mbc=numBC;
  
  vec = new double[(numRows+2*mbc)*numColumns];
  rows = (numRows+2*mbc);
  columns = numColumns;
}

dTensorBC2::dTensorBC2(const dTensorBC2& anotherdTensorBC2)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensorBC2
{
  int i;
  
  rows = anotherdTensorBC2.rows;
  columns = anotherdTensorBC2.columns;
  vec = new double[rows*columns];
  mbc = anotherdTensorBC2.mbc;
  
  for (i=0; i<rows*columns; i++)
    { vec[i] = anotherdTensorBC2.vec[i]; }
}

dTensorBC2::~dTensorBC2()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensorBC2::get(int n1, int n2) const
// POST: Get (n1,n2)^(th) entry in tensor
{
  int k;
  
  k = (n1-1+mbc)*columns + (n2-1);

  return vec[k];
}

void dTensorBC2::set(int n1, int n2, double value)
// POST: Set (n1,n2)^(th) entry in tensor to "value"
{
  int k;
  
  k = (n1-1+mbc)*columns + (n2-1);
  
  vec[k] = value;
}

int dTensorBC2::getsize(int n) const
// POST: Returns value of "size" to user
{
  if (n==1)
    { return (rows-2*mbc); }
  else
    { return columns; }
}

int dTensorBC2::getmbc() const
// POST: Returns value of "mbc" to user
{
  return mbc;
}
