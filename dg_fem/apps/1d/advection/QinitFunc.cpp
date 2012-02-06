#include <cmath>
#include "../../../lib/1d/DOGUserC1D.h"
#include "../../../lib/1d/constants.h"

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
void DOGUserC1D::QinitFunc(const dTensor1& xpts, 
			   const dTensor2& NOT_USED_1,
			   const dTensor2& NOT_USED_2, 
			   dTensor2& qvals)
{
  const int numpts=xpts.getsize();
  const double width = 2.0*0.25;

  for (int i=1; i<=numpts; i++)
    {
      double x = xpts.get(i);
      double s = x-0.5;
      
      if ( fabs(s) > width/2.0 )
	{ qvals.set(i,1, 0.0e0 ); }
      else
	{ qvals.set(i, 1,  pow(cos(pi*s/width),6) ); }
      
    }

}

