export module App;

#include <iostream>

import TwoTouristsSolver;
import TwoTouristsGenerator;
import MaxSumSolver;
import MaxSumGenerator;

namespace interviews {
    export class App {
    public:
        void run();
    };
}

namespace interviews {
    void App::run() {
        TwoTouristsSolver solver;
        TwoTouristsGenerator twoTouristsGenerator;
        std::cout << "Max distance: " << solver.solve(twoTouristsGenerator.generate()) << std::endl;

        MaxSumSolver sumSolver;
        MaxSumGenerator maxSumGenerator;
        std::cout << "Max sum: " << sumSolver.solve(maxSumGenerator.generate()) << std::endl;
    }
}