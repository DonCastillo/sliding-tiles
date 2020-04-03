#ifndef BOARD_TILE_H
#define BOARD_TILE_H
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>

class Board_Tile
{
    // 3 X 3 tile board current configuration
    std::string config;
    int AC;
    int EC;
    int DC;

    // moves or steps that led to config from a given start configuration
    // previous configuration before the current configuration
    // e.g. URRD
    std::string movesFromStart = "";

    public:

        // pass the initial configuration of the tile board
        Board_Tile(const std::string& pConfig, const std::string& pMoves, const int pAC);

        virtual ~Board_Tile();

        // list of Board_Tile at most 4 objects that are one move away from the current object
        // returns at most 4 Board_Tile that has different configurations of current board config
        std::vector<Board_Tile> nextConfigs();

        // number of moves it took from the initial board to reach the current configuration
        int numMoves();

        // takes a Board_Tile object goalconfig representing the goal configuration
        // and returns the value of the Manhattan distance of the object
        /*
            AC = (number of moves from the initial config to curent config)
            EC = (estimated number of moves from the current config to goal config)
            Manhattan Distance (MD) = AC + EC
        */
        int Manhattan_Distance(const Board_Tile& goalconfig);

        std::string getConfig();
        int getAC();
        int getEC();
        int getDC();
        int getIndexOfZero();
        char getLastMove();
        bool canMoveTo(const char direction);
        void printBoard();
        std::string getMovesFromStart();
};

#endif // BOARD_TILE_H
