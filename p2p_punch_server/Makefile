

#wuyujie
#objects := $(patsubst %.c,%.o,$(wildcard *.c))

CC = g++  
CFLAGS =  -W -Wall -Wunused-parameter  -Wno-deprecated -Wcpp -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL -Wno-literal-suffix -Wno-unused-variable -Wno-unused-function -Wunused-parameter    


SRC := $(wildcard *.cpp *.c)

DIR :=$(notdir $(SRC))

INCLUDE := -I../include  -I ../  -I./ -I../include/util/ -I../include/util/detail -I ../common/ 

LIB     := -L../common/ -L../lib/ -L./  -ltarsutil


objects := $(patsubst %.cpp,%.o,$(DIR))


server:
	g++ -o  $@  $(INCLUDE)  $(DIR)  $(LIB)



all:
	@echo $(SRC)




