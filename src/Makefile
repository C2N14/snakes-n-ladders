CXX = g++
OUT_FILENAME = snakes
CXXFLAGS = -Wall -D'OUT_FILENAME="$(OUT_FILENAME)"'
OBJECTS = Board.cpp Player.cpp Die.cpp snakes.cpp
EXEC = $(OUT_FILENAME)

all: $(OBJECTS)                                                       
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)
