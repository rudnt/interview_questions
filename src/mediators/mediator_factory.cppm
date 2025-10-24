module;

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

import IMediator;
import MaxSumGenerator;
import MaxSumSolver;
import Mediator;
import NotImplementedError;
import ProblemName;
import TwoTouristsSolver;
import TwoTouristsGenerator;

export module MediatorFactory;

namespace interviews {
    /**
     * @brief Factory for creating mediator instances for different interview problems.
     * 
     * Provides a centralized way to create properly configured mediators with
     * appropriate generators and solvers for each problem type.
     */
    export class MediatorFactory {
    public:
        /**
         * @brief Creates a mediator for the specified problem.
         * @param name The type of problem to create a mediator for.
         * @return std::unique_ptr<IMediator> A configured mediator instance.
         * @throws NotImplementedError if the problem type is not supported.
         */
        std::unique_ptr<IMediator> get(ProblemName);
    };
}

namespace interviews {
    std::unique_ptr<IMediator> MediatorFactory::get(ProblemName name) {
        switch (name) {
        case ProblemName::MaxSum: {
            auto generator = std::make_shared<MaxSumGenerator>();
            auto solver = std::make_shared<MaxSumSolver>();
            return std::make_unique<Mediator<std::string, int>>(generator, solver);
        }
        case ProblemName::TwoTourists: {
            auto generator = std::make_shared<TwoTouristsGenerator>();
            auto solver = std::make_shared<TwoTouristsSolver>();
            return std::make_unique<Mediator<std::vector<int>, int>>(generator, solver);
        }
        default:
            throw NotImplementedError("I believe that this problem hasn't been solved yet.");
        }
    }
}
