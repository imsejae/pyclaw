#define _DOGUserC1D_H_
// --------------------------------------------------------------------------
//  DOGPACK user files (1d)
// --------------------------------------------------------------------------

#include "stdlib.h"
#include "tensors.h"

// RANK ONE TENSORS ----------------------------------------
class DOGUserC1D
{
 public:
  // Constructor
  DOGUserC1D();
  
  // Destructor
  ~DOGUserC1D();    

  // Initial condition
  void QinitFunc(const dTensor1& xpts, 
		 const dTensor2& NOT_USED_1,
		 const dTensor2& NOT_USED_2, 
		 dTensor2& qvals);

  // Aux array
  void AuxFunc(const dTensor1& xpts, 
	       const dTensor2& NOT_USED_1,
	       const dTensor2& NOT_USED_2, 
	       dTensor2& auxvals);

  // Flux function
  void FluxFunc(const dTensor1& xpts, 
		const dTensor2& Q,
		const dTensor2& Aux, 
		dTensor2& flux);

  // Set wave speed for Riemann solver
  void SetWaveSpd(const dTensor1& xedge,
		  const dTensor1& Ql,
		  const dTensor1& Qr,
		  const dTensor1& Auxl,
		  const dTensor1& Auxr,
		  double& s1,double& s2);

  // Project onto right eigenvectors for limiting
  void ProjectRightEig(const dTensor1& Aux_ave, 
		       const dTensor1& Q_ave, 
		       const dTensor2& Wvals,
		       dTensor2& Qvals);

  // Project onto left eigenvectors for limiting
  void ProjectLeftEig(const dTensor1& Aux_ave, 
		      const dTensor1& Q_ave,
		      const dTensor2& Qvals,
		      dTensor2& Wvals);

  // Set values in ghost cells to specify boundary conditions
  void SetBndValues(const dTensor2& node, 
		    dTensorBC3& aux, 
		    dTensorBC3& q);

  // Source term function
  void SourceTermFunc(const dTensor1& xpts, 
		      const dTensor2& qvals, 
		      const dTensor2& auxvals,
		      dTensor2& fvals);

  // Do something before each stage in method
  void BeforeStep(double dt, const dTensor2& node, dTensorBC3& aux, dTensorBC3& q);

  // Do something after each stage in method
  void AfterStep(double dt, const dTensor2& node, dTensorBC3& aux, dTensorBC3& q);

  // Do something after full time step in method
  void AfterFullTimeStep(double dt, const dTensor2& node, const dTensor1& prim_vol,
			 dTensorBC3& auxold, dTensorBC3& aux, 
			 dTensorBC3& qold, dTensorBC3& q);

};
// ---------------------------------------------------------
