TOPNAME = ysyx_24100005_top
NXDC_FILES = constr/top.nxdc
INC_PATH ?= /home/myuser/ysyx/ysyx-workbench/npc/include

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
                                 --x-assign fast --x-initial fast --noassert --trace --timing

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -g -DTOP_NAME="\"V$(TOPNAME)\"" -Wall -Werror

LDFLAGS += -lreadline

LIBS += $(shell llvm-config --libs)
CXXFLAGS += -I/usr/lib/llvm-18/include -std=c++17   -fno-exceptions -funwind-tables -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS

CSRCS += /home/myuser/ysyx/ysyx-workbench/nemu/src/utils/disasm.cc

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
                --top-module $(TOPNAME) $^ \
                $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
				-LDFLAGS $(LIBS) \
                --Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) \
				-I/home/myuser/ysyx/ysyx-workbench/npc/vsrc


IMG ?= 
ELF ?= 
REF ?= /home/myuser/ysyx/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so

NPC_EXEC := $(BIN) $(IMG) $(ELF) $(REF)

sim:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(NPC_EXEC)

## gdb有问题，传递的参数要加 --args参数
gdb:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	gdb -s $(NPC_EXEC)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

# git commit的tracer
include ../Makefile
