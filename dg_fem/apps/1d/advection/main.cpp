#include "dogdefs.h"

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
  // Declare DOGBASE object
  DOGBaseC1D dogBaseC1D();
  DOGUserC1D dogUserC1D();
  
  // Parameters and output directory
  dogBaseC1D.Initialize();
  /*
  ini_doc.initFromFile("parameters.ini");
  IniDocument::Section& ini_sec = ini_doc["dogParams"];
  DogSolver::parse_arguments();
  */

  // Run the startscript
  dogBaseC1D.RunStartScript(1);

  // Call the ``RunDogpack'' routine, which executes the
  // discontinuous Galerkin code
  int m;
  string outputdir = "output";
  //m = dogBaseC1D.RunDogpack(outputdir);
  
  return m;
}
