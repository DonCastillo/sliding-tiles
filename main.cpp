#include <iostream>
#include <string>
#include "Sliding_Solver.h"
#include "BinaryHeap.h"

int main()
{
    std::string initConfig;
    std::string goalConfig;

    bool loop = false;

    std::cout << "SLIDING TILES by Don Castillo\nTerm Project in CPSC 3620: Data Structures and Algorithm\n\n";
    std::cout << "Enter two nine-character long string of digits (from 0 through 8)\n"
              << "representing the 3x3 row-oriented layout of the initial and goal board\n"
              << "configurations of the sliding puzzle. The '0' character represents a blank tile\n\n";

    do{
        do{
            std::cout << "Enter the start board configuration: ";
            std::getline(cin, initConfig);
        }while( !Sliding_Solver::validateConfig(initConfig) );


        do{
            std::cout << "Enter the goal board configuration: ";
            std::getline(cin, goalConfig);
        }while( !Sliding_Solver::validateConfig(goalConfig) );


        Sliding_Solver solver(initConfig, goalConfig);
        solver.Solve_Puzzle();

        string command;
        std::cout << "\n\nSolve another sliding puzzle?\n(Type 'q' to quit, any key to continue): ";
        std::getline(cin, command);
        if (command[0] != 'q')
            loop = true;
        else
            loop = false;

        std::cout << "\n\n";

    }while(loop);




    return 0;
}
