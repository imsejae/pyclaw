
""" 
Set up the plot figures, axes, and items to be done for each frame.

This module is imported by the plotting routines and then the
function setplot is called to set the plot parameters.
    
""" 

#--------------------------
def setplot(plotdata):
#--------------------------
    
    """ 
    Specify what is to be plotted at each frame.
    Input:  plotdata, an instance of visclaw.data.ClawPlotData.
    Output: a modified version of plotdata.
    
    """ 

    plotdata.clearfigures()  # clear any old figures,axes,items data

    

    # Figure for q[0]
    plotfigure = plotdata.new_plotfigure(name='Density', figno=0)

    # Set up for axes in this figure:
    plotaxes = plotfigure.new_plotaxes()
    #plotaxes.xlimits = [-5.0,5.0]
    #plotaxes.ylimits = [0,4.0]
    plotaxes.title = 'Density'

    # Set up for item on these axes:
    plotitem = plotaxes.new_plotitem(plot_type='1d')
    plotitem.plot_var = 0
    plotitem.plotstyle = '-'
    plotitem.color = 'b'
    plotitem.show = True       # show on plot?
    

    # Figure for q[1]
    plotfigure = plotdata.new_plotfigure(name='Pressure', figno=1)

    # Set up for axes in this figure:
    plotaxes = plotfigure.new_plotaxes()
    #plotaxes.xlimits = [-5.0,5.0]
    #plotaxes.ylimits = [-0.1, 1.4]
    plotaxes.title = 'Pressure'

    # Set up for item on these axes:
    plotitem = plotaxes.new_plotitem(plot_type='1d')
    def P(current_data):
        gamma = 1.4

        q = current_data.q   # solution when this function called
        P = (gamma-1)*(q[4,:]-0.5*(q[1,:]**2 + q[2,:]**2 + q[3,:]**2)/q[0,:]);
        return P
    plotitem.plot_var = P
    plotitem.plotstyle = '-'
    plotitem.color = 'b'
    plotitem.show = True       # show on plot?
    

    # Parameters used only when creating html and/or latex hardcopy
    # e.g., via visclaw.frametools.printframes:

    plotdata.printfigs = True                # print figures
    plotdata.print_format = 'png'            # file format
    plotdata.print_framenos = 'all'          # list of frames to print
    plotdata.print_fignos = 'all'            # list of figures to print
    plotdata.html = True                     # create html files of plots?
    plotdata.html_homelink = '../README.html'   # pointer for top of index
    plotdata.latex = True                    # create latex file of plots?
    plotdata.latex_figsperline = 2           # layout of plots
    plotdata.latex_framesperline = 1         # layout of plots
    plotdata.latex_makepdf = False           # also run pdflatex?


    # Figure for q[2]
    plotfigure = plotdata.new_plotfigure(name='Velocity', figno=2)

    # Set up for axes in this figure:
    plotaxes = plotfigure.new_plotaxes()
    #plotaxes.xlimits = [-5.0,5.0]
    #plotaxes.ylimits = [-0.1, 1.4]
    plotaxes.title = 'Velocity'

    # Set up for item on these axes:
    plotitem = plotaxes.new_plotitem(plot_type='1d')
    def u(current_data):
        q = current_data.q   # solution when this function called
        rho = q[0,:]           # pressure
        mom = q[1,:]           # velocity
        u=mom/rho  # uses impedance Z set above
        return u
    plotitem.plot_var=u
    plotitem.plotstyle = '-'
    plotitem.color = 'b'
    plotitem.show = True       # show on plot?
    

    # Parameters used only when creating html and/or latex hardcopy
    # e.g., via visclaw.frametools.printframes:

    plotdata.printfigs = True                # print figures
    plotdata.print_format = 'png'            # file format
    plotdata.print_framenos = 'all'          # list of frames to print
    plotdata.print_fignos = 'all'            # list of figures to print
    plotdata.html = True                     # create html files of plots?
    plotdata.html_homelink = '../README.html'   # pointer for top of index
    plotdata.latex = True                    # create latex file of plots?
    plotdata.latex_figsperline = 2           # layout of plots
    plotdata.latex_framesperline = 1         # layout of plots
    plotdata.latex_makepdf = False           # also run pdflatex?

    return plotdata
