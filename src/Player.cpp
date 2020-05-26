#include "Player.hpp"

using namespace std;

Player::Player() {}

Player::Player(unsigned int playerNumber) {
    this->d_playerNumber = playerNumber;
    this->d_currentPosition = 0;
}

unsigned int Player::number() { return this->d_playerNumber; }

size_t Player::position() { return this->d_currentPosition; }

void Player::setPosition(size_t newPosition) {
    this->d_currentPosition = newPosition;
}
