#ifndef GAME_H
#define GAME_H

#include "Board.hpp"
#include "Die.hpp"
#include "Player.hpp"
#include <vector>

const unsigned int DEFAULT_MAX_TURNS = 100;
const size_t DEFAULT_PLAYERS_NUMBER = 2;

class Game {
protected:
    std::istream &d_in;
    std::ostream &d_out;

    Die d_die;
    Board d_board;
    std::vector<Player> d_players;

    unsigned int d_maxTurns;
    unsigned int d_turnNumber;

    virtual bool turnPrompt() = 0;
    void turn(Player *player);

public:
    Game();
    Game(std::istream &is, std::ostream &os);
    Game(std::istream &is, std::ostream &os, size_t boardSize,
         size_t numberOfSnakes, size_t numberOfLadders, int snakePenalty,
         int ladderReward, size_t numberOfPlayers, unsigned int maxTurns);

    void start();

    // pesky warnings...
    virtual ~Game();
};

#endif
