#include <string>
#include <vector>

const size_t DEFAULT_BOARD_SIZE = 30;
const size_t DEFAULT_MAX_SPECIAL_TILES = 14;

class Board {
private:
    enum TileType { Snake, Ladder, Normal };

    std::vector<TileType> d_board;

    int tileSteps(TileType type);

public:
    Board();
    Board(size_t boardSize, size_t specialTiles);

    size_t size();

    std::string tileString(size_t tileNumber);
    int tileSteps(size_t tileNumber);

    std::string operator[](size_t tileNumber);
};
