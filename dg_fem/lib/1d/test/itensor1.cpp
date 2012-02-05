// --------------------------------------------------------------------------
//  IMPLEMENTATION FILE (itensor1.cpp)
//    This module describes a class of rank one tensors (vectors)
//    All of the elements in the tensors are of type "int"
// --------------------------------------------------------------------------

#include "tensors.h"
#include<new>
using namespace std;


// Private members of class:
//     int* vec;     Pointer to vector on free store
//     int size;     Size of vector


iTensor1::iTensor1(int numElements)
// Constructor
// POST: Create a vector of length n
{
  vec = new int[numElements];
  size = numElements;
}

iTensor1::iTensor1(const iTensor1& anotheriTensor1)
// Copy constructor
// POST: New tensor created with size and contents same as anotheriTensor1
{
  int i;

  size = anotheriTensor1.size;
  vec = new int[size];
  
  for (i=0; i<size; i++)
    { vec[i] = anotheriTensor1.vec[i]; }
}

iTensor1::~iTensor1()
// Destructor
// POST: iTensor no longer exists
{
  delete[] vec;
}

const int& iTensor1::get(int n) const
// POST: Get n^(th) entry in tensor
{
  int k = n-1;
  
  return vec[k];
}

void iTensor1::set(int n, int value)
// POST: Set n^(th) entry in tensor to "value"
{
  int k = n-1;
  
  vec[k] = value; 
}

int iTensor1::getsize() const
// POST: Returns value of "size" to user
{
  return size;
}

void iTensor1::resize(int newsize)
// POST: change "size" and "vec"
{
  int i;
  int* newvec;
  newvec = new int[newsize];
  
  if (newsize>size)
    {  
      for (i=0; i<size; i++)
	{  newvec[i] = vec[i];  }
      
      for (i=size; i<newsize; i++)
	{  newvec[i] = 0;  }
    }
  else
    {
      for (i=0; i<newsize; i++)
	{  newvec[i] = vec[i];  }
    }
  
  size = newsize;
  delete[] vec;
  vec = new int[size];
  
  for (i=0; i<size; i++)
    {  vec[i] = newvec[i];  }   
  
  delete[] newvec;
  
  return;
}
