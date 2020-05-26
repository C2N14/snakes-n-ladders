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
    Die die(d_die);
    Board board(d_board);
    ostream &out(this->d_out);

    unsigned int roll = die.roll();
    size_t position = player->position();
    size_t boardSize = board.size();

    out << this->d_turnNumber << " ";
    out << player->number() << " ";
    out << position + 1 << " ";
    out << roll << " ";

    // handle roll that falls outside of the board
    size_t rollTileNumber;
    if (position + roll > boardSize - 1) {
        rollTileNumber = boardSize - 1;
    } else {
        rollTileNumber = position + roll;
    }

    out << board[rollTileNumber] << " ";

    int steps = board.tileSteps(rollTileNumber);
    size_t newPosition = rollTileNumber + steps;

    // handle steps that fall outside the board
    if (steps < 0 && position < unsigned(abs(steps))) {
        newPosition = 0;
    } else if (newPosition > boardSize - 1) {
        newPosition = boardSize - 1;
    }

    player->setPosition(newPosition);

    out << newPosition + 1 << " ";
    out << endl;

    this->d_turnNumber++;
}

void Game::start() {
    ostream &out(this->d_out);
    Board board(this->d_board);

    Player *currentPlayer = &this->d_players[0];

    while (this->d_turnNumber <= this->d_maxTurns) {
        if (!this->turnPrompt()) {
            out << "Thanks for playing!!!" << endl;
            break;
        }

        // start the turn
        this->turn(currentPlayer);

        if (currentPlayer->position() >= board.size() - 1) {
            break;
        }

        // increment to the next player
        currentPlayer =
            &this->d_players[currentPlayer->number() % this->d_players.size()];
    }

    out << "-- GAME OVER --" << endl;

    if (this->d_turnNumber == this->d_maxTurns) {
        out << "The maximum number of turns has been reached..." << endl;
    }

    for (auto player : this->d_players) {
        if (player.position() >= board.size() - 1) {
            out << "Player " << player.number() << " is the winner!!!" << endl;
            return;
        }
    }
}

Game::~Game() {}
