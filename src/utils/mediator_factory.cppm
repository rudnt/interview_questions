export module MediatorFactory;

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

namespace interviews {
    export class MediatorFactory {
    public:
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