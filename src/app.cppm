export module App;

#include <iostream>
#include <memory>

import TwoTouristsSolver;
import TwoTouristsGenerator;
import MaxSumSolver;
import MaxSumGenerator;
import Mediator;

namespace interviews {
    export class App {
    public:
        void run();
    };
}

namespace interviews {
    void App::run() {
        auto solver{ std::make_shared<TwoTouristsSolver>() };
        auto generator{ std::make_shared<TwoTouristsGenerator>() };
        Mediator<std::vector<int>, int> mediator(generator, solver);
        mediator.generateProblemData();
        mediator.solveProblem();
        std::cout << "Max distance: " << mediator.getSolution() << std::endl;

        auto solver2{ std::make_shared<MaxSumSolver>() };
        auto generator2{ std::make_shared<MaxSumGenerator>() };
        Mediator<std::string, int> mediator2(generator2, solver2);
        mediator2.generateProblemData();
        mediator2.solveProblem();
        std::cout << "Max sum: " << mediator2.getSolution() << std::endl;
    }
}