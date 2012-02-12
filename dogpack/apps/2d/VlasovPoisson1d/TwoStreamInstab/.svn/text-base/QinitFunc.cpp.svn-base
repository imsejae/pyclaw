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
    double x,y;

    for (i=1; i<=numpts; i++)
    {
        x = xpts.get(i,1);
        y = xpts.get(i,2);

        qvals.set(i, 1, 
            pow(y,2) / sqrt(2.0*pi) * (
                1.0-0.5*cos(0.5*x) ) * exp( -0.5 * pow(y,2) ) );
    }

}
