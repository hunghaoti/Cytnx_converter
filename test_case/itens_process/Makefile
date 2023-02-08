#install root
ITENSOR_ROOT:=$(HOME)/install/itensor

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
	$(CC) $(ITENSOR_CXXFLAGS) -I$(ITENSOR_HEADER) -I$(GOOGLETEST_INC) -L$(ITENSOR_LIBDIR) $^ -o $@ -litensor -lpthread -lopenblas $(GOOGLETEST_LIB)

$(OBJDIR)/%.o:$(GEN_SRC)/%.cpp
	$(CC) $(ITENSOR_CXXFLAGS) -I$(ITENSOR_HEADER) -I$(GOOGLETEST_INC) -L$(ITENSOR_LIBDIR) -I$(GEN_SRC) -c $^ -o $@



#clean
.phony: clean

clean:
	rm -f *.o *.e *.gcda *.gcno objs/*


