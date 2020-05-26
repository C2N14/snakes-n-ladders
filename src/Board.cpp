#include "Board.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// default constructor delegates to custom constructor by using the constants :)
Board::Board() : Board(DEFAULT_BOARD_SIZE, DEFAULT_MAX_SPECIAL_TILES) {}

// NOTE: I know the snakes can overwrite the ladders, but I kinda like how it
// adds yet more randomness into the game ;)
Board::Board(size_t boardSize, size_t maxSpecialTiles)
    : d_board(boardSize, Normal) {
    // create and fill the vector with all possible tile numbers for both
    // snakes and ladders with their possible positions
    vector<size_t> laddersNumbers(boardSize - this->tileSteps(Ladder) - 1);
    iota(laddersNumbers.begin(), laddersNumbers.end(), 1);

    vector<size_t> snakesNumbers(boardSize + this->tileSteps(Board::Snake) - 1);
    iota(snakesNumbers.begin(), snakesNumbers.end(),
         -this->tileSteps(Board::Snake));

    // shuffle numbers
    random_shuffle(laddersNumbers.begin(), laddersNumbers.end());
    random_shuffle(snakesNumbers.begin(), snakesNumbers.end());

    // add the ladders
    for (size_t i = 0; i < maxSpecialTiles / 2; i++) {
        this->d_board[laddersNumbers[i]] = Ladder;
    }

    // add the snakes
    for (size_t i = 0; i < maxSpecialTiles / 2; i++) {
        this->d_board[snakesNumbers[i]] = Snake;
    }
}

size_t Board::size() { return this->d_board.size(); }

string Board::tileString(size_t tileNumber) {
    TileType type = this->d_board[tileNumber];

    if (type == Snake) {
        return "S";
    } else if (type == Ladder) {
        return "L";
    } else {
        return "N";
    }
}

// private version
int Board::tileSteps(TileType type) {
    if (type == Snake) {
        return -3;
    } else if (type == Ladder) {
        return 3;
    } else {
        return 0;
    }
}

// public version
int Board::tileSteps(size_t tileNumber) {
    return this->tileSteps(this->d_board[tileNumber]);
}

// only used for getting, NOT setting
string Board::operator[](size_t tileNumber) {
    return this->tileString(tileNumber);
}
