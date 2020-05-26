#include <cstddef> // why do I need to include this??? ('size_t' not defined)

// I'm not really sure if a default constructor would make sense here...
class Player {
private:
    size_t d_currentPosition;
    unsigned int d_playerNumber;

public:
    Player(unsigned int playerNumber);

    unsigned int number();

    size_t position();
    void setPosition(size_t newPosition);
};
