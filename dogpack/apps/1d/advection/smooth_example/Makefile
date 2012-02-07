### definitions ###

# default/library definitions
include $(DOGPACK)/lib/1d/Makefile.defs

# compiler options
#
# overridden library objects
#
include $(DOGPACK)/apps/semi_lagrangian/lib/1d/Makefile.defs

DogSolveUser           = $(DOGPACK)/apps/semi_lagrangian/lib/1d/DogSolveSL
DFluxFunc              = DFluxFunc
D2FluxFunc             = D2FluxFunc

# place to add object modules
#
ALL_OBJECTS = $(COMMON_OBJECTS) $(SL_LIB_OBJECTS)
ALL_SOURCES = $(COMMON_SOURCES) $(SL_LIB_SOURCES)

### targets ###

include $(DOGPACK)/lib/Makefile.targets

### DO NOT remove this line - make depends on it ###
