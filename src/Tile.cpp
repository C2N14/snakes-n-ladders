#include "Tile.hpp"

using namespace std;

Tile::Tile() {}

Tile::Tile(std::string stringName, int steps)
    : d_string(stringName), d_steps(steps) {}

string Tile::toString() { return this->d_string; }

int Tile::steps() { return this->d_steps; }
