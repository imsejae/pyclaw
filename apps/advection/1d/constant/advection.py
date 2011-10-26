#!/usr/bin/env python
# encoding: utf-8

"""
1D shallow advection equation with constant convective velocity.
"""


def advection(kernel_language='Fortran',iplot=False,htmlplot=False,use_petsc=False,solver_type='sharpclaw',outdir='./_output'):
    #===========================================================================
    # Import libraries
    #===========================================================================
    import numpy as np

    if use_petsc:
        import petclaw as pyclaw
    else:
        import pyclaw

    if solver_type=='sharpclaw':
        solver = pyclaw.SharpClawSolver1D()
    else:
        solver = pyclaw.ClawSolver1D()

    #===========================================================================
    # Setup solver and solver parameters
    #===========================================================================
    solver.kernel_language = kernel_language

    from riemann import rp_advection
    solver.mwaves = rp_advection.mwaves
    if solver.kernel_language=='Python': 
        solver.rp = rp_advection.rp_advection_1d

    solver.bc_lower[0] = 2
    solver.bc_upper[0] = 2

    # Time integrator
    solver.time_integrator='DWSSP105'
    solver.dt_initial = 0.1
    solver.cfl_max = 0.4
    solver.cfl_desired = 0.3


    #===========================================================================
    # Initialize grids and then initialize the solution associated to the grid
    #===========================================================================
    x = pyclaw.Dimension('x',0.0,1.0,100)
    grid = pyclaw.Grid(x)
    meqn = 1
    state = pyclaw.State(grid,meqn)
    state.aux_global['u']=1.

    xc=grid.x.center
    beta=100; gamma=0; x0=0.75
    state.q[0,:] = np.exp(-beta * (xc-x0)**2) * np.cos(gamma * (xc - x0))

    #===========================================================================
    # Setup controller and controller paramters
    #===========================================================================
    claw = pyclaw.Controller()
    claw.solution = pyclaw.Solution(state)
    claw.solver = solver
    claw.outdir = outdir
    claw.tfinal = 1.0
   
    #===========================================================================
    # Solve the problem
    #===========================================================================
    status = claw.run()

    #===========================================================================
    # Plot results
    #===========================================================================
    if htmlplot:  pyclaw.plot.html_plot(outdir=outdir)
    if iplot:     pyclaw.plot.interactive_plot(outdir=outdir)

if __name__=="__main__":
    from pyclaw.util import run_app_from_main
    output = run_app_from_main(advection)
