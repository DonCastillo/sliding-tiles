
/** @author Don Castillo
 *  @brief  Header of the Board_Tile class
 *  @date   06/04/2020
 *
 */

#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H
#include "BinaryHeap.h"
#include "Board_Tile.h"
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <iomanip>

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

        /** @brief  solves the puzzle using A* search
         *          prints the solution table
         */
        void Solve_Puzzle();

        /** @brief  validates string configuration
         *  @param  config  string configuration
         */
        static bool validateConfig(const std::string& config);
};

#endif // SLIDING_SOLVER_H
