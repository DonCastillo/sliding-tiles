#include "Board_Tile.h"
#include <string>

Board_Tile::Board_Tile(const std::string& pConfig) {
    config = pConfig;
}

Board_Tile::~Board_Tile() {}


std::vector<Board_Tile> Board_Tile::nextConfigs() {

    std::vector<Board_Tile> temp;

    // get 0 index
    int indexOfZero = getIndexOfZero();

    // move up
    if (canMoveTo('U')) {
        std::swap( config[indexOfZero], config[indexOfZero - 3]);
        std::cout << "Up: " << config << std::endl;
    }

    // move down
    if (canMoveTo('D')) {
        std::swap( config[indexOfZero], config[indexOfZero + 3]);
        std::cout << "Down: " << config << std::endl;
    }

    // move left
    if (canMoveTo('L')) {
        std::swap( config[indexOfZero], config[indexOfZero - 1]);
        std::cout << "Left: " << config << std::endl;
    }

    // move right
    if (canMoveTo('R')) {
        std::swap( config[indexOfZero], config[indexOfZero + 1]);
        std::cout << "Right: " << config << std::endl;
    }
    return temp;
}



int Board_Tile::numMoves() {

}

int Board_Tile::Manhattan_Distance(const Board_Tile& goalconfig) {

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
