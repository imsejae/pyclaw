#include "tensors.h"

// Update the solution using the constructed Lstar
void UpdateSoln(double alpha1,double alpha2,double beta,double dt,
		const dTensor2& node,const dTensorBC3& aux,
		const dTensorBC3& qstar, const dTensorBC3& Lstar,
		dTensorBC3& qnew)
{
  const int melems = qnew.getsize(1);
  const int   meqn = qnew.getsize(2);
  const int   kmax = qnew.getsize(3);
  const int   maux = aux.getsize(2);
  const int mbc = qnew.getmbc();
  
  for (int k=1; k<=kmax; k++)
    for (int m=1; m<=meqn; m++)        
      for (int j=(2-mbc); j<=(melems+mbc-1); j++)
	{
	  double tmp = alpha1*qstar.get(j,m,k) + alpha2*qnew.get(j,m,k)
	    + beta*dt*Lstar.get(j,m,k);
	  
	  qnew.set(j,m,k, tmp );
	}
  
  // Optional call to modify updated solution
  void AfterUpdateSoln(const dTensor2& node,
		       const dTensorBC3& aux,
		       dTensorBC3& q,
		       double dt,
		       double beta);
  AfterUpdateSoln(node,aux,qnew,dt,beta); 
}
