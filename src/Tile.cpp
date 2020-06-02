#include "Tile.hpp"

using namespace std;

Tile::Tile() {}

Tile::Tile(std::string stringName, int steps)
    : d_string(stringName), d_steps(steps) {}

Tile::operator string() const { return this->d_string; }

Tile::operator int() const { return this->d_steps; }
