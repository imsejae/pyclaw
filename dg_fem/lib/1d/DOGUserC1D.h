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

  // 

 private:
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
 
};
// ---------------------------------------------------------
