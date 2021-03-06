CC := gcc
CPP := g++
DBGFLAG = -g
CCFLAG += -I./inc
CPPFLAG += -I./inc
#CCFLAG += -DBUBBLE 
#CCFLAG += -DSELECTION 
#CCFLAG += -DINSERTION 
#CCFLAG += -DSHELL 
#CCFLAG += -DMERGE 
#CCFLAG += -DQUICKSORT 
#CCFLAG += -DCOUNTSORT 
#CPPFLAG += -DOBSERVER_PATTERN 
CPPFLAG += -DTESTLINK 

CCOBJFLAG := $(CCFLAG)
CPPOBJFLAG := $(CPPFLAG)

BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src
DBG_PATH := debug
INC_PATH := inc

TARGET_NAME := sort
TARGET := $(BIN_PATH)/$(TARGET_NAME)
TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_DEBUG := $(addprefix $(DBG_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ) \
                  $(OBJ_DEBUG)
CLEAN_LIST := $(TARGET) \
			  $(TARGET_DEBUG) \
			  $(DISTCLEAN_LIST)

# default rule
default: all

# non-phony targets
$(TARGET): $(OBJ)
	$(CPP) $(CPPFLAG) -o $@ $?

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CCOBJFLAG) -o $@ $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CPP) -c $(CPPOBJFLAG) -o $@ $<

$(DBG_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CCOBJFLAG) $(DBGFLAG) -o $@ $<

$(DBG_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CPP) -c $(CPPOBJFLAG) $(DBGFLAG) -o $@ $<

$(TARGET_DEBUG): $(OBJ_DEBUG)
	$(CPP) $(CPPFLAG) $(DBGFLAG) $? -o $@

# phony rules
.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)

