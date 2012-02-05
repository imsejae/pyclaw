// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (dtensorBC3.cpp)
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
//     int mbc;         Number of ghost cells


dTensorBC3::dTensorBC3(int n1, int n2, int n3, int numBC)
// Constructor
// POST: Create a tensor of size (n1,n2,n3)
{
    mbc=numBC;

    vec = new double[(n1+2*mbc)*n2*n3];
    numElem1 = (n1+2*mbc);
    numElem2 = n2;
    numElem3 = n3;
}

dTensorBC3::dTensorBC3(const dTensorBC3& anotherdTensorBC3)
// Copy constructor
// POST: New tensor created with size and contents same as anotherdTensorBC3
{
    int i;

    numElem1 = anotherdTensorBC3.numElem1;
    numElem2 = anotherdTensorBC3.numElem2;
    numElem3 = anotherdTensorBC3.numElem3;
    vec = new double[numElem1*numElem2*numElem3];
    mbc = anotherdTensorBC3.mbc;
  
    for (i=0; i<numElem1*numElem2*numElem3; i++)
    { vec[i] = anotherdTensorBC3.vec[i]; }
}

dTensorBC3::~dTensorBC3()
// Destructor
// POST: dTensor no longer exists
{
    delete[] vec;
}

const double& dTensorBC3::get(int n1, int n2, int n3) const
// POST: Get (n1,n2,n3)^(th) entry in tensor
{
  int k;
  
  k = (n1-1+mbc)*numElem2*numElem3 + (n2-1)*numElem3 + (n3-1);
    
  return vec[k];
}

void dTensorBC3::set(int n1, int n2, int n3, double value)
// POST: Set (n1,n2,n3)^(th) entry in tensor to "value"
{
  int k;
  
  k = (n1-1+mbc)*numElem2*numElem3 + (n2-1)*numElem3 + (n3-1);
    
  vec[k] = value;
}

int dTensorBC3::getsize(int n) const
// POST: Returns value of "size" to user
{
  switch(n)
    {
    case 1: 
      return (numElem1-2*mbc); 
      break;
    case 2:
      return numElem2;
      break;
    case 3:
      return numElem3;
      break;
    }
}

int dTensorBC3::getmbc() const
// POST: Returns value of "mbc" to user
{
  return mbc;
}

void dTensorBC3::resize(int mx_new)
// POST: Resize tensor from
//       q(numElem1,numElem2,numElem3)  to  q(mx_new,numElem2,numElem3)
{
  int i,n;
  double* vec_new;

  n = numElem2*numElem3;
  
  vec_new = new double[(mx_new+2*mbc)*n];
  
  if ( (mx_new+2*mbc) <= numElem1 )
    {
      for (i=0; i<((mx_new+2*mbc)*n); i++)
	{
	  vec_new[i] = vec[i];
	}
    }
  else
    {
      for (i=0; i<(numElem1*n); i++)
	{
	  vec_new[i] = vec[i];
	}
      
      for (i=numElem1*n; i<((mx_new+2*mbc)*n); i++)
	{
	  vec_new[i] = 0.0;
	}
    }

  numElem1 = mx_new+2*mbc;
      
  delete[] vec;
  vec = new double[numElem1*n];
  
  for (i=0; i<numElem1*n; i++)
    {
      vec[i] = vec_new[i];
    }
  
  delete[] vec_new;
}
