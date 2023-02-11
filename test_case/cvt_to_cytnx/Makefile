CYTNX_ROOT:=/home/j9263178/cytnx_bk_new
ITENSOR_ROOT:=/home/j9263178/itensor

#conda cytnx environment path, ex, $(HOME)/anaconda3/envs/cytnx
CYTNX_CONDA_ENV_ROOT:=/home/j9263178/anaconda3/envs/cytnx4
CYTNX_CONDA_ENV_LIBDIR:=$(CYTNX_CONDA_ENV_ROOT)/lib/


CC := g++

CYTNX_INC :=$(CYTNX_ROOT)/include
CYTNX_LIB :=$(CYTNX_ROOT)/lib64/libcytnx.a
CYTNX_CXXFLAGS :=-I$(CYTNX_CONDA_ENV_ROOT) -fvisibility-inlines-hidden -fmessage-length=0 -march=nocona -mtune=haswell -ftree-vectorize -fPIC -fstack-protector-strong -fno-plt -O2 -ffunction-sections -pipe -isystem /home/j9263178/anaconda3/envs/cytnx4/include -Wformat=0 -w -g -fprofile-arcs -ftest-coverage -fopenmp -DUNI_HPTT
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

CYTNX_CVT_ROOT=$(shell pwd)/../..

GEN_SRC := ./
OBJ_DIR := objs

OBJDIR:=objs
SOURCES := $(wildcard $(GEN_SRC)/*.cpp) $(wildcard $(CYTNX_CVT_ROOT)/*.cpp)
SOURCES := $(filter-out $(CYTNX_CVT_ROOT)/main.cpp $(CYTNX_CVT_ROOT)/test.cpp, $(SOURCES))
OBJECTS := $(patsubst $(GEN_SRC)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
OBJECTS := $(patsubst $(CYTNX_CVT_ROOT)/%.cpp, $(OBJDIR)/%.o, $(OBJECTS))

cvt_to_cytnx.e:$(OBJECTS)
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} -L$(ITENSOR_LIBDIR) $^ -o $@ $(CYTNX_LIB) -litensor -pthread $(CYTNX_LDFLAGS)

$(OBJDIR)/%.o:$(GEN_SRC)/%.cpp
	mkdir -p objs
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} -L$(ITENSOR_LIBDIR) -I$(CYTNX_CVT_ROOT) -I$(GEN_SRC) -c $^ -o $@
$(OBJDIR)/%.o:$(CYTNX_CVT_ROOT)/%.cpp
	mkdir -p objs
	$(CC) $(ITENSOR_CXXFLAGS) $(CYTNX_CXXFLAGS) -I$(ITENSOR_HEADER) -I${CYTNX_INC} -L$(ITENSOR_LIBDIR) -I$(CYTNX_CVT_ROOT) -I$(GEN_SRC) -c $^ -o $@



#clean
.phony: clean

clean:
	rm -f *.o *.e *.gcda *.gcno objs/*


