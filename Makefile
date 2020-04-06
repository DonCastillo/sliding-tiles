CXX=g++
CXXFLAGS= -Wall -g -std=c++11 

SRC_DIR = src
SRC_INCLUDE = include

PROGRAM = sliding-tiles


# default rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean-all
clean-all: clean
	rm -rf *.o $(PROGRAM) *~

$(PROGRAM): $(SRC_DIR)/*.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRC_DIR)/*.cpp main.cpp
