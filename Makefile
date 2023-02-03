#install root
CYTNX_ROOT=$(HOME)/libraries/Cytnx_bkUT_lib
ITENSOR_ROOT:=$(HOME)/install/itensor

CC := g++

CYTNX_INC :=$(CYTNX_ROOT)/include
CYTNX_LIB :=$(CYTNX_ROOT)/lib64/libcytnx.a
CYTNX_CXXFLAGS :=-w -fprofile-arcs
#CYTNX_CXXFLAGS :=-Wformat=0 -Wno-c++11-narrowing -w -g -fprofile-arcs -ftest-coverage


#itensor flags
ITENSOR_CXXFLAGS:=-std=c++17
ITENSOR_HEADER:=$(ITENSOR_ROOT)
ITENSOR_LIBDIR:=$(ITENSOR_ROOT)/lib

obj:=elem_wise_cvt.o cytnx_converter.o
exe: test.e main.e

%.e:$(obj) %.o
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} -L$(ITENSOR_LIBDIR) $^ -o $@ $(CYTNX_LIB) -litensor -pthread -lopenblas


%.o:%.cpp
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} $< -c


#clean
.phony: clean

clean:
	rm -f *.o *.e *.gcda *.gcno


