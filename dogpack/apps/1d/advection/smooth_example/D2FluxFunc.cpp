#include "dogdefs.h"

// This is a user-supplied routine that sets the
// Derivative of the Jacobian of the Flux Function.  
// In 1d this is a 3-tensor of size numpts x meqn x meqn x meqn
//
//     D2flux(:, i, j, k) = \partial^2 f_i / \partial q_j \partial q_k
//
//     Simple Advection Equation
//
void D2FluxFunc(const dTensor1& xpts, 
		const dTensor2& Q,
		const dTensor2& Aux, 
		dTensor4& D2flux)
{
  int i;
  int numpts=xpts.getsize();
  double x;
  double h,u;

  for (i=1; i<=numpts; i++)
  {
    x = xpts.get(i);

    // 2nd Derivative of Flux function
    D2flux.set(i, 1, 1, 1, 0.0e0 );

  }    
}
