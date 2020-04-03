#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H
#include "BinaryHeap.h"
#include "Board_Tile.h"
#include <string>

class Sliding_Solver
{
    // minHeap of the Board_Tile objects
    BinaryHeap<Board_Tile> tileQueue;

    // initial configuration
    std::string initConfig;

    // goal configuration
    std::string goalConfig;

    public:
        Sliding_Solver(const std::string& pInitConfig, const std::string& pGoalConfig);
        virtual ~Sliding_Solver();
        void Solve_Puzzle();
};

#endif // SLIDING_SOLVER_H
