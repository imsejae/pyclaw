#include "DogParams.h"
#include "DogParamsCart1.h"

void Initialize(DogParams& dogParams,
		DogParamsCart1& dogParamsCart1)
{
  dogParams.init();
  dogParamsCart1.init(200,2,0.0,1.0);
}
