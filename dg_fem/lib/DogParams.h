#ifndef DOGPARAMS_H
#define DOGPARAMS_H
#include <stdio.h> // for FILE
#define MAX_NUM_SUBSYSTEMS 10
//#include <iosfwd> // for string*
//#include <string>
using namespace std;

class IniDocument;
enum DataFmt {ASCII=1,HDF5=5};
struct DogParams{
private:
  bool is_initialized;
  int ndims;
  char* mesh_type;
  int nout;
  double tfinal;
  double dtv[2+1];
  double cflv[2+1];
  int nv;
  char* time_stepping_method;
  char* limiter_method;
  int method[7+1];
  int meqn;
  int nrestart;
  DataFmt datafmt;
  int nout_per_restart;
  int how_many_plot_resolutions; int* nout_per_plot;
  // number of time steps per call to DogSolve*
  // at which ConSoln should print output (negative=always)
  // (see e.g. apps/plasma/2d/twofluid/g10/ConSoln.cpp for example of use)
  int num_subintervals;
  //
  // added by James
  double time;
   double dt;
  //
  int use_divfree;
  int how_many_vectors_divfree; int* which_compnt_divfree;
  //
  // derived parameters
  //
  int kmax;
  double frame_interval; // time interval per call to DogSolve*
  double frame_subinterval; // time interval per ConSoln output (0=always)
  int how_many_generic_components; int* generic_components;
  //
  // methods
  //
private:
  void setDerivedParameters();
  void set_kmax();
  void checkParameters();
  void checkParameters1();
  void checkParameters2();
   void reportParameters();
  void resetParameters();
public:
  
  ~DogParams();
DogParams():
  mesh_type(0),
    time_stepping_method(0),
    limiter_method(0),
    is_initialized(false), nout_per_plot(0),
    use_divfree(0), how_many_vectors_divfree(0), which_compnt_divfree(0),
    how_many_generic_components(0), generic_components(0),
    kmax(0)
  {}
  void init(IniDocument& ini_doc);
  void write_qhelp(const char* filename);
  void write_output_parameters_ini(const char* filename);
  
  bool get_is_initialized()const{return is_initialized;}
  int   get_ndims()   const{ return  ndims;}
  const char* get_mesh_type()            const{return mesh_type;}
  const char* get_time_stepping_method() const{return time_stepping_method;}
  const char* get_limiter_method()       const{return limiter_method;}
  int   get_nout()    const{ return  nout;}
  double get_tfinal() const{ return  tfinal;}
   const double* get_cflv() const{ return  cflv;}
  int   get_nv()           const{ return  nv;}
  // get_dtv() is deprecated
  const double* get_dtv()  const{ return  dtv;}
  // use these instead
  double get_initial_dt() const{ return dtv[1]; }
  double get_max_dt() const{ return dtv[2]; }
  // get_method is deprecated
  const int* get_method() const{ return  method;}
  // use these instead
  int    get_space_order()      const{ return method[1];}
  int    get_time_order()       const{ return method[2];}
  int    get_use_limiter()      const{ return method[3];}
  int    get_verbosity()        const{ return method[4];}
  int    get_mcapa()            const{ return method[5];}
  int    get_maux()             const{ return method[6];}
  int    get_source_term()      const{ return method[7];}
  int    get_meqn()             const{ return  meqn;}
  int    get_mrestart()         const{ if(nrestart >= 0) return 1; return 0;}
  int    get_nrestart()         const{ return  nrestart;}
  int    get_nstart()           const{ return  nout_per_restart*nrestart;}
  DataFmt get_datafmt()         const{ return  datafmt;}
  int get_num_subintervals()    const{ return  num_subintervals;}
  //
  double get_frame_interval()   const{ return frame_interval;}
  double get_frame_subinterval()const{ return frame_subinterval;}
  int get_nout_per_restart() const{ return nout_per_restart;}
  int get_how_many_plot_resolutions() const{ return how_many_plot_resolutions;}
  const int* get_nout_per_plot() const{ return nout_per_plot;}
  int get_kmax() const{ return kmax;}
  // merged from James
  double get_time() const { return time; }
  double get_dt()   const { return dt; }
  int get_use_divfree() const { return use_divfree; }
  int get_how_many_vectors_divfree()
    const { return how_many_vectors_divfree; }
  const int* get_which_compnt_divfree()
    const{ return which_compnt_divfree; }
  int get_how_many_generic_components()
    const{ return how_many_generic_components; }
  int get_generic_component(int i)
    const{ return generic_components[i]; }
  // public methods for setting should not exist
  // (this data is in the DogState class).
  void set_time(double in) { time = in; }
  void set_dt(double in)   { dt = in; }
  
  // convenience functions
  bool using_moment_limiter();
  bool using_viscosity_limiter();
  bool using_relax_limiter();
  bool using_positive_limiter();
};

extern DogParams dogParams;

#endif
