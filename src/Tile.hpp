#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
protected:
    std::string d_string;
    int d_steps;

public:
    Tile();
    Tile(std::string stringName, int steps);

    std::string toString();
    int steps();
};

#endif
