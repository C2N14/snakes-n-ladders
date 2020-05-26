#ifndef MANUALGAME_H
#define MANUALGAME_H

#include "Game.hpp"

class ManualGame : public Game {
protected:
    bool turnPrompt();

public:
    using Game::Game;

    ~ManualGame();
};

#endif
