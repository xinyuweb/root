TIME:=$(shell date +'%Y%m%d')
OS:=$(shell uname -s)
ARCH:=$(shell uname -m)
BIT32:=i686
BIT64:=x86_64

# source directions
COMMON_DIR=common/
SRC_DIR=src/
TEST_DIR=test/

OBJ_DIR=./lib/

LIB_DIR = /usr/lib
LOCAL_LIB_DIR = /usr/local/lib

ifeq ($(ARCH),$(BIT64))
    LIB_DIR = /usr/lib64
    LOCAL_LIB_DIR = /usr/local/lib64
endif


CC=gcc

INCLUDE:=-I/usr/include -I/usr/local/include  -I. -I./libs/include/libev -I./libs/include/rock/

# lib directions
LIBS_PATH:=${PWD}/libs/lib
LIB=-L${LIB_DIR} -L${LOCAL_LIB_DIR}   -lpthread -L${LIBS_PATH} /home/qiaolei/virtualboxshare/dpan/git_workspace/root/netframe/libs/lib/libev.a -lm /home/qiaolei/virtualboxshare/dpan/git_workspace/root/netframe/libs/lib/librock.a # -lstdc++ -lm -lev  

CFLAGS:=-Wall -g -O2  -Wextra -std=c99 $(INCLUDE)   -D_GNU_SOURCE  -DOS_LINUX 
#CPPFLAGS:=$(CFLAGS) 

COMMON_SRC:=$(wildcard $(COMMON_DIR)*.c)
SRC_SRC:=$(wildcard $(SRC_DIR)*.c)
TEST_SRC:=$(wildcard $(TEST_DIR)*.c)

COMMON_OBJ:=$(patsubst %.c,%.o,$(COMMON_SRC))
SRC_OBJ:=$(patsubst %.c,%.o,$(SRC_SRC))
TEST_OBJ:=$(patsubst %.c,%.o,$(TEST_SRC))

COMMON_DEP:=$(patsubst %.c,%.d,$(COMMON_SRC))
SRC_DEP:=$(patsubst %.c,%.d,$(SRC_SRC))
TEST_DEP:=$(patsubst %.c,%.d,$(TEST_SRC))

CPPFLAGS += -MD

#LIB_NAME=$(OBJ_DIR)libdeny_crawler_${ARCH}_${OS}.a
LIB_NAME=bin/test_${ARCH}_${OS}
all: $(LIB_NAME)

$(LIB_NAME): $(COMMON_OBJ) $(SRC_OBJ)
	#ar -r $@ $^
	#ranlib $(LIB_NAME)
	$(CC) $^ $(CFLAGS) -o $@ $(LIB)
clean:
	rm $(COMMON_DIR)*.o $(SRC_DIR)*.o $(TEST_DIR)*.o -fv
	rm $(COMMON_DIR)*.d $(SRC_DIR)*.d $(TEST_DIR)*.d -fv
	rm $(LIB_NAME)

-include $(COMMON_DEP) $(SRC_DEP) $(TEST_DEP)


rebuild: clean all
love: clean all

