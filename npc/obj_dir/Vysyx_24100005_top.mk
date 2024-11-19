# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vysyx_24100005_top.mk

default: Vysyx_24100005_top__ALL.a

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vysyx_24100005_top
# Module prefix (from --prefix)
VM_MODPREFIX = Vysyx_24100005_top
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-MMD \
	-O3 \
	-I/usr/include/SDL2 \
	-D_REENTRANT \
	-I/home/myuser/ysyx/ysyx-workbench/npc/include \
	-I/home/myuser/ysyx/ysyx-workbench/nvboard/usr/include \
	-g \
	-DTOP_NAME="Vysyx_24100005_top" \
	-Wall \
	-Werror \
	-I/usr/lib/llvm-18/include \
	-std=c++17 \
	-fno-exceptions \
	-funwind-tables \
	-D_GNU_SOURCE \
	-D__STDC_CONSTANT_MACROS \
	-D__STDC_FORMAT_MACROS \
	-D__STDC_LIMIT_MACROS \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	/home/myuser/ysyx/ysyx-workbench/nvboard/build/nvboard.a \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lreadline \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	disasm \
	auto_bind \
	main \
	sdb \
	tool \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	/home/myuser/ysyx/ysyx-workbench/nemu/src/utils \
	/home/myuser/ysyx/ysyx-workbench/npc/build \
	/home/myuser/ysyx/ysyx-workbench/npc/csrc \


### Default rules...
# Include list of all generated classes
include Vysyx_24100005_top_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk
disasm.o: /home/myuser/ysyx/ysyx-workbench/nemu/src/utils/disasm.cc
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
auto_bind.o: /home/myuser/ysyx/ysyx-workbench/npc/build/auto_bind.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
main.o: /home/myuser/ysyx/ysyx-workbench/npc/csrc/main.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
sdb.o: /home/myuser/ysyx/ysyx-workbench/npc/csrc/sdb.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
tool.o: /home/myuser/ysyx/ysyx-workbench/npc/csrc/tool.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

# Verilated -*- Makefile -*-
