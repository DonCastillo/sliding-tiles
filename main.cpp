#include <iostream>
#include "Sliding_Solver.h"
#include "BinaryHeap.h"
#include <iostream>


int main()
{
    std::string initConfig = "120453786";
    std::string goalConfig = "123450786";
    Sliding_Solver solver(initConfig, goalConfig);

    // initial board
    Board_Tile board("123405678", "", 0);

    // goal board
    Board_Tile goal("123456780", "", 0);
    std::cout << board.getConfig() << std::endl;
    //std::cout << board.nextConfigs().size() << std::endl;
    for (Board_Tile b : board.nextConfigs()) {
        std::cout << "---" << std::endl;
        std::cout << "current: " << b.getConfig() << std::endl;
        std::cout << "AC: " << b.getAC() << std::endl;
        std::cout << "MovesFromStart: " << b.getMovesFromStart() << std::endl;

        //b.getConfig();
    }
    board.Manhattan_Distance(goal);
    //board.getConfig();
    //std::cout << board.getIndexOfZero() << std::endl;
    //std::cout << std::boolalpha << board.canMoveTo('U');
    return 0;
}

