from PyDOG import runDOG
import pyclaw
def advection2drot_unst(iplot=False,htmlplot=False,outputdir='output'):
 if iplot:
  runDOG(True,False,outputdir) 
 elif htmlplot:
  runDOG(False,True,outputdir)
 else:
  runDOG(False,False,outputdir)
 

if __name__=="__main__":
    import sys
    from pyclaw.util import run_app_from_main
    output = run_app_from_main(advection2drot_unst)
