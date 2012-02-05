// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensor3.cpp)
//    This module describes a class of rank three tensors
//    All of the elements in the tensors are of type "double"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;


// Private members of class:
//     double* vec;     Pointer to vector on free store
//     int numElem1;    Number of elements in first index
//     int numElem2;    Number of elements in second index
//     int numElem3;    Number of elements in third index


dTensor3::dTensor3(int n1, int n2, int n3)
// Constructor
// POST: Create a tensor of size (n1,n2,n3)
{
  vec = new double[n1*n2*n3];
  numElem1 = n1;
  numElem2 = n2;
  numElem3 = n3;
}

dTensor3::dTensor3(const dTensor3& anotherdTensor3)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensor3
{
  int i;
  
  numElem1 = anotherdTensor3.numElem1;
  numElem2 = anotherdTensor3.numElem2;
  numElem3 = anotherdTensor3.numElem3;
  
  vec = new double[numElem1*numElem2*numElem3];
  
  for (i=0; i<numElem1*numElem2*numElem3; i++)
    { vec[i] = anotherdTensor3.vec[i]; }
}

dTensor3::~dTensor3()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensor3::get(int n1, int n2, int n3) const
// POST: Get (n1,n2)^(th) entry in tensor
{
  int k;
  k = (n1-1)*numElem2*numElem3 + (n2-1)*numElem3 + (n3-1);
  
  return vec[k];
}

void dTensor3::set(int n1, int n2, int n3, double value)
// POST: Set (n1,n2)^(th) entry in tensor to "value"
{
  int k;
  k = (n1-1)*numElem2*numElem3 + (n2-1)*numElem3 + (n3-1);
  
  vec[k] = value;
}

int dTensor3::getsize(int n) const
// POST: Returns value of "size" to user
{
  switch(n)
    {
    case 1:
      return numElem1;
      break;
    case 2:
      return numElem2;
      break;
    case 3:
      return numElem3;
      break;
    }
}
