#include "Sliding_Solver.h"
#include <string>

Sliding_Solver::Sliding_Solver(const std::string& pInitConfig,
                               const std::string& pGoalConfig)
{
    initBoard = Board_Tile(pInitConfig);
    goalBoard = Board_Tile(pGoalConfig);
}

Sliding_Solver::~Sliding_Solver()
{

}

void Sliding_Solver::Solve_Puzzle()
{

    Board_Tile finalBoard;

    // if both boards are the same
    if (initBoard.getConfig() == goalBoard.getConfig())
    {
            finalBoard = initBoard;
    }
    else
    {
        /* if not the same, get the nextconfigs of the initial board
           and insert them into the heap */
        for (Board_Tile nextBoard : initBoard.nextConfigs())
        {
            nextBoard.Manhattan_Distance(goalBoard);
            tileQueue.insert(nextBoard);
        }

        /* keep looking at the findMin() from the heap until
           the findMin().getConfig == goalBoard.getConfig */
        while(tileQueue.findMin().getConfig() != goalBoard.getConfig())
        {

            /* get the minimum board from the heap as determined by
               DC = AC + EC */
            Board_Tile minBoard = tileQueue.findMin();
            tileQueue.deleteMin();

            for (Board_Tile nextBoard : minBoard.nextConfigs())
            {
                nextBoard.Manhattan_Distance(goalBoard);
                //std::cout << nextBoard.getConfig() << " " << nextBoard.getDC() << " " << nextBoard.getMovesFromStart() << std::endl;
                tileQueue.insert(nextBoard);
            }

        }

        finalBoard = tileQueue.findMin();
        tileQueue.makeEmpty();
    }

    std::cout << "-------------" << std::endl;
    std::cout << "Config:\t\t" << finalBoard.getConfig() << std::endl;
    std::cout << "Solution:\t" << finalBoard.getMovesFromStart() << std::endl;
    std::cout << "Moves:\t\t" << finalBoard.numMoves() << std::endl;
}
