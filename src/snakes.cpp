#include "AutomaticGame.hpp"
#include "Game.hpp"
#include "ManualGame.hpp"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <utility>

using namespace std;

const string OUT_FILENAME = "snakes";

template <class T>
pair<T, bool> parseArgument(ostream &out, string argumentName,
                            string argumentString, bool previousSucess,
                            vector<T> possibleValues = {},
                            bool excludeMode = false);

int main(int argc, char **argv) {

    // 1 == ./snakes
    // 3 == ./snakes in out
    // 9 == ./snakes n n n n n n n s
    // 11 == ./snakes in out n n n n n n n s
    if (argc != 1 && argc != 3 && argc != 9 && argc != 11) {
        cout << "Usage: ./" << OUT_FILENAME << " OR ./" << OUT_FILENAME
             << " fileIn fileOut"
             << " with the following optional arguments:\n[n (board size) n "
                "(snakes) n (ladders) n (snake penalty) n (ladder reward) n "
                "(players) n (max turns) a/m (auto/manual)]"
             << endl;
        return 1;
    }

    // seed the randomness!
    srand(time(NULL));

    Game *game;

    ifstream fileIn;
    ofstream fileOut;

    // these need to be NULL because they are protected???
    istream in(NULL);
    ostream out(NULL);

    // if in and out files are specified, with or without optional parameters
    if (argc == 3 || argc == 11) {
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

        // point the streams to the file
        in.rdbuf(fileIn.rdbuf());
        out.rdbuf(fileOut.rdbuf());

    } else {
        // point the streams to the terminal
        in.rdbuf(cin.rdbuf());
        out.rdbuf(cout.rdbuf());
    }

    // if optional parameters are used
    if (argc == 9 || argc == 11) {

        // handle both file and console modes
        unsigned int argOffset = 0;
        if (argc == 11) {
            argOffset = 2;
        }

        // I REALLY wanted to code this with try/catch and exceptions like in
        // Python, but everything I read on StackOverflow said exceptions in C++
        // are for EXCEPTIONAL cases, and that they are code smell :S

        bool sucess = true;
        size_t boardSize, numberOfSnakes, numberOfLadders, numberOfPlayers;
        int snakePenalty, ladderReward;
        unsigned int maxTurns;
        char autoOrManual;

        tie(boardSize, sucess) = parseArgument<size_t>(
            out, "board size", argv[argOffset + 1], sucess, {0, 1}, true);

        tie(numberOfSnakes, sucess) = parseArgument<size_t>(
            out, "number of snakes", argv[argOffset + 2], sucess);

        tie(numberOfLadders, sucess) = parseArgument<size_t>(
            out, "number of ladders", argv[argOffset + 3], sucess);

        tie(snakePenalty, sucess) = parseArgument<int>(
            out, "snake penalty", argv[argOffset + 4], sucess, {0}, true);

        tie(ladderReward, sucess) = parseArgument<int>(
            out, "ladder reward", argv[argOffset + 5], sucess, {0}, true);

        tie(numberOfPlayers, sucess) = parseArgument<size_t>(
            out, "number of players", argv[argOffset + 6], sucess, {0}, true);

        tie(maxTurns, sucess) =
            parseArgument<size_t>(out, "maximum ammount of turns",
                                  argv[argOffset + 7], sucess, {0}, true);

        tie(autoOrManual, sucess) = parseArgument<char>(
            out, "automatic or manual turn", argv[argOffset + 8], sucess,
            {'a', 'A', 'm', 'M'});

        // if any of the optional parameters could not be set, exit
        if (!sucess) {
            if (argc == 3 || argc == 11) {
                fileIn.close();
                fileOut.close();
            }
            return 3;
        }

        if (tolower(autoOrManual) == 'a') {

            game = new AutomaticGame(in, out, boardSize, numberOfSnakes,
                                     numberOfLadders, snakePenalty,
                                     ladderReward, numberOfPlayers, maxTurns);
        } else {

            game = new ManualGame(in, out, boardSize, numberOfSnakes,
                                  numberOfLadders, snakePenalty, ladderReward,
                                  numberOfPlayers, maxTurns);
        }

    } else {
        game = new ManualGame(in, out);
    }

    game->start();

    delete game;

    if (argc == 3 || argc == 11) {
        fileIn.close();
        fileOut.close();
    }

    return 0;
}

// returns false if there was an error
// takes into account if there was an error parsing an argument before as to not
// overwrite the 'sucess' variable
// I know, it's a mess :S
template <typename T>
pair<T, bool> parseArgument(ostream &out, string argumentName,
                            string argumentString, bool previousSucess,
                            vector<T> possibleValues, bool excludeMode) {

    T returnValue;
    bool isInVector;

    stringstream ss(argumentString);

    // if couldnt convert the input into the required return value
    if (!(ss >> returnValue)) {
        out << "ERROR: Couldn't parse " << argumentString << " for "
            << argumentName << endl;

        // use the default constructor for the data type
        return make_pair(T(), false);

    } else {
        // if a vector of possible values is specified, find if the input value
        // is in this vector
        if (!possibleValues.empty()) {

            isInVector = find(possibleValues.begin(), possibleValues.end(),
                              returnValue) != possibleValues.end();

            if ((isInVector && !excludeMode) || (!isInVector && excludeMode)) {
                return make_pair(returnValue, previousSucess);

            } else {
                out << "ERROR: " << argumentString
                    << " is an invalid value for " << argumentName << endl;

                // use the default constructor for the data type
                return make_pair(T(), false);
            }

        } else {
            return make_pair(returnValue, previousSucess);
        }
    }
}
