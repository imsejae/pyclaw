def run_DG_cpp():
    # write the parameters file
    outputdir = 'outputdir'
    failure = os.system('dog.exe %s' % filename)
    if failure:
        print 'Could not run'
    
