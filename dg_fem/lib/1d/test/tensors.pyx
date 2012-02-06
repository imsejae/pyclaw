
cdef extern from "tensors.h":
    ctypedef struct c_dTensor1 "dTensor1":
        double& get(int n)
        void set(int n, double value)
        int getsize()
    c_dTensor1 *new_dTensor1 "new dTensor1" (int n)
    void del_dTensor1 "delete" (c_dTensor1 *dTens)


    ctypedef struct c_dTensorBC1 "dTensorBC1":
        double& get(int n)
        void set(int n, double value)
        int getsize()
        int getmbc()
    c_dTensorBC1 *new_dTensorBC1 "new dTensorBC1" (int n,int mbc)
    void del_dTensorBC1 "delete" (c_dTensorBC1 *dTens)

    ctypedef struct c_dTensor2 "dTensor2":
        double& get(int n1,int n2)
        void set(int n1,int n2, double value)
        int getsize(int n)
    c_dTensor2 *new_dTensor2 "new dTensor2" (int n1,int n2)
    void del_dTensor2 "delete" (c_dTensor2 *dTens)

    ctypedef struct c_iTensor2 "iTensor2":
        int& get(int n1,int n2)
        void set(int n1,int n2, int value)
        int getsize(int n)
    c_iTensor2 *new_iTensor2 "new iTensor2" (int n1,int n2)
    void del_iTensor2 "delete" (c_iTensor2 *dTens)

    ctypedef struct c_dTensorBC2 "dTensorBC2":
        double& get(int n1,int n2)
        void set(int n1,int n2, double value)
        int getsize(int n)
        int getmbc()
    c_dTensorBC2 *new_dTensorBC2 "new dTensorBC2" (int n1,int n2,int mbc)
    void del_dTensorBC2 "delete" (c_dTensorBC2 *dTens)

    ctypedef struct c_dTensor3 "dTensor3":
        double& get(int n1,int n2,int n3)
        void set(int n1,int n2,int n3, double value)
        int getsize(int n)
    c_dTensor3 *new_dTensor3 "new dTensor3" (int n1,int n2,int n3)
    void del_dTensor3 "delete" (c_dTensor3 *dTens)

    ctypedef struct c_iTensor3 "iTensor3":
        int& get(int n1,int n2,int n3)
        void set(int n1,int n2,int n3, int value)
        int getsize(int n)
    c_iTensor3 *new_iTensor3 "new iTensor3" (int n1,int n2,int n3)
    void del_iTensor3 "delete" (c_iTensor3 *dTens)

    ctypedef struct c_dTensorBC3 "dTensorBC3":
        double& get(int n1,int n2,int n3)
        void set(int n1,int n2,int n3, double value)
        int getsize(int n)
        int getmbc()
    c_dTensorBC3 *new_dTensorBC3 "new dTensorBC3" (int n1,int n2,int n3,int mbc)
    void del_dTensorBC3 "delete" (c_dTensorBC3 *dTens)

    ctypedef struct c_dTensor4 "dTensor4":
        double& get(int n1,int n2,int n3,int n4)
        void set(int n1,int n2,int n3,int n4, double value)
        int getsize(int n)
    c_dTensor4 *new_dTensor4 "new dTensor4" (int n1,int n2,int n3,int n4)
    void del_dTensor4 "delete" (c_dTensor4 *dTens)

    ctypedef struct c_dTensorBC4 "dTensorBC4":
        double& get(int n1,int n2,int n3,int n4)
        void set(int n1,int n2,int n3,int n4, double value)
        int getsize(int n)
        int getmbc()
    c_dTensorBC4 *new_dTensorBC4 "new dTensorBC4" (int n1,int n2,int n3,int n4,int mbc)
    void del_dTensorBC4 "delete" (c_dTensorBC4 *dTens)

    ctypedef struct c_iTensor1 "iTensor1":
        int& get(int n)
        void set(int n, int value)
        int getsize()
    c_iTensor1 *new_iTensor1 "new iTensor1" (int n)
    void del_iTensor1 "delete" (c_iTensor1 *iTens)


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

cdef class dTensorBC1:
    cdef c_dTensorBC1 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n,int mbc):
        self.thisptr = new_dTensorBC1(n,mbc)
    def __dealloc__(self):
        del_dTensorBC1(self.thisptr)
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
    cdef c_dTensor2 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2):
        self.thisptr = new_dTensor2(n1,n2)
    def __dealloc__(self):
        del_dTensor2(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2):
        return self.thisptr.get(n1,n2)
    def set(self,n1,n2,value):
        self.thisptr.set(n1,n2,value)

cdef class iTensor2:
    cdef c_iTensor2 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2):
        self.thisptr = new_iTensor2(n1,n2)
    def __dealloc__(self):
        del_iTensor2(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2):
        return self.thisptr.get(n1,n2)
    def set(self,n1,n2,value):
        self.thisptr.set(n1,n2,value)

cdef class dTensorBC2:
    cdef c_dTensorBC2 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int mbc):
        self.thisptr = new_dTensorBC2(n1,n2,mbc)
    def __dealloc__(self):
        del_dTensorBC2(self.thisptr)
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
    cdef c_dTensor3 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3):
        self.thisptr = new_dTensor3(n1,n2,n3)
    def __dealloc__(self):
        del_dTensor3(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3):
        return self.thisptr.get(n1,n2,n3)
    def set(self,n1,n2,n3,value):
        self.thisptr.set(n1,n2,n3,value)

cdef class iTensor3:
    cdef c_iTensor3 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3):
        self.thisptr = new_iTensor3(n1,n2,n3)
    def __dealloc__(self):
        del_iTensor3(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3):
        return self.thisptr.get(n1,n2,n3)
    def set(self,n1,n2,n3,value):
        self.thisptr.set(n1,n2,n3,value)

cdef class dTensorBC3:
    cdef c_dTensorBC3 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3,int mbc):
        self.thisptr = new_dTensorBC3(n1,n2,n3,mbc)
    def __dealloc__(self):
        del_dTensorBC3(self.thisptr)
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
    cdef c_dTensor4 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3,int n4):
        self.thisptr = new_dTensor4(n1,n2,n3,n4)
    def __dealloc__(self):
        del_dTensor4(self.thisptr)
    def getsize(self,int n):
        return self.thisptr.getsize(n)
    def get(self,n1,n2,n3,n4):
        return self.thisptr.get(n1,n2,n3,n4)
    def set(self,n1,n2,n3,n4,value):
        self.thisptr.set(n1,n2,n3,n4,value)

cdef class dTensorBC4:
    cdef c_dTensorBC4 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n1,int n2,int n3,int n4,int mbc):
        self.thisptr = new_dTensorBC4(n1,n2,n3,n4,mbc)
    def __dealloc__(self):
        del_dTensorBC4(self.thisptr)
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
    cdef c_iTensor1 *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int n):
        self.thisptr = new_iTensor1(n)
    def __dealloc__(self):
        del_iTensor1(self.thisptr)
    def getsize(self):
        return self.thisptr.getsize()
    def get(self,n):
        return self.thisptr.get(n)
    def set(self,n,value):
        self.thisptr.set(n,value)

