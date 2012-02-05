#define _TENSORS_H_
// --------------------------------------------------------------------------
//  SPECIFICATION FILE (tensors.h)
//    This module describes six separate classes for
//
//         rank one   tensors of doubles  -- dTensor1 (vectors)
//         rank two   tensors of doubles  -- dTensor2 (matrices)
//         rank three tensors of doubles  -- dTensor3
//         
//         rank one   tensors of integers -- iTensor1 (vectors)
//         rank two   tensors of integers -- iTensor2 (matrices)
//         rank three tensors of integers -- iTensor3
//
// --------------------------------------------------------------------------

#include "stdlib.h"

// RANK ONE TENSORS ----------------------------------------
class dTensor1
{
 public:
    dTensor1(int n);
    // Constructor
    // POST: Create a vector of length n
    
   // dTensor1(const dTensor1& anotherdTensor1);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensor1
    
    ~dTensor1();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n) const;
    // POST: Get n^(th) entry in tensor

    void set(int n, double value);
    // POST: Set n^(th) entry in tensor to "value"

    int getsize() const;
    // POST: Returns value of "size" to user

 private:
    double* vec;
    int size;
};
// ---------------------------------------------------------
/*

// RANK TWO TENSORS ----------------------------------------
class dTensor2
{
 public:
    dTensor2(int n1, int n2);
    // Constructor
    // POST: Create a matrix with n1 rows and n2 columns
    
    dTensor2(const dTensor2& anotherdTensor2);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensor2
    
    ~dTensor2();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n1, int n2) const;
    // POST: Get (n1,n2)^(th) entry in tensor

    void set(int n1, int n2, double value);
    // POST: Set (n1,n2)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of rows
    //       if n==2: returns number of columns

 private:
    double* vec;
    int rows,columns;
};
// ---------------------------------------------------------



// RANK THREE TENSORS ----------------------------------------
class dTensor3
{
 public:
    dTensor3(int n1, int n2, int n3);
    // Constructor
    // POST: Create a tensor of size (n1,n2,n3)
    
    dTensor3(const dTensor3& anotherdTensor3);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensor3
    
    ~dTensor3();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n1, int n2, int n3) const;
    // POST: Get (n1,n2,n3)^(th) entry in tensor

    void set(int n1, int n2, int n3, double value);
    // POST: Set (n1,n2,n3)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of elements in first index
    //       if n==2: returns number of elements in second index
    //       if n==3: returns number of elements in third index

 private:
    double* vec;
    int numElem1,numElem2,numElem3;
};
// ---------------------------------------------------------


// RANK FOUR TENSORS ---------------------------------------
class dTensor4
{
 public:
    dTensor4(int n1, int n2, int n3, int n4);
    // Constructor
    // POST: Create a tensor of size (n1,n2,n3,n4)
    
    dTensor4(const dTensor4& anotherdTensor4);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensor3
    
    ~dTensor4();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n1, int n2, int n3, int n4) const;
    // POST: Get (n1,n2,n3,n4)^(th) entry in tensor

    void set(int n1, int n2, int n3, int n4, double value);
    // POST: Set (n1,n2,n3,n4)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of elements in first index
    //       if n==2: returns number of elements in second index
    //       if n==3: returns number of elements in third index
    //       if n==4: returns number of elements in fourth index

 private:
    double* vec;
    int numElem1,numElem2,numElem3,numElem4;
    int size;
};
// ---------------------------------------------------------

// RANK ONE TENSORS ----------------------------------------
class iTensor1
{
 public:
    iTensor1(int n);
    // Constructor
    // POST: Create a vector of length n
    
    iTensor1(const iTensor1& anotheriTensor1);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotheriTensor1
    
    ~iTensor1();
    // Destructor
    // POST: iTensor no longer exists

    const int& get(int n) const;
    // POST: Get n^(th) entry in tensor

    void set(int n, int value);
    // POST: Set n^(th) entry in tensor to "value"

    int getsize() const;
    // POST: Returns value of "size" to user
    
    void resize(int newsize);
    // POST: change "size" and "vec"

 private:
    int* vec;
    int size;
};
// ---------------------------------------------------------


// RANK TWO TENSORS ----------------------------------------
class iTensor2
{
 public:
    iTensor2(int n1, int n2);
    // Constructor
    // POST: Create a matrix with n1 rows and n2 columns
    
    iTensor2(const iTensor2& anotheriTensor2);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotheriTensor2
    
    ~iTensor2();
    // Destructor
    // POST: iTensor no longer exists

    const int& get(int n1, int n2) const;
    // POST: Get (n1,n2)^(th) entry in tensor

    void set(int n1, int n2, int value);
    // POST: Set (n1,n2)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of rows
    //       if n==2: returns number of columns

 private:
    int* vec;
    int rows,columns;
};
// ---------------------------------------------------------



// RANK THREE TENSORS ----------------------------------------
class iTensor3
{
 public:
    iTensor3(int n1, int n2, int n3);
    // Constructor
    // POST: Create a tensor of size (n1,n2,n3)
    
    iTensor3(const iTensor3& anotheriTensor3);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotheriTensor3
    
    ~iTensor3();
    // Destructor
    // POST: iTensor no longer exists

    const int& get(int n1, int n2, int n3) const;
    // POST: Get (n1,n2,n3)^(th) entry in tensor

    void set(int n1, int n2, int n3, int value);
    // POST: Set (n1,n2,n3)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of elements in first index
    //       if n==2: returns number of elements in second index
    //       if n==3: returns number of elements in third index

 private:
    int* vec;
    int numElem1,numElem2,numElem3;
};
// ---------------------------------------------------------


// RANK ONE TENSORS WITH GHOST CELLS -----------------------
class dTensorBC1
{
 public:
    dTensorBC1(int n, int numBC);
    // Constructor
    // POST: Create a vector of length n
    
    dTensorBC1(const dTensorBC1& anotherdTensorBC1);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensorBC1
    
    ~dTensorBC1();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n) const;
    // POST: Get n^(th) entry in tensor

    void set(int n, double value);
    // POST: Set n^(th) entry in tensor to "value"

    int getsize() const;
    // POST: Returns value of "size" to user

    int getmbc() const;
    // POST: Returns value of "mbc" to user

 private:
    double* vec;
    int size;
    int mbc;
};
// ---------------------------------------------------------


// RANK TWO TENSORS WITH GHOST CELLS -----------------------
class dTensorBC2
{
 public:
    dTensorBC2(int n1, int n2, int numBC);
    // Constructor
    // POST: Create a matrix with n1 rows and n2 columns
    
    dTensorBC2(const dTensorBC2& anotherdTensorBC2);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensorBC2
    
    ~dTensorBC2();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n1, int n2) const;
    // POST: Get (n1,n2)^(th) entry in tensor

    void set(int n1, int n2, double value);
    // POST: Set (n1,n2)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of rows
    //       if n==2: returns number of columns

    int getmbc() const;
    // POST: Returns value of "mbc" to user

 private:
    double* vec;
    int rows,columns;
    int mbc;
};
// ---------------------------------------------------------


// RANK THREE TENSORS WITH GHOST CELLS ---------------------
class dTensorBC3
{
 public:
    dTensorBC3(int n1, int n2, int n3, int numBC);
    // Constructor
    // POST: Create a tensor of size (n1,n2,n3)
    
    dTensorBC3(const dTensorBC3& anotherdTensorBC3);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensorBC3
    
    ~dTensorBC3();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n1, int n2, int n3) const;
    // POST: Get (n1,n2,n3)^(th) entry in tensor

    void set(int n1, int n2, int n3, double value);
    // POST: Set (n1,n2,n3)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of elements in first index
    //       if n==2: returns number of elements in second index
    //       if n==3: returns number of elements in third index

    int getmbc() const;
    // POST: Returns value of "mbc" to user

    void resize(int n1_new);
    // POST: Resize tensor from
    //       q(n1,n2,n3)  to  q(n1_new,n2,n3)

 private:
    double* vec;
    int numElem1,numElem2,numElem3;
    int mbc;
};
// ---------------------------------------------------------


// RANK FOUR TENSORS WITH GHOST CELLS ---------------------
class dTensorBC4
{
 public:
    dTensorBC4(int n1, int n2, int n3, int n4, int numBC);
    // Constructor
    // POST: Create a tensor of size (n1,n2,n3,n4)
    
    dTensorBC4(const dTensorBC4& anotherdTensorBC4);
    // Copy constructor
    // POST: New tensor created with size and contents same as anotherdTensorBC4
    
    ~dTensorBC4();
    // Destructor
    // POST: dTensor no longer exists

    const double& get(int n1, int n2, int n3, int n4) const;
    // POST: Get (n1,n2,n3,n4)^(th) entry in tensor

    void set(int n1, int n2, int n3, int n4, double value);
    // POST: Set (n1,n2,n3,n4)^(th) entry in tensor to "value"

    int getsize(int n) const;
    // POST: if n==1: returns number of elements in first index
    //       if n==2: returns number of elements in second index
    //       if n==3: returns number of elements in third index
    //       if n==4: returns number of elements in fourth index

    int getmbc() const;
    // POST: Returns value of "mbc" to user

 private:
    double* vec;
    int numElem1,numElem2,numElem3,numElem4;
    int mbc;
};
*/
// ---------------------------------------------------------
