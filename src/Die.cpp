#include "Die.hpp"
#include <random>

// again with constructor delegation :)
Die::Die() : Die(DEFAULT_SIDES) {}

Die::Die(unsigned int sides) { this->d_numberOfSides = sides; }

unsigned int Die::roll() {
    // https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range

    std::random_device rd;  // initialise seed engine
    std::mt19937 rng(rd()); // Mersenne-Twister random-number engine
    std::uniform_int_distribution<unsigned int> uni(1, this->d_numberOfSides);

    return uni(rng);
}
