#include "SnakeTile.hpp"

SnakeTile::SnakeTile() : SnakeTile(DEFAULT_SNAKE_STEPS) {}

SnakeTile::SnakeTile(int steps) : Tile("S", steps) {}
