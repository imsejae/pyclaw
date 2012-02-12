
### definitions ###

# default/library definitions
include $(DOGPACK)/lib/2d/Makefile.defs

# overridden library objects
#
include $(DOGPACK)/apps/semi_lagrangian/lib/2d/cart/Makefile.defs

#AfterQinit       = AfterQinit
DogSolveUser       = $(DOGPACK)/apps/semi_lagrangian/lib/2d/cart/DogSolveSL
#SetAdvecSpeedExtra = SetAdvecSpeedExtra

ALL_OBJECTS = $(COMMON_OBJECTS) $(SL_LIB_OBJECTS) NonConsFunc.o
ALL_SOURCES = $(COMMON_SOURCES) $(SL_LIB_SOURCES) NonConsFunc.cpp

### targets ###

include $(DOGPACK)/lib/2d/Makefile.targets

### DO NOT remove this line - make depends on it ###
