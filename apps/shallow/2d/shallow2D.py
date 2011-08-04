#!/usr/bin/env python
# encoding: utf-8

"""
2D shallow water equations.
"""
#===========================================================================
# Import libraries
#===========================================================================

import numpy as np
from petclaw import plot
#import pdb


def qinit(state,hl,ul,vl,hr,ur,vr,radDam):
    x0=0.
    y0=0.
    xCenter = state.grid.x.center
    yCenter = state.grid.y.center
    Y,X = np.meshgrid(yCenter,xCenter)
    r = np.sqrt((X-x0)**2 + (Y-y0)**2)
    state.q[0,:,:] = hl*(r<=radDam) + hr*(r>radDam)
    state.q[1,:,:] = hl*ul*(r<=radDam) + hr*ur*(r>radDam)
    state.q[2,:,:] = hl*vl*(r<=radDam) + hr*vr*(r>radDam)

    
def shallow2D(use_petsc=False,iplot=0,htmlplot=False,outdir='./_output',solver_type='classic'):
    #===========================================================================
    # Import libraries
    #===========================================================================
    import numpy as np

    if use_petsc:
        import petclaw as pyclaw
        print "yes"
    else:
        import pyclaw

    #===========================================================================
    # Setup solver and solver parameters
    #===========================================================================
    if solver_type == 'classic':
        solver = pyclaw.ClawSolver2D()
    elif solver_type == 'sharpclaw':
        solver = pyclaw.SharpClawSolver2D()

    solver.mwaves = 3
    solver.limiters = pyclaw.limiters.tvd.MC

    solver.mthbc_lower[0] = pyclaw.BC.reflecting
    solver.mthbc_upper[0] = pyclaw.BC.outflow
    solver.mthbc_lower[1] = pyclaw.BC.reflecting
    solver.mthbc_upper[1] = pyclaw.BC.outflow
    solver.dim_split=1

    #===========================================================================
    # Initialize grids, then initialize the solution associated to the grid and
    # finally initialize aux array
    #===========================================================================

    # Grid:
    xlower = -2.5
    xupper = 2.5
    mx = 600
    ylower = -2.5
    yupper = 2.5
    my = 600
    x = pyclaw.Dimension('x',xlower,xupper,mx)
    y = pyclaw.Dimension('y',ylower,yupper,my)
    grid = pyclaw.Grid([x,y])
    state = pyclaw.State(grid)

    state.meqn = 3  # Number of equations

    # Parameters
    grav = 1.0
    state.aux_global['grav'] = grav

    # Initial solution
    # ================
    # Riemann states of the dam break problem
    damRadius = 0.5
    hl = 2.
    ul = 0.
    vl = 0.
    hr = 1.
    ur = 0.
    vr = 0.
    
    qinit(state,hl,ul,vl,hr,ur,vl,damRadius) # This function is defined above

    #===========================================================================
    # Set up controller and controller parameters
    #===========================================================================
    claw = pyclaw.Controller()
    claw.tfinal = 2.5
    claw.solution = pyclaw.Solution(state)
    claw.solver = solver
    claw.outdir = outdir
    claw.nout = 1
    claw.output_format=None

    #===========================================================================
    # Solve the problem
    #===========================================================================
    status = claw.run()

    #===========================================================================
    # Plot results
    #===========================================================================
    if iplot:     plot.plotInteractive(outdir=outdir,format=claw.output_format)
    if htmlplot:  plot.plotHTML(outdir=outdir,format=claw.output_format)


if __name__=="__main__":
    import sys
    from time import time
    if len(sys.argv)>1:
        from pyclaw.util import _info_from_argv
        args, kwargs = _info_from_argv(sys.argv)
        t1= time()
        error=shallow2D(*args,**kwargs)
        t2 = time()
        error=shallow2D(*args,**kwargs)
        print 'Error: ',error
    else:
        t1 = time()
        shallow2D()
        t2 = time()
        shallow2D()
    t3 = time()
    print "first call", t2-t1, "second call", t3-t2

    





