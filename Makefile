CXX=g++
CXXFLAGS= -Wall -g -std=c++11 

SRC_DIR = src
SRC_INCLUDE = include

PROGRAM = sliding-tiles


# default rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(PROGRAM): $(SRC_DIR)/*.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRC_DIR)/*.cpp main.cpp

	
.PHONY: clean
clean:
	rm -rf *~ $(SRC_DIR)/*.o $(PROGRAM)