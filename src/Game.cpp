#include "Game.hpp"
#include <iostream>

using namespace std;

Game::Game() : Game(cin, cout) {}

Game::Game(istream &is, ostream &os)
    : d_in(is), d_out(os), d_die(), d_board(),
      d_players(DEFAULT_PLAYERS_NUMBER), d_maxTurns(DEFAULT_MAX_TURNS),
      d_turnNumber(1) {

    size_t numberOfPlayers = DEFAULT_PLAYERS_NUMBER;

    for (size_t i = 0; i < numberOfPlayers; i++) {
        d_players[i] = Player(i + 1);
    }
}

Game::Game(istream &is, ostream &os, size_t boardSize, size_t numberOfSnakes,
           size_t numberOfLadders, int snakePenalty, int ladderReward,
           size_t numberOfPlayers, unsigned int maxTurns)
    : d_in(is), d_out(os), d_die(),
      d_board(boardSize, numberOfSnakes, numberOfLadders, snakePenalty,
              ladderReward),
      d_players(numberOfPlayers), d_maxTurns(maxTurns), d_turnNumber(1) {

    for (size_t i = 0; i < numberOfPlayers; i++) {
        d_players[i] = Player(i + 1);
    }
}

void Game::turn(Player *player) {
    unsigned int roll = this->d_die.roll();
    size_t position = player->position();
    size_t boardSize = this->d_board.size();

    this->d_out << this->d_turnNumber << " ";
    this->d_out << player->number() << " ";
    this->d_out << position + 1 << " ";
    this->d_out << roll << " ";

    // handle roll that falls outside of the board
    size_t rollTileNumber;
    if (position + roll > boardSize - 1) {
        rollTileNumber = boardSize - 1;
    } else {
        rollTileNumber = position + roll;
    }

    this->d_out << this->d_board[rollTileNumber] << " ";

    int steps = this->d_board.tileSteps(rollTileNumber);
    size_t newPosition = rollTileNumber + steps;

    // handle steps that fall outside the board
    if (steps < 0 && position < unsigned(abs(steps))) {
        newPosition = 0;
    } else if (newPosition > boardSize - 1) {
        newPosition = boardSize - 1;
    }

    player->setPosition(newPosition);

    this->d_out << newPosition + 1 << " ";
    this->d_out << endl;

    this->d_turnNumber++;
}

void Game::start() {
    // start with first player
    Player *currentPlayer = &this->d_players[0];

    while (this->d_turnNumber <= this->d_maxTurns) {
        if (!this->turnPrompt()) {
            this->d_out << "Thanks for playing!!!" << endl;
            break;
        }

        // start the turn
        this->turn(currentPlayer);

        if (currentPlayer->position() >= this->d_board.size() - 1) {
            break;
        }

        // increment to the next player
        currentPlayer =
            &this->d_players[currentPlayer->number() % this->d_players.size()];
    }

    this->d_out << "-- GAME OVER --" << endl;

    if (this->d_turnNumber == this->d_maxTurns) {
        this->d_out << "The maximum number of turns has been reached..."
                    << endl;
    }

    if (currentPlayer->position() >= this->d_board.size() - 1) {
        this->d_out << "Player " << currentPlayer->number()
                    << " is the winner!!!" << endl;
        return;
    }
}

Game::~Game() {}
