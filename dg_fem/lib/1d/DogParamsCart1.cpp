#include <stdlib.h> // for exit()
#include <sstream>
#include "DogParamsCart1.h"
using namespace std;

void DogParamsCart1::set_xlims(double xlow_in, double xhigh_in)
{
    xlow = xlow_in;
    xhigh = xhigh_in;
    dx = (xhigh-xlow)/mx;
}

// It does not make sense to define defaults for
// these options, so we do not use the defaults
// mechanism used e.g. in DogParams::init
void DogParamsCart1::init(const int mx_in,
			  const int mbc_in,
			  const int xlow_in,
			  const int xhigh_in)
{
  if(is_initialized) 
    {
      return;
    }

  mx    = mx_in;
  mbc   = mbc_in;
  xlow  = xlow_in;
  xhigh = xhigh_in;

  set_xlims(xlow, xhigh);

  checkParameters();
  setDerivedParameters();
  reportParameters();

  is_initialized = true;
}

void DogParamsCart1::reportParameters()
{
  printf(  "   === parameters from [grid] ===");
  printf("\n   mx   : %d", mx   );
  printf("\n   mbc  : %d", mbc  );
  printf("\n   xlow : %f", xlow );
  printf("\n   xhigh: %f", xhigh);
  printf("\n   --- parameters derived from [grid] ---");
  printf("\n   dx   : %f ", dx);
  printf("\n");
}

void DogParamsCart1::setDerivedParameters()
{
    dx = (xhigh-xlow)/mx;
}

void DogParamsCart1::checkParameters()
{
  if(mx <= 0) printf("ERROR: mx=%d must be positive.\n",mx);
  if(mbc < 0) printf("ERROR: mbc=%d must be nonnegative.\n",mbc);
  if((xhigh-xlow) <= 0) 
    {
      printf("ERROR: xhigh=%e should be greater than"
	     " xlow=%e\n", xhigh, xlow);
    }
}
