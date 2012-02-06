#include "../../../lib/1d/tensors.h"
#include "../../../lib/1d/DOGUserC1D.h"
#include "../../../lib/1d/DOGBaseC1D.h"
#include "../../../lib/1d/DOGDataC1D.h"

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
  // Create dogData object
  DOGDataC1D dogDataC1D;
  
  // Parameters
  void Initialize(DOGDataC1D& dogDataC1D);
  Initialize(dogDataC1D);

  // Create solution area
  dTensorBC3 q(1,1,1,1);

  // Run the startscript
  void RunStartScript(int dim);
  RunStartScript(1);

  // Call the ``RunDogpack'' routine, which executes the
  // discontinuous Galerkin code
  int RunDogpack(DOGDataC1D& dogDataC1D, dTensorBC3& q);
  int m = RunDogpack(dogDataC1D,q);
  
  return m;
}
