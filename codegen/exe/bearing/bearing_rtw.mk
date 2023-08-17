###########################################################################
## Makefile generated for component 'bearing'. 
## 
## Makefile     : bearing_rtw.mk
## Generated on : Thu Aug 17 13:15:02 2023
## Final product: $(START_DIR)/bearing
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = bearing
MAKEFILE                  = bearing_rtw.mk
MATLAB_ROOT               = /Applications/MATLAB_R2023a.app
MATLAB_BIN                = /Applications/MATLAB_R2023a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
START_DIR                 = /Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_bearing
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -std=c++14 -fno-common -fexceptions

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Xcode with Clang | gmake (64-bit Mac)
# Supported Version(s):    
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) -mmacosx-version-min=10.15 \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) -mmacosx-version-min=10.15 \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
CPP_SHAREDLIB_LDFLAGS  = -arch $(ARCHS)  \
                         -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -arch $(ARCHS)  \
                       -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(START_DIR)/bearing
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/exe/bearing -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=bearing

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/exe/bearing/coder_platform.c $(START_DIR)/codegen/exe/bearing/coder_filestats.c $(START_DIR)/main.cpp $(START_DIR)/codegen/exe/bearing/bearing_data.cpp $(START_DIR)/codegen/exe/bearing/rt_nonfinite.cpp $(START_DIR)/codegen/exe/bearing/rtGetNaN.cpp $(START_DIR)/codegen/exe/bearing/rtGetInf.cpp $(START_DIR)/codegen/exe/bearing/bearing_initialize.cpp $(START_DIR)/codegen/exe/bearing/bearing_terminate.cpp $(START_DIR)/codegen/exe/bearing/bearing.cpp $(START_DIR)/codegen/exe/bearing/readpulsecsv.cpp $(START_DIR)/codegen/exe/bearing/fileManager.cpp $(START_DIR)/codegen/exe/bearing/cleancsv.cpp $(START_DIR)/codegen/exe/bearing/feof.cpp $(START_DIR)/codegen/exe/bearing/fgetl.cpp $(START_DIR)/codegen/exe/bearing/fgets.cpp $(START_DIR)/codegen/exe/bearing/ftell.cpp $(START_DIR)/codegen/exe/bearing/str2double.cpp $(START_DIR)/codegen/exe/bearing/fseek.cpp $(START_DIR)/codegen/exe/bearing/fscanf.cpp $(START_DIR)/codegen/exe/bearing/find.cpp $(START_DIR)/codegen/exe/bearing/indexShapeCheck.cpp $(START_DIR)/codegen/exe/bearing/unique.cpp $(START_DIR)/codegen/exe/bearing/PositionStruct.cpp $(START_DIR)/codegen/exe/bearing/repmat.cpp $(START_DIR)/codegen/exe/bearing/PulseStruct.cpp $(START_DIR)/codegen/exe/bearing/CommandStruct.cpp $(START_DIR)/codegen/exe/bearing/doapca.cpp $(START_DIR)/codegen/exe/bearing/horzcatStructList.cpp $(START_DIR)/codegen/exe/bearing/any1.cpp $(START_DIR)/codegen/exe/bearing/minOrMax.cpp $(START_DIR)/codegen/exe/bearing/diff.cpp $(START_DIR)/codegen/exe/bearing/sum.cpp $(START_DIR)/codegen/exe/bearing/eye.cpp $(START_DIR)/codegen/exe/bearing/mtimes.cpp $(START_DIR)/codegen/exe/bearing/svd.cpp $(START_DIR)/codegen/exe/bearing/svd1.cpp $(START_DIR)/codegen/exe/bearing/xzsvdc.cpp $(START_DIR)/codegen/exe/bearing/xnrm2.cpp $(START_DIR)/codegen/exe/bearing/xdotc.cpp $(START_DIR)/codegen/exe/bearing/median.cpp $(START_DIR)/codegen/exe/bearing/quickselect.cpp $(START_DIR)/codegen/exe/bearing/isfile.cpp $(START_DIR)/codegen/exe/bearing/sprintf.cpp $(START_DIR)/codegen/exe/bearing/readbearingcsv.cpp $(START_DIR)/codegen/exe/bearing/eml_int_forloop_overflow_check.cpp $(START_DIR)/codegen/exe/bearing/strcmp.cpp $(START_DIR)/codegen/exe/bearing/nullAssignment.cpp $(START_DIR)/codegen/exe/bearing/sort.cpp $(START_DIR)/codegen/exe/bearing/sortIdx.cpp $(START_DIR)/codegen/exe/bearing/xscal.cpp $(START_DIR)/codegen/exe/bearing/xaxpy.cpp $(START_DIR)/codegen/exe/bearing/xrotg.cpp $(START_DIR)/codegen/exe/bearing/xrot.cpp $(START_DIR)/codegen/exe/bearing/xswap.cpp $(START_DIR)/codegen/exe/bearing/wrapTo360.cpp $(START_DIR)/codegen/exe/bearing/varNamesDim.cpp $(START_DIR)/codegen/exe/bearing/onCleanup.cpp $(START_DIR)/codegen/exe/bearing/table.cpp $(START_DIR)/codegen/exe/bearing/bearing_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = coder_platform.o coder_filestats.o main.o bearing_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o bearing_initialize.o bearing_terminate.o bearing.o readpulsecsv.o fileManager.o cleancsv.o feof.o fgetl.o fgets.o ftell.o str2double.o fseek.o fscanf.o find.o indexShapeCheck.o unique.o PositionStruct.o repmat.o PulseStruct.o CommandStruct.o doapca.o horzcatStructList.o any1.o minOrMax.o diff.o sum.o eye.o mtimes.o svd.o svd1.o xzsvdc.o xnrm2.o xdotc.o median.o quickselect.o isfile.o sprintf.o readbearingcsv.o eml_int_forloop_overflow_check.o strcmp.o nullAssignment.o sort.o sortIdx.o xscal.o xaxpy.o xrotg.o xrot.o xswap.o wrapTo360.o varNamesDim.o onCleanup.o table.o bearing_rtwutil.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm -lstdc++

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/bearing/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/bearing/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


coder_platform.o : $(START_DIR)/codegen/exe/bearing/coder_platform.c
	$(CC) $(CFLAGS) -o "$@" "$<"


coder_filestats.o : $(START_DIR)/codegen/exe/bearing/coder_filestats.c
	$(CC) $(CFLAGS) -o "$@" "$<"


main.o : $(START_DIR)/main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bearing_data.o : $(START_DIR)/codegen/exe/bearing/bearing_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/codegen/exe/bearing/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/codegen/exe/bearing/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/codegen/exe/bearing/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bearing_initialize.o : $(START_DIR)/codegen/exe/bearing/bearing_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bearing_terminate.o : $(START_DIR)/codegen/exe/bearing/bearing_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bearing.o : $(START_DIR)/codegen/exe/bearing/bearing.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


readpulsecsv.o : $(START_DIR)/codegen/exe/bearing/readpulsecsv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fileManager.o : $(START_DIR)/codegen/exe/bearing/fileManager.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cleancsv.o : $(START_DIR)/codegen/exe/bearing/cleancsv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feof.o : $(START_DIR)/codegen/exe/bearing/feof.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fgetl.o : $(START_DIR)/codegen/exe/bearing/fgetl.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fgets.o : $(START_DIR)/codegen/exe/bearing/fgets.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ftell.o : $(START_DIR)/codegen/exe/bearing/ftell.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


str2double.o : $(START_DIR)/codegen/exe/bearing/str2double.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fseek.o : $(START_DIR)/codegen/exe/bearing/fseek.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fscanf.o : $(START_DIR)/codegen/exe/bearing/fscanf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.o : $(START_DIR)/codegen/exe/bearing/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


indexShapeCheck.o : $(START_DIR)/codegen/exe/bearing/indexShapeCheck.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unique.o : $(START_DIR)/codegen/exe/bearing/unique.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PositionStruct.o : $(START_DIR)/codegen/exe/bearing/PositionStruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


repmat.o : $(START_DIR)/codegen/exe/bearing/repmat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PulseStruct.o : $(START_DIR)/codegen/exe/bearing/PulseStruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CommandStruct.o : $(START_DIR)/codegen/exe/bearing/CommandStruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


doapca.o : $(START_DIR)/codegen/exe/bearing/doapca.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


horzcatStructList.o : $(START_DIR)/codegen/exe/bearing/horzcatStructList.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


any1.o : $(START_DIR)/codegen/exe/bearing/any1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.o : $(START_DIR)/codegen/exe/bearing/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


diff.o : $(START_DIR)/codegen/exe/bearing/diff.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sum.o : $(START_DIR)/codegen/exe/bearing/sum.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eye.o : $(START_DIR)/codegen/exe/bearing/eye.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mtimes.o : $(START_DIR)/codegen/exe/bearing/mtimes.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.o : $(START_DIR)/codegen/exe/bearing/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd1.o : $(START_DIR)/codegen/exe/bearing/svd1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzsvdc.o : $(START_DIR)/codegen/exe/bearing/xzsvdc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/codegen/exe/bearing/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.o : $(START_DIR)/codegen/exe/bearing/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


median.o : $(START_DIR)/codegen/exe/bearing/median.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


quickselect.o : $(START_DIR)/codegen/exe/bearing/quickselect.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isfile.o : $(START_DIR)/codegen/exe/bearing/isfile.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sprintf.o : $(START_DIR)/codegen/exe/bearing/sprintf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


readbearingcsv.o : $(START_DIR)/codegen/exe/bearing/readbearingcsv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_int_forloop_overflow_check.o : $(START_DIR)/codegen/exe/bearing/eml_int_forloop_overflow_check.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strcmp.o : $(START_DIR)/codegen/exe/bearing/strcmp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nullAssignment.o : $(START_DIR)/codegen/exe/bearing/nullAssignment.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.o : $(START_DIR)/codegen/exe/bearing/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/codegen/exe/bearing/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xscal.o : $(START_DIR)/codegen/exe/bearing/xscal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.o : $(START_DIR)/codegen/exe/bearing/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.o : $(START_DIR)/codegen/exe/bearing/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.o : $(START_DIR)/codegen/exe/bearing/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.o : $(START_DIR)/codegen/exe/bearing/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


wrapTo360.o : $(START_DIR)/codegen/exe/bearing/wrapTo360.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


varNamesDim.o : $(START_DIR)/codegen/exe/bearing/varNamesDim.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


onCleanup.o : $(START_DIR)/codegen/exe/bearing/onCleanup.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


table.o : $(START_DIR)/codegen/exe/bearing/table.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bearing_rtwutil.o : $(START_DIR)/codegen/exe/bearing/bearing_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


