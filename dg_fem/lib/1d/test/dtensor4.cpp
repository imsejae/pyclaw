// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensor4.cpp)
//    This module describes a class of rank four tensors
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
//     int numElem4;    Number of elements in fourth index


dTensor4::dTensor4(int n1, int n2, int n3, int n4)
// Constructor
// POST: Create a tensor of size (n1,n2,n3,n4)
{
  size = n1*n2*n3*n4;
  vec = new double[size];
  numElem1 = n1;
  numElem2 = n2;
  numElem3 = n3;
  numElem4 = n4;
}

dTensor4::dTensor4(const dTensor4& anotherdTensor4)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensor4
{
  int i;
  
  numElem1 = anotherdTensor4.numElem1;
  numElem2 = anotherdTensor4.numElem2;
  numElem3 = anotherdTensor4.numElem3;
  numElem4 = anotherdTensor4.numElem4;
  size = anotherdTensor4.size;
  vec = new double[size];
  
  for (i=0; i<size; i++)
    { vec[i] = anotherdTensor4.vec[i]; }
}

dTensor4::~dTensor4()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensor4::get(int n1, int n2, int n3, int n4) const
// POST: Get (n1,n2,n3,n4)^(th) entry in tensor
{
  int k = (((n1-1)*numElem2 + (n2-1))*numElem3
	   + (n3-1))*numElem4 + (n4-1);
  
  return vec[k];
}

void dTensor4::set(int n1, int n2, int n3, int n4, double value)
// POST: Set (n1,n2,n3,n4)^(th) entry in tensor to "value"
{
  int k = (((n1-1)*numElem2 + (n2-1))*numElem3 
            + (n3-1))*numElem4 + (n4-1);
            
  vec[k] = value;
}

int dTensor4::getsize(int n) const
// POST: Returns value of "size" to user
{
  switch(n)
    {
    case 1: return numElem1; break;
    case 2: return numElem2; break;
    case 3: return numElem3; break;
    case 4: return numElem4; break;
    }
}
