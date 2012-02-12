#include <cmath>
#include "dogdefs.h"

// This is a user-supplied routine that sets the
// initial conditions at all the points "xpts"
//
//  --------------------------------------------------------
//  NOTE: Two input values "NOT_USED_1" and "NOT_USED_2"
//        are never used in this function. The reason 
//        these variables are included in the input list
//        is to make "QinitFunc.cpp" conform with the format
//        required by "L2Project.cpp".
//  --------------------------------------------------------
//
void QinitFunc(const dTensor2& xpts, dTensor2& qvals)
{
  int i;
  int numpts=xpts.getsize(1);
  double x,y,r,r2;
  
  for (i=1; i<=numpts; i++)
    {
      x = xpts.get(i,1);
      y = xpts.get(i,2);
      
      r2 = pow(x-0.40,2)+pow(y-0.50,2);
      r  = sqrt(r2);
      
      if (r<0.3)
        {  
	  qvals.set(i,1, pow( cos(5.0/3.0*pi*r) ,6) );  
        }
      else
        {  qvals.set(i,1, 0.0 ); }
    }
}
