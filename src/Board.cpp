#include "Board.hpp"
#include "LadderTile.hpp"
#include "NormalTile.hpp"
#include "SnakeTile.hpp"
#include "Tile.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// default constructor
Board::Board() : Board(DEFAULT_BOARD_SIZE, DEFAULT_SNAKES, DEFAULT_LADDERS) {}

// custom constructor
Board::Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders,
             int snakePenalty, int ladderReward)
    : Board(boardSize, numberOfSnakes, numberOfLadders, SnakeTile(snakePenalty),
            LadderTile(ladderReward)) {}

// private constructor, only used by the other two overloaded constructors
Board::Board(size_t boardSize, size_t numberOfSnakes, size_t numberOfLadders,
             Tile snake, Tile ladder) {

    // initialize the pointers
    this->d_snake = new SnakeTile(int(snake));
    this->d_ladder = new LadderTile(int(ladder));
    this->d_normal = new NormalTile();

    // initialize the pointer vector, since they all are the same anyways a
    // pointer vector is just enough
    this->d_tiles = vector<Tile *>(boardSize, this->d_normal);

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
    // point pointers to pointy places
    for (size_t i = 0; i < specialTiles; i++) {
        if (i < numberOfSnakes) {
            this->d_tiles[possiblePlaces[i]] = this->d_snake;
        } else {
            this->d_tiles[possiblePlaces[i]] = this->d_ladder;
        }
    }
}

// delete the tile pointers
Board::~Board() {
    delete this->d_snake;
    delete this->d_ladder;
    delete this->d_normal;
}

size_t Board::size() { return this->d_tiles.size(); }

string Board::tileString(size_t tileNumber) {
    return string(*this->d_tiles[tileNumber]);
}

int Board::tileSteps(size_t tileNumber) {
    return int(*this->d_tiles[tileNumber]);
}

// only used for getting, NOT setting
string Board::operator[](size_t tileNumber) {
    return this->tileString(tileNumber);
}
