#include <cmath>
#include "dogdefs.h"

// This is a user-supplied routine that sets the
// auxiliary arrays at all the points "xpts"
//
//  --------------------------------------------------------
//  NOTE: Two input values "NOT_USED_1" and "NOT_USED_2"
//        are never used in this function. The reason 
//        these variables are included in the input list
//        is to make "AuxFunc.cpp" conform with the format
//        required by "L2Project.cpp".
//  --------------------------------------------------------
//
void AuxFunc(const dTensor1& xpts, 
	     const dTensor2& NOT_USED_1,
             const dTensor2& NOT_USED_2, 
	     dTensor2& auxvals)
{

    int i;
    int numpts=xpts.getsize();
    double x;
    
    for (i=1; i<=numpts; i++)
    {
      x = xpts.get(i);
	
      auxvals.set(i,1, 2.0e0 );
    }

}