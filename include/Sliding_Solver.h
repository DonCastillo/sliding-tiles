
/** @author Don Castillo
 *  @brief  Header of the Board_Tile class
 *
 */

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
    Board_Tile initBoard;

    // goal configuration
    Board_Tile goalBoard;

    public:
        /** @brief  constructor of Sliding_Solver object
         *  @param  pInitConfig initial configuration
         *          pGoalConfig goal configuration
         */
        Sliding_Solver(const std::string& pInitConfig,
                       const std::string& pGoalConfig);
        virtual ~Sliding_Solver();
        void Solve_Puzzle();
};

#endif // SLIDING_SOLVER_H
