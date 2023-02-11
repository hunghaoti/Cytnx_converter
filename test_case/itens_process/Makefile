#install root
ITENSOR_ROOT:=/home/j9263178/itensor

CC := g++

#itensor flags
ITENSOR_CXXFLAGS:=-std=c++17
ITENSOR_HEADER:=$(ITENSOR_ROOT)
ITENSOR_LIBDIR:=$(ITENSOR_ROOT)/lib

GOOGLETEST_ROOT=../googletest
GOOGLETEST_INC=$(GOOGLETEST_ROOT)/googletest/include
GOOGLETEST_LIB=$(GOOGLETEST_ROOT)/lib/libgtest.a

GEN_SRC := ./
OBJ_DIR := objs

OBJDIR:=objs
SOURCES := $(wildcard $(GEN_SRC)/*.cpp)
OBJECTS := $(patsubst $(GEN_SRC)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

gen_test_data_main.e:$(OBJECTS)
	$(CC) $(ITENSOR_CXXFLAGS) -I$(ITENSOR_HEADER) -I$(GOOGLETEST_INC) -L$(ITENSOR_LIBDIR) -I/home/j9263178/anaconda3/envs/cytnx4/include/ $^ -o $@ -litensor -L/home/j9263178/anaconda3/envs/cytnx4/lib -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_rt -lmkl_core -liomp5 -lpthread $(GOOGLETEST_LIB)

$(OBJDIR)/%.o:$(GEN_SRC)/%.cpp
	mkdir -p objs
	$(CC) $(ITENSOR_CXXFLAGS) -I$(ITENSOR_HEADER) -I$(GOOGLETEST_INC) -L$(ITENSOR_LIBDIR) -I/home/j9263178/anaconda3/envs/cytnx4/include/ -L/home/j9263178/anaconda3/envs/cytnx4/lib -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_rt -lmkl_core -liomp5 -I$(GEN_SRC) -c $^ -o $@



#clean
.phony: clean

clean:
	rm -f *.o *.e *.gcda *.gcno objs/*


