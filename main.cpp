#include <iostream>
#include <string>
#include "Sliding_Solver.h"
#include "BinaryHeap.h"



int main()
{
    std::string initConfig = "120453786";
    std::string goalConfig = "123450786";
    Sliding_Solver solver(initConfig, goalConfig);
    solver.Solve_Puzzle();

   /* // initial board
    Board_Tile board("123045786", "", 0);

    // goal board
    Board_Tile goal("123456780", "", 0);
    std::cout << board.getConfig() << std::endl;
    for (Board_Tile b : board.nextConfigs()) {
            b.Manhattan_Distance(goal);
            std::cout << "---" << std::endl;
            std::cout << "current: " << b.getConfig() << std::endl;
            std::cout << "AC: " << b.getAC() << std::endl;
            std::cout << "EC: " << b.getEC() << std::endl;
            std::cout << "DC: " << b.getDC() << std::endl;
            std::cout << "MovesFromStart: " << b.getMovesFromStart() << std::endl;
            std::cout << "NumOfMoves: " << b.numMoves() << std::endl;

        for (Board_Tile c : b.nextConfigs())
        {
            c.Manhattan_Distance(goal);
            std::cout << "---" << std::endl;
            std::cout << "current: " << c.getConfig() << std::endl;
            std::cout << "AC: " << c.getAC() << std::endl;
            std::cout << "EC: " << c.getEC() << std::endl;
            std::cout << "DC: " << c.getDC() << std::endl;
            std::cout << "MovesFromStart: " << c.getMovesFromStart() << std::endl;
            std::cout << "NumOfMoves: " << c.numMoves() << std::endl;
        }
    }
    board.Manhattan_Distance(goal);*/

    return 0;
}


