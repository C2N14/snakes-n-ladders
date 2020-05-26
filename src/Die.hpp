const unsigned int DEFAULT_SIDES = 6;

class Die {
private:
    unsigned int d_numberOfSides;

public:
    Die();
    Die(unsigned int sides);

    unsigned int roll();
};
