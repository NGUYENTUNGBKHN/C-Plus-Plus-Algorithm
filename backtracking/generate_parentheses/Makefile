# DIRECTION TARGET
TARGET_NAME_ORG=gererate_parentheses
BUILD_DIR=_build
OBJS_DIR = $(BUILD_DIR)/objs


FLATFORM=$(shell uname)
ifeq ($(FLATFORM),Linux)
TARGET_NAME=$(TARGET_NAME_ORG)
else
TARGET_NAME=$(TARGET_NAME_ORG).exe
endif

ifeq ($(TOOLCHAIN_PC),)
# TOOLCHAIN
CC=gcc
CPP=g++
SIZE=size
else
# TOOLCHAIN
CC=$(TOOLCHAIN_PC)/gcc
CPP=$(TOOLCHAIN_PC)/g++
SIZE=$(TOOLCHAIN_PC)/size
endif 
# CFLAG

CCFLAG=\


# Source file
SRC_FILE=$(wildcard *.cpp)

# Header file
HEADER_FILE=\

LIBS=\

OBJECTS=$(patsubst %.cpp,$(OBJS_DIR)/%.opp,$(SRC_FILE))

.PHONY: all clean default

default : all

all: $(BUILD_DIR)/$(TARGET_NAME)

$(OBJS_DIR)/%.opp: %.cpp
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CPP) $(CCFLAG) $(LIBS) $(HEADER_FILE) -c $< -o $@

$(BUILD_DIR)/$(TARGET_NAME): $(OBJECTS)
	@echo "LINK $@"
	@$(CPP) $(CCFLAG) $(LIBS) $(HEADER_FILE) $(OBJECTS) -o $@
	@$(SIZE) $@

clean:
	rm -r $(BUILD_DIR)







