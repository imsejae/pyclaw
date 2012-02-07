#include <string>
#include "DogParams.h"
#include "DogParamsCart1.h"

void Initialize(char* outputdir,
		DogParams& dogParams,
		DogParamsCart1& dogParamsCart1)
{
  string tmpstring = "output";
  outputdir = &tmpstring[0];
  printf(" dude = %s\n",outputdir);
  dogParams.init();
  dogParamsCart1.init(200,2,0.0,1.0);
}
