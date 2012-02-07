cimport testtensor

cdef class dTensor1:
    cdef testtensor.dTensor1 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n):
        self.thisptr = testtensor.new_dTensor1(n)
    def __dealloc__(self):
        testtensor.del_dTensor1(self.thisptr)
    def getsize(self):
        return self.thisptr.getsize()
    def get(self,n):
        return self.thisptr.get(n)
    def set(self,n,value):
        self.thisptr.set(n,value)

def SumOperator(self):
    SumOperator( self)  

cdef class dTensorBC1:
    cdef testtensor.c_dTensorBC1 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n,int mbc):
        self.thisptr = testtensor.new_dTensorBC1(n,mbc)
    def __dealloc__(self):
        testtensor.del_dTensorBC1(self.thisptr)
    def getsize(self):
        return self.thisptr.getsize()
    def get(self,n):
        return self.thisptr.get(n)
    def get(self,n):
        return self.thisptr.get(n)
    def getmbc(self):
        return self.thisptr.getmbc()
    def set(self,n,value):
        self.thisptr.set(n,value)

cdef class dTensor2:
    cdef testtensor.c_dTensor2 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2):
        self.thisptr = testtensor.new_dTensor2(n1,n2)
    def __dealloc__(self):
        testtensor.del_dTensor2(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2):
        return self.thisptr.get(n1,n2)
    def set(self,n1,n2,value):
        self.thisptr.set(n1,n2,value)

cdef class iTensor2:
    cdef testtensor.c_iTensor2 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2):
        self.thisptr = testtensor.new_iTensor2(n1,n2)
    def __dealloc__(self):
        testtensor.del_iTensor2(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2):
        return self.thisptr.get(n1,n2)
    def set(self,n1,n2,value):
        self.thisptr.set(n1,n2,value)

cdef class dTensorBC2:
    cdef testtensor.c_dTensorBC2 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int mbc):
        self.thisptr = testtensor.new_dTensorBC2(n1,n2,mbc)
    def __dealloc__(self):
        testtensor.del_dTensorBC2(self.thisptr)
    def getsize(self,n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2):
        return self.thisptr.get(n1,n2)
    def get(self,n1,n2):
        return self.thisptr.get(n1,n2)
    def getmbc(self):
        return self.thisptr.getmbc()
    def set(self,n1,n2,value):
        self.thisptr.set(n1,n2,value)

cdef class dTensor3:
    cdef testtensor.c_dTensor3 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3):
        self.thisptr = testtensor.new_dTensor3(n1,n2,n3)
    def __dealloc__(self):
        testtensor.del_dTensor3(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3):
        return self.thisptr.get(n1,n2,n3)
    def set(self,n1,n2,n3,value):
        self.thisptr.set(n1,n2,n3,value)

cdef class iTensor3:
    cdef testtensor.c_iTensor3 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3):
        self.thisptr = testtensor.new_iTensor3(n1,n2,n3)
    def __dealloc__(self):
        testtensor.del_iTensor3(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3):
        return self.thisptr.get(n1,n2,n3)
    def set(self,n1,n2,n3,value):
        self.thisptr.set(n1,n2,n3,value)

cdef class dTensorBC3:
    cdef testtensor.c_dTensorBC3 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3,int mbc):
        self.thisptr = testtensor.new_dTensorBC3(n1,n2,n3,mbc)
    def __dealloc__(self):
        testtensor.del_dTensorBC3(self.thisptr)
    def getsize(self,n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3):
        return self.thisptr.get(n1,n2,n3)
    def get(self,n1,n2,n3):
        return self.thisptr.get(n1,n2,n3)
    def getmbc(self):
        return self.thisptr.getmbc()
    def set(self,n1,n2,n3,value):
        self.thisptr.set(n1,n2,n3,value)

cdef class dTensor4:
    cdef testtensor.c_dTensor4 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3,int n4):
        self.thisptr = testtensor.new_dTensor4(n1,n2,n3,n4)
    def __dealloc__(self):
        testtensor.del_dTensor4(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3,n4):
        return self.thisptr.get(n1,n2,n3,n4)
    def set(self,n1,n2,n3,n4,value):
        self.thisptr.set(n1,n2,n3,n4,value)

cdef class dTensorBC4:
    cdef testtensor.c_dTensorBC4 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3,int n4,int mbc):
        self.thisptr = testtensor.new_dTensorBC4(n1,n2,n3,n4,mbc)
    def __dealloc__(self):
        testtensor.del_dTensorBC4(self.thisptr)
    def getsize(self,n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3,n4):
        return self.thisptr.get(n1,n2,n3,n4)
    def get(self,n1,n2,n3,n4):
        return self.thisptr.get(n1,n2,n3,n4)
    def getmbc(self):
        return self.thisptr.getmbc()
    def set(self,n1,n2,n3,n4,value):
        self.thisptr.set(n1,n2,n3,n4,value)

cdef class iTensor1:
    cdef testtensor.c_iTensor1 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n):
        self.thisptr = testtensor.new_iTensor1(n)
    def __dealloc__(self):
        testtensor.del_iTensor1(self.thisptr)
    def getsize(self):
        return self.thisptr.getsize()
    def get(self,n):
        return self.thisptr.get(n)
    def set(self,n,value):
        self.thisptr.set(n,value)



