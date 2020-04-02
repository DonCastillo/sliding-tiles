#ifndef BOARD_TILE_H
#define BOARD_TILE_H
#include <string>
#include <vector>

class Board_Tile
{
    // 3 X 3 tile board configuration
    std::string config;

    // moves or steps that led to config from a given start configuration
    std::string movesFromStart;

    public:

        // pass the initial configuration of the tile board
        Board_Tile(const std::string&);

        virtual ~Board_Tile();

        // list of Board_Tile at most 4 objects that are one move away from the current object
        std::vector<Board_Tile> nextConfigs();

        // number of moves it took from the initial board to reach the current configuration
        int numMoves();

        // takes a Board_Tile object goalconfig representing the goal configuration
        // and returns the value of the Manhattan distance of the object
        int Manhattan_Distance(const Board_Tile& goalconfig);

};

#endif // BOARD_TILE_H
