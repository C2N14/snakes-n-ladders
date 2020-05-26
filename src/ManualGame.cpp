#include "ManualGame.hpp"

#include <iostream>

using namespace std;

bool ManualGame::turnPrompt() {
    istream &in(this->d_in);
    ostream &out(this->d_out);

    if (this->d_turnNumber == 1) {
        out << "Press C to continue next turn, or E to end the game:" << endl;
    }

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

ManualGame::~ManualGame() {}
