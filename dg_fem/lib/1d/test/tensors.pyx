
cdef extern from "tensors.h":
    ctypedef struct c_dTensor1 "dTensor1":
        double& get(int n)
        void set(int n, double value)
        int getsize()
    c_dTensor1 *new_dTensor1 "new dTensor1" (int n)
    void del_dTensor1 "delete" (c_dTensor1 *dTens)

cdef class dTensor1:
    cdef c_dTensor1 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n):
        self.thisptr = new_dTensor1(n)
    def __dealloc__(self):
        del_dTensor1(self.thisptr)
    def getsize(self):
        return self.thisptr.getsize()
    def get(self,n):
        return self.thisptr.get(n)
    def set(self,n,value):
        self.thisptr.set(n,value)
        
