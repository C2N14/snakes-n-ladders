CXX = g++

MAIN = snakes

CXXFLAGS = -Wall -g -D'OUT_FILENAME="$(MAIN)"'

INCLUDES =

LFLAGS =

LIBS =

SRCS = Tile.cpp SnakeTile.cpp LadderTile.cpp NormalTile.cpp Board.cpp Player.cpp Die.cpp Game.cpp ManualGame.cpp AutomaticGame.cpp snakes.cpp

OBJS = $(SRCS:.cpp=.o)

ARGS = in.txt out.txt

all: $(MAIN)

$(MAIN): $(OBJS)                                                       
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS)

.c.o:
	$(CCX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN) out.txt

run:
	./$(MAIN) $(ARGS)
