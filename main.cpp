#include <iostream>
#include <string>
#include "Sliding_Solver.h"
#include "BinaryHeap.h"



int main()
{
    std::string initConfig = "582041637";
    std::string goalConfig = "825041376";
    //Sliding_Solver::validateConfig(initConfig);
    //Sliding_Solver solver(initConfig, goalConfig);
    //solver.Solve_Puzzle();
    std::cout << std::boolalpha << Sliding_Solver::validateConfig("582041637");

    return 0;
}
