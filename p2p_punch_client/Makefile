

#wuyujie
#objects := $(patsubst %.c,%.o,$(wildcard *.c))

CC = g++  
CFLAGS =  -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
-DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL         \
-Wno-literal-suffix -Wno-unused-variable -Wno-unused-function              \
-Wno-sign-compare -Wno-deprecated -Wno-unused-parameter -Wno-missing-field-initializers \
-DAC_HAS_DEBUG -DLINUX_DAEMON

LDFLAGS = -lm  

SRC := $(wildcard *.cpp *.c)

DIR :=$(notdir $(SRC))

INCLUDE := -I../include  -I./ -I../include/util/ -I../include/util/detail

LIB     :=-L./ -L../ -ltarsutil -lpthread


objects := $(patsubst %.cpp,%.o,$(DIR))


server:
	$(CC) -o  $@  $(INCLUDE) $(LIB) $(DIR)



all:
	@echo $(SRC)




