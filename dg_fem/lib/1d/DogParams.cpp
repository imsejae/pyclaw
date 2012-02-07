#include "DogParams.h"
#include "constants.h"
#include <stdlib.h>
#include <float.h> // for DBL_MAX
#include <cstring>
#include <string>

DogParams::~DogParams()
{
  //free(mesh_type);
  //free(time_stepping_method);
  //free(limiter_method);
  delete [] nout_per_plot;
  delete [] which_compnt_divfree;
  delete [] generic_components;
}

void DogParams::set_kmax()
{
  switch(ndims)
  {
  case 1:
    kmax = get_space_order();
    break;
  case 2:
    kmax = get_space_order()*(get_space_order()+1)/2;
    break;
  default:
    printf("ndims = %i is unsupported\n",ndims);
    exit(1);
  }
}

// access defaults from a file that other applications
// (e.g. matlab) might also want to read
void DogParams::init()
{
  if(is_initialized) 
    {
      return;
    }

  ndims   = 1;
  nout    = 10;
  tfinal  = 1.0;
  dtv[1]  = 0.002;
  dtv[2]  = 1.0e10;
  cflv[1] = 1.00;
  cflv[2] = 0.95;
  nv      = 500000;
  string tsm = "Runge-Kutta";
  time_stepping_method = &tsm[0];
  string lm = "moment";
  limiter_method = &lm[0];
  string mt = "Cartesian";
  mesh_type = &mt[0];
  method[1] = 4;
  method[2] = 4;
  method[3] = 0;
  method[4] = 1;
  method[5] = 0;
  method[6] = 1;
  method[7] = 0;
  meqn      = 1;
  datafmt   = 1;
  nrestart  = -1;

  resetParameters();
  setDerivedParameters();

  checkParameters();
  reportParameters();

  is_initialized = true;
}

void DogParams::resetParameters()
{
  if (str_eq(time_stepping_method, "SDC") && get_time_order()==1)
      {
        free(time_stepping_method);
	time_stepping_method = strdup("Runge-Kutta");
        printf(
	  "   NOTE:  1st order SDC is the same as 1st order Runge-Kutta. \n"
	  "          The program will use time_stepping_method = %s\n\n",
	  time_stepping_method);
      }
}

void DogParams::setDerivedParameters()
{
  set_kmax();
  // set generic_components lookup table
  // (and how_many_generic_components)
  //
  generic_components = new int[meqn+1];
  if(use_divfree)
  {
    for(int i=0;i<=meqn;i++) generic_components[i]=-1;
    int generic_component=0;
    for(int m=1;m<=meqn;m++)
    {
      bool is_generic = true;
      // check if m is not generic
      for(int i=1;i<=how_many_vectors_divfree;i++)
      {
        if(m==which_compnt_divfree[i] || m==which_compnt_divfree[i]+1)
          is_generic=false;
      }
      if(is_generic) generic_components[++generic_component]=m;
    }
    how_many_generic_components = generic_component;
  }
  else
  {
    for(int i=0;i<=meqn;i++) generic_components[i]=i;
    how_many_generic_components = meqn;
  }
  // dprint(how_many_generic_components);

  frame_interval = tfinal/nout;
  if(num_subintervals > EPSILON)
    frame_subinterval = frame_interval/num_subintervals;
  else if(num_subintervals < -EPSILON) // infinity
    frame_subinterval = 0;
  else
    frame_subinterval = DBL_MAX; //numeric_limits<double>::max();
}

void DogParams::checkParameters()
{
    // check cflv
    if (cflv[2] >= cflv[1])
    {
      printf("desired CFL must be strictly smaller than max CFL\n");
    }

    int& space_order = method[1];
    int& time_order  = method[2];
    int& use_limiter = method[3];
    int& verbosity   = method[4];
    int& mcapa       = method[5];
    int& maux        = method[6];
    int& source_term = method[7];

    // check mcapa
    if (mcapa > maux)
      {
	printf("mcapa cannot be larger than maux \n");
      }
  
    // check meqn
    if (meqn < 1)
      {
	printf("meqn must be at least 1 \n");
      }

    if (use_limiter<0 || use_limiter>1)
      {
	printf("use_limiter must be set either 0 or 1: use_limiter = %i",use_limiter);
      }
  
    // check ndims
    switch(ndims)
    {
        case 1:
          checkParameters1();
          break;
        case 2:
          checkParameters2();
          break;
        default:
          printf(" ERROR: number of dimensions must be set to 1 or 2.\n\n");
    }
}

// checks based on what has been implemented for one dimension
//
void DogParams::checkParameters1()
{
  if(get_mrestart())
    {
      printf("DogParams: restarting from data has not yet ",
	     "been implemented for one dimension.");
    }
  
  // check space_order
  if (get_space_order()<1 || get_space_order()>5 )
    {
      printf("incorrect spatial accuracy,",
	     " must have space_order = 1, 2, 3, 4, or 5 ");
    }  
  
  // check time_stepping_method
  if (!str_eq(time_stepping_method, "Runge-Kutta") &&
      !str_eq(time_stepping_method, "SDC") &&
      !str_eq(time_stepping_method, "Lax-Wendroff") &&
      !str_eq(time_stepping_method, "User-Defined") &&
      !str_eq(time_stepping_method, "LxW_synch") &&
      !str_eq(time_stepping_method, "LxW_asynch"))
    {
      printf("the time-stepping method %s",time_stepping_method,
	     " has not been implemented. \n\n",
	     " The available options are \n",
	     "   1. Runge-Kutta \n",
	     "   2. SDC \n",
	     "   3. Lax-Wendroff \n",
	     "   4. User-Defined \n");
    }
  
  // checks per time_stepping_method
  if (str_eq(time_stepping_method, "Runge-Kutta"))
    {
      if (get_time_order()<0 || get_time_order()>5)
	{
	  printf("Runge-Kutta must have time_order = 1, 2, 3, or 4 \n");
	}
    }
  else if (str_eq(time_stepping_method, "SDC"))
    {
      if (get_time_order()<0 || get_time_order()>5)
	{
	  printf("SDC must have time_order = 1, 2, 3, 4, or 5 \n");
	}
    }
  else if (str_eq(time_stepping_method, "Lax-Wendroff"))
    {
      if (get_time_order()<0 || (get_time_order()>5 ) )
	{
	  printf("Lax-Wendroff must have time_order = 1, 2, 3, 4, or 5 \n");
	}
    }

  // check limiter method
  if (!str_eq(limiter_method, "moment") &&
      !str_eq(limiter_method, "viscosity") &&
      !str_eq(limiter_method, "relax"))
    {
      printf("the limiter method %s",limiter_method,
	     " has not been implemented. \n\n",
	     " The available options are \n",
	     "   1. moment \n");
    }
  
}

// checks based on what has been implemented for two dimensions
//
void DogParams::checkParameters2()
{
    // check space_order
    if (get_space_order()<1 || get_space_order()>5 )
    {
      printf("invalid spatial accuracy,",
	     " must have space_order = 1, 2, 3, 4, or 5 ");
    }  

    // check time_stepping_method
    if (!str_eq(time_stepping_method, "Runge-Kutta") &&
        !str_eq(time_stepping_method, "SDC") &&
        !str_eq(time_stepping_method, "Lax-Wendroff") && 
        !str_eq(time_stepping_method, "User-Defined") )
      {
	printf("the time-stepping method ", time_stepping_method,
	       " has not been implemented. \n\n",
	       " The available options are \n",
	       "   1. Runge-Kutta \n",
	       "   2. SDC \n",
	       "   3. Lax-Wendroff \n",
	       "   4. User-Defined \n");
      }

    // check time_order per time_stepping_method
    if (str_eq(time_stepping_method, "Runge-Kutta") )
      {
	if (get_time_order()<0 || get_time_order()>5)
	  {
	    printf("Runge-Kutta must have time_order = 1, 2, 3, 4, or 5 ");
	  }
      }
    else if (str_eq(time_stepping_method, "SDC"))
      {
        if (get_time_order()<0 || get_time_order()>5)
	  {
            printf("SDC must have time_order = 1, 2, 3, 4, or 5 ");
	  }
      }
    else if (str_eq(time_stepping_method, "Lax-Wendroff"))
      {
        if (get_time_order()<0 || (get_time_order()>3 ) )
	  {
            printf("Lax-Wendroff must have time_order = 1, 2, or 3 ");
	  }
      }

    // check limiter method
    if (!str_eq(limiter_method, "moment") &&
        !str_eq(limiter_method, "viscosity") &&
        !str_eq(limiter_method, "positive"))
      {
	printf("the limiter method %s",limiter_method,
	       " has not been implemented. \n\n",
	       " The available options are \n",
	       "   1. moment \n",
	       "   2. viscosity \n",
	       "   3. positive \n");
      }

}

void DogParams::reportParameters()
{
  // Output parameters to screen
  printf(
    "   === parameters from [dogParams] ===\n"
    "                      Mesh Type:  %s\n"
    "   Number of Spatial Dimensions:  %d\n"
    "            Number of Equations:  %d\n"
    "      Order of Accuracy in Time:  %d\n"
    "     Order of Accuracy in Space:  %d\n"
    "           Time-Stepping Method:  %s\n"
    "                 Limiter Method:  %s\n"
    "                       Limiters:  %s\n"
    "         desired Courant number:  %f\n",
    mesh_type,ndims,meqn,
    get_time_order(),get_space_order(),
    time_stepping_method,limiter_method,
    get_use_limiter()?"yes":"no",cflv[2]);
  printf("\n");
}

void DogParams::write_qhelp(const char* filename)
{
  FILE* file = fopen(filename,"w");
  fprintf(file,"%s\n",mesh_type);
  fprintf(file,"%d\n", meqn);
  fprintf(file,"%d\n", get_maux());
  fprintf(file,"%d\n", nout);
  fprintf(file,"%d\n", get_space_order());
  fclose(file);
}

void DogParams::write_output_parameters_ini(const char* filename)
{
  FILE* file = fopen(filename,"w");
  fprintf(file,"[dogParams]\n");
  fprintf(file,"mesh_type = %s\n", mesh_type);
  fprintf(file,"meqn = %d\n", meqn);
  fprintf(file,"maux = %d\n", get_maux());
  fprintf(file,"nout = %d\n", nout);
  fprintf(file,"space_order = %d\n", get_space_order());
  fprintf(file,"datafmt = %d\n",get_datafmt());
  fclose(file);
}

bool DogParams::using_positive_limiter()
{
  return (get_use_limiter()==1 && str_eq(get_limiter_method(),"positive"));
}

bool DogParams::using_moment_limiter()
{
  return (get_use_limiter()==1 && str_eq(get_limiter_method(),"moment"));
}

bool DogParams::using_viscosity_limiter()
{
  return (get_use_limiter()==1 && str_eq(get_limiter_method(),"viscosity"));
}

bool DogParams::using_relax_limiter()
{
  return (get_use_limiter()==1 && str_eq(get_limiter_method(),"relax"));
}


bool DogParams::str_eq(const char* str1, const char* str2)
{
  // for case-insensitive matching change this to strcasecmp
  return !strcmp(str1,str2);
}
