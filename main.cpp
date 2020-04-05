#include <iostream>
#include <string>
#include "Sliding_Solver.h"
#include "BinaryHeap.h"

int main()
{
    std::string initConfig;
    std::string goalConfig;

    bool loop = false;

    do{
        do{
            std::cout << "Enter a 3x3 start board configuration: ";
            std::getline(cin, initConfig);
        }while( !Sliding_Solver::validateConfig(initConfig) );


        do{
            std::cout << "Enter a 3x3 goal board configuration: ";
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
