#include "Sliding_Solver.h"

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
        // if not the same, get the nextconfigs of the initial board
        // and insert them into the heap
        for (Board_Tile nextBoard : initBoard.nextConfigs())
        {
            nextBoard.Manhattan_Distance(goalBoard);
            tileQueue.insert(nextBoard);
        }

        // keep looking at the findMin() from the heap until the findMin().getConfig == goalBoard.getConfig
        int counter = 1, limit = 99999;
        while( (tileQueue.findMin().getConfig() != goalBoard.getConfig()) && (counter < limit) )
        {
            // get the minimum board from the heap as determined by DC = AC + EC
            Board_Tile minBoard = tileQueue.findMin();
            tileQueue.deleteMin();
            //tileQueue.makeEmpty();

            for (Board_Tile nextBoard : minBoard.nextConfigs())
            {
                nextBoard.Manhattan_Distance(goalBoard);
                //std::cout << counter << ": " << nextBoard.getConfig() << " " << nextBoard.getDC() << " " << nextBoard.getMovesFromStart() << std::endl;
                tileQueue.insert(nextBoard);
                ++counter;
            }
        }

        // endless loop means no solution
        if (counter >= limit) {
            finalBoard = Board_Tile("");
        } else {
            finalBoard = tileQueue.findMin();
        }

        tileQueue.makeEmpty();
    }

    // print result
    std::cout << "\n\n";
    std::cout << std::left << std::setw(20) << "Start Board"
                           << std::setw(20) << "Goal Board"
                           << std::setw(20) << "Number of Moves"
                           << std::setw(20) << "Solution"
                           << std::setw(20) << std::endl;
    std::cout << std::left << std::setw(20) << initBoard.getConfig()
                           << std::setw(20) << goalBoard.getConfig()
                           << std::setw(20) << finalBoard.numMoves()
                           << std::setw(20);

    if (finalBoard.getConfig() == initBoard.getConfig()) {
        std::cout << "Same boards";
        std::cout << std::setw(20) << std::endl;
        return;
    }
    if (finalBoard.getConfig().length() != 0)
        std::cout << finalBoard.getMovesFromStart();
    else
        std::cout << "No solution";
    std::cout << std::setw(20) << std::endl;
}



bool Sliding_Solver::validateConfig(const std::string& config)
{
    // check if the string is exactly 8 characters long
    if (config.length() != 9) {
        std::cout << "Should be exactly 9 characters long." << std::endl;
        return false;
    }


    // check if every character is valid
    // valid charactes 1,2,3,4,5,6,7,8,0

    // check if it contains a 0 or if
    // there's a invalid character
    bool proceed = false;
    for (char c : config) {
        if (c == '0') {
            proceed = true;
        }
        int f = c - '0';
        if ( !isdigit(c) || f > 8 ) {
            std::cout << "There's an invalid character." << std::endl;
            return false;
        }
    }

    if (!proceed) {
        std::cout << "No '0' found." << std::endl;
        return false;
    }


    // check for duplicates
    std::stack<char> tempStack;
    for (char c : config)
        tempStack.push(c);

    while(!tempStack.empty())
    {
        char t = tempStack.top();
        int counter = 0;

        for (char c : config)
        {
            if (c == t)
                counter++;
        }

        if (counter != 1) {
            std::cout << "There's a duplicate character." << std::endl;
            return false;
        }

        tempStack.pop();
    }

    return true;
}



























