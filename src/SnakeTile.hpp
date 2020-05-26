#ifndef SNAKETILE_H
#define SNAKETILE_H

#include "Tile.hpp"

const int DEFAULT_SNAKE_STEPS = -3;

class SnakeTile : public Tile {
public:
    SnakeTile();
    SnakeTile(int steps);
};

#endif
