#include <iostream>
#include "Sliding_Solver.h"
#include "BinaryHeap.h"
#include <iostream>


int main()
{
    std::string initConfig = "120453786";
    std::string goalConfig = "123456780";
    Sliding_Solver solver(initConfig, goalConfig);

    Board_Tile board("123405678");
    std::cout << board.getConfig() << std::endl;
    board.nextConfigs();
    //board.getConfig();
    //std::cout << board.getIndexOfZero() << std::endl;
    //std::cout << std::boolalpha << board.canMoveTo('U');
    return 0;
}

