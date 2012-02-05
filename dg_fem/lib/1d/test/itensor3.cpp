// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (itensor3.cpp)
//    This module describes a class of rank three tensors
//    All of the elements in the tensors are of type "int"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;


// Private members of class:
//     int* vec;        Pointer to vector on free store
//     int numElem1;    Number of elements in first index
//     int numElem2;    Number of elements in second index
//     int numElem3;    Number of elements in third index


iTensor3::iTensor3(int n1, int n2, int n3)
// Constructor
// POST: Create a tensor of size (n1,n2,n3)
{
  vec = new int[n1*n2*n3];
  numElem1 = n1;
  numElem2 = n2;
  numElem3 = n3;
}

iTensor3::iTensor3(const iTensor3& anotheriTensor3)
// Copy constructor
// POST: New tensor created with size and contents same as anotheriTensor3
{
  int i;
  
  numElem1 = anotheriTensor3.numElem1;
  numElem2 = anotheriTensor3.numElem2;
  numElem3 = anotheriTensor3.numElem3;
  vec = new int[numElem1*numElem2*numElem3];
  
  for (i=0; i<numElem1*numElem2*numElem3; i++)
    { vec[i] = anotheriTensor3.vec[i]; }
}

iTensor3::~iTensor3()
// Destructor
// POST: iTensor no longer exists
{
  delete[] vec;
}

const int& iTensor3::get(int n1, int n2, int n3) const
// POST: Get (n1,n2)^(th) entry in tensor
{
  int k;
  k = (n1-1)*numElem2*numElem3 + (n2-1)*numElem3 + (n3-1);

  return vec[k];
}

void iTensor3::set(int n1, int n2, int n3, int value)
// POST: Set (n1,n2)^(th) entry in tensor to "value"
{
  int k;
  k = (n1-1)*numElem2*numElem3 + (n2-1)*numElem3 + (n3-1);

  vec[k] = value;
}

int iTensor3::getsize(int n) const
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
