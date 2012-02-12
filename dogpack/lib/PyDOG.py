import os
import pyclaw
import numpy as np
def runDOG(iplot=False,htmlplot=False,outputdir='output'):
    # call dogpack and output to specified (or not) directory
    os.system('dog.exe -o %s' % outputdir)
    if iplot:
      pyclaw.plot.interactive_plot('_output','asciiy')
    if htmlplot:  
      pyclaw.plot.html_plot('_output','asciiy')
#def load_DG_app(outputdir='output'):
        
