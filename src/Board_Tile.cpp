#include "Board_Tile.h"
#include <string>

Board_Tile::Board_Tile(const std::string& pConfig,
                       const std::string& pMoves,
                       const int pAC) {
    config = pConfig;
    movesFromStart = pMoves;
    AC = pAC;
}

Board_Tile::~Board_Tile() {}


std::vector<Board_Tile> Board_Tile::nextConfigs() {

    std::vector<Board_Tile> temp;

    // get 0 index
    int indexOfZero = getIndexOfZero();


    // move up
    if (canMoveTo('U')) {
        std::string newConfig = config;
        std::swap( newConfig[indexOfZero], newConfig[indexOfZero - 3]);
        Board_Tile board(newConfig, movesFromStart+'U', AC+1);
        temp.push_back(board);
    }

    // move down
    if (canMoveTo('D')) {
        std::string newConfig = config;
        std::swap( newConfig[indexOfZero], newConfig[indexOfZero + 3]);
        Board_Tile board(newConfig, movesFromStart+'D', AC+1);
        temp.push_back(board);
    }

    // move left
    if (canMoveTo('L')) {
        std::string newConfig = config;
        std::swap( newConfig[indexOfZero], newConfig[indexOfZero - 1]);
        Board_Tile board(newConfig, movesFromStart+'L', AC+1);
        temp.push_back(board);
    }

    // move right
    if (canMoveTo('R')) {
        std::string newConfig = config;
        std::swap( newConfig[indexOfZero], newConfig[indexOfZero + 1]);
        Board_Tile board(newConfig, movesFromStart+'R', AC+1);
        temp.push_back(board);
    }
    return temp;
}



int Board_Tile::Manhattan_Distance(const Board_Tile& goalconfig) {
    /*std::string goalConfig = goalconfig.getConfig();
    std::string currentConfig = getConfig();

    for (int i = 0; i < goalConfig.length(); ++i) {
        for (int j = i; j < currentConfig.length(); ++j) {

        }
    }*/
}

std::string Board_Tile::getConfig() {
    return config;
}
int Board_Tile::getAC() {
    return AC;
}
int Board_Tile::getEC() {
    return EC;
}
int Board_Tile::getDC() {
    return DC;
}


bool Board_Tile::canMoveTo(const char direction) {

    char lastMove = getLastMove();
    int indexOfZero = getIndexOfZero();


    switch( toupper(direction) ) {
        case 'U': {
            if (lastMove != 'D') {
                if ((indexOfZero - 3) >= 0) {
                   return true;
                }
            }
        } break;

        case 'D': {
            if (lastMove != 'U') {
                if ((indexOfZero + 3) <= 8) {
                    return true;
                }
            }
        } break;

        case 'R': {
            if (lastMove != 'L') {
                if (((indexOfZero + 1) % 3) > 0) {
                    return true;
                }
            }
        } break;

        case 'L': {
            if (lastMove != 'R') {
                if ( (((indexOfZero - 1) % 3) < 2) &&
                     (((indexOfZero - 1) % 3) > -1)) {
                        return true;
                     }
            }
        } break;
        default:
            break;;
    }
    return false;
}



int Board_Tile::numMoves() {
    return movesFromStart.length();
}


char Board_Tile::getLastMove(){
    return movesFromStart[(movesFromStart.length())-1];
}



int Board_Tile::getIndexOfZero() {
    for(int i = 0; i < config.length(); ++i) {
        if(config[i] == '0') {
            return i;
        }
    }
    return -1;
}

std::string Board_Tile::getMovesFromStart(){
    return movesFromStart;
}
