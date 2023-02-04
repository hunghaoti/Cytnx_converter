#install root
CYTNX_ROOT=$(HOME)/libraries/Cytnx_bkUT_lib
ITENSOR_ROOT:=$(HOME)/install/itensor

#conda cytnx environment path, ex, $(HOME)/anaconda3/envs/cytnx
CYTNX_CONDA_ENV_ROOT:=$(HOME)/anaconda3/envs/cytnx
CYTNX_CONDA_ENV_LIBDIR:=$(CYTNX_CONDA_ENV_ROOT)/lib/

CC := g++

#cytnx flags
#CYTNX_INC := $(shell python -c "exec(\"import sys\nsys.path.append(\'$(CYTNX_ROOT)\')\nimport cytnx\nprint(cytnx.__cpp_include__)\")")
#CYTNX_LDFLAGS := $(shell python -c "exec(\"import sys\nsys.path.append(\'$(CYTNX_ROOT)\')\nimport cytnx\nprint(cytnx.__cpp_linkflags__)\")")
#CYTNX_LIB := $(shell python -c "exec(\"import sys\nsys.path.append(\'$(CYTNX_ROOT)\')\nimport cytnx\nprint(cytnx.__cpp_lib__)\")")/libcytnx.a
#CYTNX_CXXFLAGS := $(shell python -c "exec(\"import sys\nsys.path.append(\'$(CYTNX_ROOT)\')\nimport cytnx\nprint(cytnx.__cpp_flags__)\")")

CYTNX_INC :=$(CYTNX_ROOT)/include
CYTNX_LIB :=$(CYTNX_ROOT)/lib64/libcytnx.a
CYTNX_CXXFLAGS :=-I$(CYTNX_CONDA_ENV_ROOT) -fvisibility-inlines-hidden -fmessage-length=0 -march=nocona -mtune=haswell -ftree-vectorize -fPIC -fstack-protector-strong -fno-plt -O2 -ffunction-sections -pipe -isystem /home/hunghaoti/anaconda3/envs/cytnx/include -Wformat=0 -w -g -fprofile-arcs -ftest-coverage -fopenmp -DUNI_HPTT
CYTNX_LDFLAGS :=\
	$(CYTNX_CONDA_ENV_LIBDIR)libmkl_intel_ilp64.so \
	$(CYTNX_CONDA_ENV_LIBDIR)libmkl_intel_thread.so \
	$(CYTNX_CONDA_ENV_LIBDIR)libmkl_core.so \
	$(CYTNX_CONDA_ENV_LIBDIR)libiomp5.so \
	-lpthread -lm -ldl -lpthread -lm -ldl -Wl,-rpath,$(CYTNX_CONDA_ENV_LIBDIR) $(CYTNX_ROOT)/hptt/lib/libhptt.a

#itensor flags
ITENSOR_CXXFLAGS:=-std=c++17
ITENSOR_HEADER:=$(ITENSOR_ROOT)
ITENSOR_LIBDIR:=$(ITENSOR_ROOT)/lib

obj:=elem_wise_cvt.o cytnx_converter.o
exe: test.e main.e

%.e:$(obj) %.o
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} -L$(ITENSOR_LIBDIR) $^ -o $@ $(CYTNX_LIB) -litensor -pthread $(CYTNX_LDFLAGS)


%.o:%.cpp
	echo $(CYTNX_ENV_ROOT)
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} -L$(CYTNX_LIB) $< -c


#clean
.phony: clean

clean:
	rm -f *.o *.e *.gcda *.gcno


