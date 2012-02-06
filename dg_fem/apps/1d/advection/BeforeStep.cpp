#include "DOGUserC1D.h"

// Function that is called before each time step
void DOGUserC1D::BeforeStep(double dt, const dTensor2& node, dTensorBC3& aux, dTensorBC3& q)
{
  const int melems = q.getsize(1);
  const int   meqn = q.getsize(2);
  const int   kmax = q.getsize(3);
  const int   maux = aux.getsize(2);  
}
