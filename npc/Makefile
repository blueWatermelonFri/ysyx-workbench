<<<<<<< HEAD
<<<<<<< HEAD
TOPNAME = ysyx_24100005_top
NXDC_FILES = constr/top.nxdc
INC_PATH ?= /home/myuser/ysyx/ysyx-workbench/npc/include

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
                                 --x-assign fast --x-initial fast --noassert --trace --timing
=======
STUID = ysyx_22040000
STUNAME = 何源宏

# DO NOT modify the following code!!!

TRACER = tracer-ysyx
GITFLAGS = -q --author='$(TRACER) <tracer@ysyx.org>' --no-verify --allow-empty

YSYX_HOME = $(NEMU_HOME)/..
WORK_BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
WORK_INDEX = $(YSYX_HOME)/.git/index.$(WORK_BRANCH)
TRACER_BRANCH = $(TRACER)

LOCK_DIR = $(YSYX_HOME)/.git/

# prototype: git_soft_checkout(branch)
define git_soft_checkout
	git checkout --detach -q && git reset --soft $(1) -q -- && git checkout $(1) -q --
endef

# prototype: git_commit(msg)
define git_commit
	-@flock $(LOCK_DIR) $(MAKE) -C $(YSYX_HOME) .git_commit MSG='$(1)'
	-@sync $(LOCK_DIR)
endef

.git_commit:
	echo 1111111111111111111111111111111111111111111111111111111111111111111111
	-@while (test -e .git/index.lock); do sleep 0.1; done;               `# wait for other git instances`
	-@git branch $(TRACER_BRANCH) -q 2>/dev/null || true                 `# create tracer branch if not existent`
	-@cp -a .git/index $(WORK_INDEX)                                     `# backup git index`
	-@$(call git_soft_checkout, $(TRACER_BRANCH))                        `# switch to tracer branch`
	-@git add . -A --ignore-errors                                       `# add files to commit`
	-@(echo "> $(MSG)" && echo $(STUID) $(STUNAME) && uname -a && uptime `# generate commit msg`) \
	                | git commit -F - $(GITFLAGS)                        `# commit changes in tracer branch`
	-@$(call git_soft_checkout, $(WORK_BRANCH))                          `# switch to work branch`
	-@mv $(WORK_INDEX) .git/index     





=======
include ../Makefile
>>>>>>> e4f70e1 (>)
TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert
>>>>>>> f2d33a7 (>)

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
<<<<<<< HEAD
CXXFLAGS += $(INCFLAGS) -g -DTOP_NAME="\"V$(TOPNAME)\"" -Wall -Werror

LDFLAGS += -lreadline

LIBS += $(shell llvm-config --libs)
CXXFLAGS += -I/usr/lib/llvm-18/include -std=c++17   -fno-exceptions -funwind-tables -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS

CSRCS += /home/myuser/ysyx/ysyx-workbench/nemu/src/utils/disasm.cc
=======
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
>>>>>>> f2d33a7 (>)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
<<<<<<< HEAD
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
<<<<<<< HEAD
	$(NPC_EXEC)

## gdb有问题，传递的参数要加 --args参数
gdb:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	gdb -s $(NPC_EXEC)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

# git commit的tracer
=======
	@echo "Write this Makefile by your self."
	verilator --cc --exe --build -j 0 -Wall --trace-fst  ./csrc/main.cpp ./vsrc/example.v 

clean:
	rm -rf ./obj_dir
<<<<<<< HEAD
>>>>>>> b1cfd9b (> sim RTL)
=======
	rm  ./dump.vcd

>>>>>>> 4db6f01 (> sim RTL)
include ../Makefile
=======
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


sim:$(BIN)
	$(call git_commit, "sim RTL") 

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

<<<<<<< HEAD
>>>>>>> f2d33a7 (>)
=======

>>>>>>> e4f70e1 (>)
