CXX = g++
INCLUDES = -I./
CXXFLAGS = $(INCLUDES) -lncurses -pedantic -std=c++11
LDFLAGS =  

SRC = examples/example_curses.cpp
OBJ = $(SRC:.cc=.o)
EXEC = example_curses

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(EXEC)