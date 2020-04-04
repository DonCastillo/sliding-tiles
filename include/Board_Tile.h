
/** @author Don Castillo
 *  @brief  Header of the Board_Tile class
 *
 */

#ifndef BOARD_TILE_H
#define BOARD_TILE_H
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>

class Board_Tile
{
    // 3 X 3 tile board current configuration
    std::string config;

    // number of moves from the intitial configuration to the current configuration
    int AC = 0;

    // estimated number of moves needed to reach
    // the goal configuration as determined by the Manhattan Distance
    int EC;

    // DC = AC + EC
    // Sum of Manhattan Distance and the number of moves from the
    // initial configuration to the current configuration
    int DC;

    // moves or steps that led to the current configuration
    // from a given start configuration e.g. URRD
    std::string movesFromStart = "";

    public:

        Board_Tile() {}

        /** @brief  constructor of Board_Tile object
         *  @param  pConfig     current configuration
         *          pMoves      cumulative moves from the initial configuration
         *          AC          distance of current configuration from the initial
         */
        Board_Tile(const std::string& pConfig, const std::string& pMoves = "", const int pAC = 0);

        virtual ~Board_Tile();


        /** @brief  returns at most 4 Board_Tile objects that have different
         *          configurations of the current board configuration
         */
        std::vector<Board_Tile> nextConfigs();

        /**
         *  @brief  takes a Board_Tile object goalconfig representing the goal configuration
         *          and returns the value of the Manhattan distance of the object
         *  @param  goalconfig  goal board
         */
        int Manhattan_Distance(const Board_Tile& goalconfig);

        /** @brief  determine if '0' can be moved UP, DOWN, RIGHT, LEFT
         */
        bool canMoveTo(const char direction);



        /**********************
            @brief  Getters
        ************************/

        // returns the current configuration of the board in string
        std::string getConfig() const;

        // returns AC
        int getAC();

        // returns EC
        int getEC();

        // returns DC
        int getDC();

        // returns index of '0' in the configuration
        int getIndexOfZero();

        // returns last previous move
        char getLastMove();

        // number of moves it took from the initial board to
        // reach the current configuration
        int numMoves();

        // returns movesFromStart
        std::string getMovesFromStart();

        // returns X, Y coordinates of a character in the board
        /*      00  01  02
                10  11  12
                20  21  22
        */
        int getXCoordinate(int index);
        int getYCoordinate(int index);


        /**********************
            @brief  Operators, to be used in the
                    Binary Heap Class
        ************************/
        bool operator==(const Board_Tile& b) const;
        bool operator!=(const Board_Tile& b) const;
        bool operator> (const Board_Tile& b) const;
        bool operator< (const Board_Tile& b) const;
        bool operator>= (const Board_Tile& b) const;
        bool operator<= (const Board_Tile& b) const;
};

#endif // BOARD_TILE_H
