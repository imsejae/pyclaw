#include "../../../lib/1d/DOGUserC1D.h"

// This is a user-supplied routine that sets the source term
void DOGUserC1D::SourceTermFunc(const dTensor1& xpts, 
				const dTensor2& qvals, 
				const dTensor2& auxvals,
				dTensor2& fvals)
{
  const int numpts=xpts.getsize();
  const int meqn=qvals.getsize(2);
  
  for (int i=1; i<=numpts; i++)
    {
      double x = xpts.get(i);
      
      for (int me=1; me<=meqn; me++)
        {
          fvals.set(i,me, 0.0 );
        }
    }           
        
}
