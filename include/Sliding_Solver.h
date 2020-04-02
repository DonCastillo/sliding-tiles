#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H
#include "BinaryHeap.h"
#include "Board_Tile.h"
#include <string>

class Sliding_Solver
{
    // minHeap of the Board_Tile objects
    BinaryHeap<Board_Tile*> tileQueue;

    // initial configuration
    std::string initialConfig;

    // goal configuration
    std::string goalConfig;

    public:
        explicit Sliding_Solver();
        virtual ~Sliding_Solver();
        void Solve_Puzzle();
};

#endif // SLIDING_SOLVER_H
