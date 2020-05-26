#include "LadderTile.hpp"

LadderTile::LadderTile() : LadderTile(DEFAULT_LADDER_STEPS) {}

LadderTile::LadderTile(int steps) : Tile("L", steps) {}
