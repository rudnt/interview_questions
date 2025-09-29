export module App;

#include <iostream>

import TwoTouristsSolver;
import TwoTouristsGenerator;
import MaxSumSolver;
import MaxSumGenerator;
import Mediator;
import MediatorFactory;
import ProblemName;

namespace interviews {
    export class App {
    public:
        void run();
    };
}

namespace interviews {
    void App::run() {
        auto factory { MediatorFactory() };
        std::cout << "--- Interview questions ---" << std::endl << std::endl;

        auto mediator { factory.get(ProblemName::TwoTourists) };
        mediator->generateProblemData();
        mediator->solveProblem();
        std::cout << "Problem name: TwoTourists" << std::endl;
        std::cout << "Elevations:   " << mediator->getProblemData() << std::endl;
        std::cout << "Max distance: " << mediator->getSolution() << std::endl;
        std::cout << std::endl;

        mediator = factory.get(ProblemName::MaxSum);
        mediator->generateProblemData();
        mediator->solveProblem();
        std::cout << "Problem name: MaxSum" << std::endl;
        std::cout << "Digits:       " << mediator->getProblemData() << std::endl;
        std::cout << "Max sum:      " << mediator->getSolution() << std::endl;
    }
}