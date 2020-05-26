#include "Board.hpp"
#include "Die.hpp"
#include "Player.hpp"
#include <ctime>
#include <fstream>
#include <iostream>

#ifdef OUT_FILENAME
#define OUT_FILENAME "snakes"
#endif

using namespace std;

const unsigned int MAX_TURNS = 100;

class MyGame {
private:
    istream &d_in;
    ostream &d_out;

    Die d_die;
    Board d_board;

    unsigned int d_turnNumber;

    bool askToContinue() {
        istream &in(this->d_in);
        ostream &out(this->d_out);

        string choice;
        bool firstTry = true;
        do {
            if (firstTry) {
                firstTry = false;
            } else {
                out << "Invalid option, please press C to continue next turn "
                       "or E to end the game"
                    << endl;
            }

            in >> choice;
        } while (choice != "C" && choice != "E");

        if (choice == "C") {
            return true;
        } else {
            return false;
        }
    }

    void turn(Player *player) {
        Die die(d_die);
        Board board(d_board);
        ostream &out(this->d_out);

        unsigned int roll = die.roll();

        out << this->d_turnNumber << " ";
        out << player->number() << " ";
        out << player->position() + 1 << " ";
        out << roll << " ";

        size_t rollTileNumber = player->position() + roll;

        out << board[rollTileNumber] << " ";

        size_t newPosition = rollTileNumber + board.tileSteps(rollTileNumber);
        newPosition =
            newPosition > board.size() - 1 ? board.size() - 1 : newPosition;

        player->setPosition(newPosition);

        out << player->position() + 1 << " ";
        out << endl;

        this->d_turnNumber++;
    }

public:
    MyGame() : MyGame(cin, cout) {} // constructor delegation!
    MyGame(istream &is, ostream &os)
        : d_in(is), d_out(os), d_die(), d_board(), d_turnNumber(1) {}

    void start() {
        ostream &out(this->d_out);
        Board board(this->d_board);

        Player p1(1);
        Player p2(2);

        Player *currentPlayer = &p1;

        out << "Press C to continue next turn, or E to end the game:" << endl;

        while (this->d_turnNumber < MAX_TURNS) {
            if (!this->askToContinue()) {
                out << "Thanks for playing!!!" << endl;
                break;
            }

            // start the turn
            this->turn(currentPlayer);

            if (currentPlayer->position() >= board.size() - 1) {
                break;
            }

            // switch players for next turn
            if (currentPlayer == &p1) {
                currentPlayer = &p2;
            } else {
                currentPlayer = &p1;
            }
        }

        out << "-- GAME OVER --" << endl;

        if (this->d_turnNumber == MAX_TURNS - 1) {
            out << "The maximum number of turns has been reached..." << endl;
        }

        if (p1.position() >= board.size() - 1) {
            out << "Player 1 is the winner!!!" << endl;
        } else if (p2.position() >= board.size() - 1) {
            out << "Player 2 is the winner!!!" << endl;
        }
    }
};

int main(int argc, char **argv) {

    if (argc != 1 && argc != 3) {
        cout << "Usage: ./" << OUT_FILENAME << " OR ./" << OUT_FILENAME
             << " fileIn fileOut" << endl;
        return 1;
    }

    // seed the randomness!
    srand(time(NULL));

    MyGame *game;

    ifstream fileIn;
    ofstream fileOut;

    if (argc == 3) {
        fileIn.open(argv[1]);
        if (!fileIn.is_open() || fileIn.fail()) {
            cout << "ERROR: Couldn't open " << argv[1] << endl;
            return 2;
        }

        fileOut.open(argv[2]);
        if (!fileOut.is_open() || fileOut.fail()) {
            cout << "ERROR: Couldn't open " << argv[2] << endl;
            return 2;
        }

        game = new MyGame(fileIn, fileOut);

    } else {
        game = new MyGame();
    }

    game->start();

    delete game;

    if (argc == 3) {
        fileIn.close();
        fileOut.close();
    }

    return 0;
}
