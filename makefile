# retrieve system architecture
ARCH := $(shell uname -s)
$(info Creating busy function C/C++ library and demo programs for ARCH = $(ARCH))

# specify compilation options
CXX = c++
CC = cc
CFLAGS = -O2
LDFLAGS = -lm
ifndef INSTALL_DIR
  INSTALL_DIR = /usr/local/lib
  $(info INSTALL_DIR not defined. Setting to default value. INSTALL_DIR = $(INSTALL_DIR).)
endif
ifndef INSTALL_INC
  INSTALL_INC = /usr/local/include
  $(info INSTALL_INC not defind. Setting to default value. INSTALL_INC = $(INSTALL_INC).)
endif

# set the library creation method
ifeq ($(ARCH),Darwin)
  LIB_METHOD = Libtool -static -o
else 
  LIB_METHOD = ar -cru
endif
$(info Using LIB_METHOD = $(LIB_METHOD))

# set the rules for creating the C library

all: ./libcprogbar.a ./test ./test2 ./test3

./libcprogbar.a: cprogbar.c cprogbar.h
	$(CC) $(CFLAGS) -c cprogbar.c -I.
	$(LIB_METHOD) libcprogbar.a cprogbar.o

./test: test.c libcprogbar.a
	$(CC) $< -o $@ $(CFLAGS) -I. -L. -lcprogbar $(LDFLAGS)

./test2: test2.c libcprogbar.a
	$(CC) $< -o $@ $(CFLAGS) -I. -L. -lcprogbar $(LDFLAGS)

./test3: test3.cpp
	$(CXX) $< -o $@ $(CFLAGS) -I. $(LDFLAGS)

clean:
	@echo Cleaning up *.o files . . . 
	@rm -vf cprogbar.o

distclean:
	@echo Cleaning up *.o, *.a and executable files . . . 
	@rm -vf cprogbar.o
	@rm -vf libcprogbar.a
	@rm -vf test
	@rm -vf test2
	@rm -vf test3

install:
	@echo Installing libraries to $(INSTALL_DIR) and header files to $(INSTALL_INC) . . . 
	@cp libcprogbar.a $(INSTALL_DIR)
	@cp cprogbar.h $(INSTALL_INC)
	@cp progbar.h $(INSTALL_INC)



