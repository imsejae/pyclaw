// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensor1.cpp)
//    This module describes a class of rank one tensors (vectors)
//    All of the elements in the tensors are of type "double"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;

// Private members of class:
//     double* vec;     Pointer to vector on free store
//     int size;        Size of vector


dTensor1::dTensor1(int numElements)
// Constructor
// POST: Create a vector of length n
{
  vec = new double[numElements];
  size = numElements;
}

dTensor1::dTensor1(const dTensor1& anotherdTensor1)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensor1
{
  int i;
  
  size = anotherdTensor1.size;
  vec = new double[size];
  
  for (i=0; i<size; i++)
    { vec[i] = anotherdTensor1.vec[i]; }
}

dTensor1::~dTensor1()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensor1::get(int n) const
// POST: Get n^(th) entry in tensor
{
  int k = n-1;

  return vec[k];
}

void dTensor1::set(int n, double value)
// POST: Set n^(th) entry in tensor to "value"
{
  int k = n-1;

  vec[k] = value;
}

int dTensor1::getsize() const
// POST: Returns value of "size" to user
{
  return size;
}
