#ifndef LADDERTILE_H
#define LADDERTILE_H

#include "Tile.hpp"

const int DEFAULT_LADDER_STEPS = 3;

class LadderTile : public Tile {
public:
    LadderTile();
    LadderTile(int steps);
};

#endif
