// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensorBC4.cpp)
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
//     int mbc;         Number of ghost cells


dTensorBC4::dTensorBC4(int n1, int n2, int n3, int n4, int numBC)
// Constructor
// POST: Create a tensor of size (n1,n2,n3,n4)
{
  mbc=numBC;
  
  vec = new double[(n1+2*mbc)*n2*n3*n4];
  numElem1 = (n1+2*mbc);
  numElem2 = n2;
  numElem3 = n3;
  numElem4 = n4;  
}

dTensorBC4::dTensorBC4(const dTensorBC4& anotherdTensorBC4)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensorBC4
{
  int i;
  
  numElem1 = anotherdTensorBC4.numElem1;
  numElem2 = anotherdTensorBC4.numElem2;
  numElem3 = anotherdTensorBC4.numElem3;
  numElem4 = anotherdTensorBC4.numElem4;
  vec = new double[numElem1*numElem2*numElem3*numElem4];
  mbc = anotherdTensorBC4.mbc;
  
  for (i=0; i<numElem1*numElem2*numElem3*numElem4; i++)
    { vec[i] = anotherdTensorBC4.vec[i]; }
}

dTensorBC4::~dTensorBC4()
// Destructor
// POST: dTensor no longer exists
{
  delete[] vec;
}

const double& dTensorBC4::get(int n1, int n2, int n3, int n4) const
// POST: Get (n1,n2,n3,n4)^(th) entry in tensor
{
  int k;
  
  k = (n1-1+mbc)*numElem2*numElem3*numElem4 
    + (n2-1)*numElem3*numElem4 + (n3-1)*numElem4 + (n4-1);
  
  return vec[k];
}

void dTensorBC4::set(int n1, int n2, int n3, int n4, double value)
// POST: Set (n1,n2,n3,n4)^(th) entry in tensor to "value"
{
  int k;
  
  k = (n1-1+mbc)*numElem2*numElem3*numElem4 
    + (n2-1)*numElem3*numElem4 + (n3-1)*numElem4 + (n4-1);
  
  vec[k] = value;
}

int dTensorBC4::getsize(int n) const
// POST: Returns value of "size" to user
{
  int nout;
  
  switch(n)
    {
    case 1:
      nout = numElem1-2*mbc;
      break;
    case 2:
      nout = numElem2;
      break;
    case 3:
      nout = numElem3;
      break;
    case 4:
      nout = numElem4;
      break;
    }
  
  return nout;
}

int dTensorBC4::getmbc() const
// POST: Returns value of "mbc" to user
{
  return mbc;
}
