#include "Board.hpp"
#include "LadderTile.hpp"
#include "NormalTile.hpp"
#include "SnakeTile.hpp"
#include "Tile.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// I really don't know if I love this chain of delegated constructors, but it
// was the solution I found worked the best to have each class call its default
// constructor without aggregating all constants in a single file

Board::Board() : Board(DEFAULT_BOARD_SIZE, DEFAULT_SNAKES, DEFAULT_LADDERS) {}

Board::Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders)
    : Board(boardSize, numberOfSnakes, numberOfLadders, SnakeTile(),
            LadderTile(), NormalTile()) {}

Board::Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders,
             int snakePenalty, int ladderReward)
    : Board(boardSize, numberOfSnakes, numberOfLadders, SnakeTile(snakePenalty),
            LadderTile(ladderReward), NormalTile()) {}

Board::Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders,
             Tile snake, Tile ladder, Tile normal)
    : d_tiles(boardSize, normal) {

    size_t specialTiles = numberOfSnakes + numberOfLadders;

    if (numberOfSnakes > boardSize - 2) {
        numberOfSnakes = boardSize - 2;
        numberOfLadders = 0;
    } else if (specialTiles > boardSize - 2) {
        numberOfLadders = boardSize - numberOfSnakes - 2;
    }

    specialTiles = numberOfSnakes + numberOfLadders;

    vector<size_t> possiblePlaces(boardSize - 2); // leave out the first & last
    iota(possiblePlaces.begin(), possiblePlaces.end(), 1);

    random_shuffle(possiblePlaces.begin(), possiblePlaces.end());

    // prioritize snakes, obviously ;)
    for (size_t i = 0; i < specialTiles; i++) {
        if (i < numberOfSnakes) {
            this->d_tiles[possiblePlaces[i]] = snake;
        } else {
            this->d_tiles[possiblePlaces[i]] = ladder;
        }
    }
}

size_t Board::size() { return this->d_tiles.size(); }

string Board::tileString(size_t tileNumber) {
    return this->d_tiles[tileNumber].toString();
}

int Board::tileSteps(size_t tileNumber) {
    return this->d_tiles[tileNumber].steps();
}

// only used for getting, NOT setting
string Board::operator[](size_t tileNumber) {
    return this->tileString(tileNumber);
}
