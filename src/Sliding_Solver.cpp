#include "Sliding_Solver.h"
#include <string>

Sliding_Solver::Sliding_Solver(const std::string& pInitConfig,
                               const std::string& pGoalConfig)
{
    initBoard = Board_Tile(pInitConfig, "", 0);
    goalBoard = Board_Tile(pGoalConfig, "", 0);

    for (Board_Tile b : initBoard.nextConfigs()) {
            //b.Manhattan_Distance(goalBoard);
            std::cout << "---" << std::endl;
            std::cout << "current: " << b.getConfig() << std::endl;
            std::cout << "AC: " << b.getAC() << std::endl;
            std::cout << "EC: " << b.Manhattan_Distance(goalBoard) << std::endl;
            std::cout << "DC: " << b.getDC() << std::endl;
            std::cout << "MovesFromStart: " << b.getMovesFromStart() << std::endl;
            std::cout << "NumOfMoves: " << b.numMoves() << std::endl;
            tileQueue.insert(b);
    }
    //tileQueue.insert()
}

Sliding_Solver::~Sliding_Solver()
{

}

void Sliding_Solver::Solve_Puzzle()
{
    /*std::cout << "Hello";
    Board_Tile a("123456780", "UD", 2);
    Board_Tile b("123456780", "UD", 2);
    std::cout << std::boolalpha << (a==b);
    std::cout << "\n---------" << std::endl;
    tileQueue.deleteMin();
    std::cout << tileQueue.findMin().getConfig();*/
}
