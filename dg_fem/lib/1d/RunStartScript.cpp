#include <stdlib.h> // for system()
#include <stdio.h>

void RunStartScript(int ndims)
{
  // run startscript
  // to create output directory if it does not exist
  // and copy data files to output directory
  char command_str[1024];
  //const char* get_outputdir();
  int numchars = snprintf(command_str,1024,
    "if test -f startscript && test -x startscript;\n"
    "then ./startscript %s %d\n"
    "else ${PYCLAW}/dg_fem/scripts/startscript %s %d\n"
    "fi", "output",ndims,"output",ndims);
  int exit_status = system(command_str);
}
