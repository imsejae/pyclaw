#define _DOGBASE_H_
// --------------------------------------------------------------------------
//  DOGPACK base files (1d)
// --------------------------------------------------------------------------

#include "stdlib.h"
#include "tensors.h"

// RANK ONE TENSORS ----------------------------------------
class DOGBase
{
 public:
  // Constructor
  DOGBase();
  
  // Destructor
  ~DOGBase();    

  // L2Project function
  void L2Project(int mopt, int istart, int iend,
		 const dTensor2& node,
		 const dTensorBC3& qin, 
		 const dTensorBC3& auxin,  
		 dTensorBC3& Fout,
		 void (*Func)(const dTensor1&, const dTensor2&, const dTensor2&, dTensor2&));
  
  // Output function
  void Output(const dTensor2& node, 
	      const dTensorBC3& aux,
	      const dTensorBC3& q,
	      double t,
	      int nframe,
	      string outputdir);
  
  // Right-hand side function
  void ConstructL(const int method[],
		  const dTensor2& node,
		  dTensorBC3& aux,
		  dTensorBC3& q,
		  dTensorBC3& Lstar,
		  dTensorBC1& smax);

  // Runge-Kutta time-stepping method
  void DogSolveRK(const dTensor2& node, const dTensor1& prim_vol, dTensorBC3& aux, 
		  dTensorBC3& qold, dTensorBC3& qnew, dTensorBC1& smax,
		  double tstart, double tend,int nv, const int method[],
		  double dtv[], const double cflv[],string outputdir);

  // Function to compute CFL number
  double GetCFL(double dt,double dtmax,
		const dTensor1& prim_vol,
		const int method[],
		const dTensorBC3& aux,
		const dTensorBC1& smax);
  
  // Update the solution using the constructed Lstar
  void UpdateSoln(double alpha1,double alpha2,double beta,double dt,
		  const dTensor2& node,const dTensorBC3& aux,
		  const dTensorBC3& qstar, const dTensorBC3& Lstar,
		  dTensorBC3& qnew);

  
};
// ---------------------------------------------------------
