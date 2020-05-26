#ifndef BOARD_H
#define BOARD_H

#include "Tile.hpp"
#include <string>
#include <vector>

const size_t DEFAULT_BOARD_SIZE = 30;
const size_t DEFAULT_SNAKES = 6;
const size_t DEFAULT_LADDERS = 6;

class Board {
private:
    std::vector<Tile> d_tiles;

public:
    Board();
    Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders);
    Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders,
          int snakePenalty, int ladderReward);
    Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders,
          Tile snake, Tile ladder, Tile normal);

    size_t size();

    std::string tileString(size_t tileNumber);
    int tileSteps(size_t tileNumber);

    std::string operator[](size_t tileNumber);
};

#endif
