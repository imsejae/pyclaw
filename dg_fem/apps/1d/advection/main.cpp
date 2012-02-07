#include "../../../lib/1d/tensors.h"
#include "../../../lib/1d/DOGUserC1D.h"
#include "../../../lib/1d/DOGBaseC1D.h"
#include "../../../lib/1d/DogParams.h"
#include "../../../lib/1d/DogParamsCart1.h"

// =========================================================================
//
//  Copyright J.A. Rossmanith
//
//  This software is made available for research and instructional use only.
//  You may copy and use this software without charge for these non-commercial
//  purposes, provided that the copyright notice and associated text is
//  reproduced on all copies.  For all other uses (including distribution of
//  modified versions), please contact the author at the address given below.
//
//  *** This software is made available "as is" without any assurance that it
//  *** will work for your purposes.  The software may in fact have defects, so
//  *** use the software at your own risk.
//
//    Author:  James A. Rossmanith
//             Department of Mathematics
//             University of Wisconsin
//             Madison, WI 53706
//             rossmani@math.wisc.edu
// =========================================================================

int main()
{  
  // Parameters
  DogParams dogParams;
  DogParamsCart1 dogParamsCart1;
  void Initialize(DogParams& dogParams,
		  DogParamsCart1& dogParamsCart1);
  Initialize(dogParams,dogParamsCart1);

  // Create solution array
  int mx = dogParamsCart1.get_mx();
  int mbc = dogParamsCart1.get_mbc();
  int meqn = dogParams.get_meqn();
  int kmax = dogParams.get_kmax();
  dTensorBC3 q(mx,meqn,kmax,mbc);

  // Run the startscript
  void RunStartScript(int dim);
  RunStartScript(1);

  // Call the ``RunDogpack'' routine, which executes the
  // discontinuous Galerkin code
  int RunDogpack(const DogParams& dogParams,
		 const DogParamsCart1& dogParamsCart1,
		 dTensorBC3& q);
  int m = RunDogpack(dogParams,dogParamsCart1,q);
  return m;
}
