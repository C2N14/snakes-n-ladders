#ifndef AUTOMATICGAME_H
#define AUTOMATICGAME_H

#include "Game.hpp"

class AutomaticGame : public Game {
protected:
    bool turnPrompt();

public:
    using Game::Game;

    ~AutomaticGame();
};

#endif
