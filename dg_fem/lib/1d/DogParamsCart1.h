#ifndef DOGPARAMSCART1_H
#define DOGPARAMSCART1_H

struct DogParamsCart1{
 private:
   bool is_initialized;
   int mx;
   int mbc;
   double xlow;
   double xhigh;
   double dx; // calculated

 //
 // methods
 //
private:
  void checkParameters();
  void setDerivedParameters();
public:
  bool get_is_initialized(){return is_initialized;}
  void reportParameters();
  
  DogParamsCart1(){is_initialized=false;}

  void init(const int mx_in,
	    const int mbc_in,
	    const int xlow_in,
	    const int xhigh_in);
    
   const int   & get_mx()    const{ return  mx;   }
   const int   & get_melems()    const{ return  mx;   }
   const int   & get_mbc()   const{ return  mbc;  }
   const double& get_xlow()  const{ return  xlow; }
   const double& get_xhigh() const{ return  xhigh;}
   const double& get_dx()    const{ return  dx;   }

   void set_mx(int mx_in){ mx = mx_in; }
   void set_xlims(double,double);
};

#endif
