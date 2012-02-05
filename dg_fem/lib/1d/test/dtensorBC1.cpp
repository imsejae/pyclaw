// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensorBC1.cpp)
//    This module describes a class of rank one tensors (vectors)
//    All of the elements in the tensors are of type "double"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;


// Private members of class:
//     double* vec;     Pointer to vector on free store
//     int size;        Size of vector
//     int mbc;         Number of ghost cells

dTensorBC1::dTensorBC1(int numElements, int numBC)
// Constructor
// POST: Create a vector of length n
{
  mbc=numBC;

  vec  = new double[numElements+2*mbc];
  size = (numElements+2*mbc);
}

dTensorBC1::dTensorBC1(const dTensorBC1& anotherdTensorBC1)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensorBC1
{
  int i;
  
  size = anotherdTensorBC1.size;
  vec = new double[size];
  mbc = anotherdTensorBC1.mbc;
  
  for (i=0; i<size; i++)
    { vec[i] = anotherdTensorBC1.vec[i]; }
}

dTensorBC1::~dTensorBC1()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensorBC1::get(int n) const
// POST: Get n^(th) entry in tensor
{
  int k = n-1+mbc;
      
  return vec[k];
}

void dTensorBC1::set(int n, double value)
// POST: Set n^(th) entry in tensor to "value"
{
  int k = n-1+mbc;
  
  vec[k] = value;
}

int dTensorBC1::getsize() const
// POST: Returns value of "size" to user
{
  return (size-2*mbc);
}

int dTensorBC1::getmbc() const
// POST: Returns value of "mbc" to user
{
  return mbc;
}
