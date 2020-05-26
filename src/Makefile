CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++11 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = 
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)