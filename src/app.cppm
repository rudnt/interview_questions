export module App;

#include <iostream>

import TwoTourists;
import TwoTouristsGenerator;
import MaxSum;
import MaxSumGenerator;

namespace interviews {
    export class App {
    public:
        void run();
    };
}

namespace interviews {
    void App::run() {
        TwoTourists solver;
        TwoTouristsGenerator twoTouristsGenerator;
        std::cout << "Max distance: " << solver.solve(twoTouristsGenerator.generate()) << std::endl;

        MaxSum sumSolver;
        MaxSumGenerator maxSumGenerator;
        std::cout << "Max sum: " << sumSolver.solve(maxSumGenerator.generate()) << std::endl;
    }
}