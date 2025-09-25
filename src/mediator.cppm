export module Mediator;

#include <memory>
#include <stdexcept>
#include <string>

import SolverBase;
import GeneratorBase;

namespace interviews {
    export template<typename ArgsType, typename ReturnType>
    class Mediator {
    public:
        Mediator(GeneratorBase<ArgsType>, SolverBase<ArgsType, ReturnType>);

        void generateProblemData();
        void solveProblem();

        std::string getProblemData() const;
        std::string getSolution() const;

    private:
        GeneratorBase<ArgsType> generator;
        SolverBase<ArgsType, ReturnType> solver;

        std::variant<bool, ArgsType> problemData{ false };
        std::variant<bool, ReturnType> solution{ false };

    private:
        void assertProblemDataSet() const;
        void assertSolutionSet() const;
    };
}

namespace interviews {
    template<typename ArgsType, typename ReturnType>
    Mediator<ArgsType, ReturnType>::Mediator(GeneratorBase<ArgsType> generator, SolverBase<ArgsType, ReturnType> solver) {
        this->generator = generator;
        this->solver = solver;
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::generateProblemData() {
        problemData = generator.generate();
        solution = false;
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::solveProblem() {
        assertProblemDataSet();
        solution = solver.solve(get<ArgsType>(problemData));
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::assertProblemDataSet() const {
        if (!hold_alternative<ArgsType>(problemData)) {
            throw std::runtime_error("Problem data hasn't been generated yet.");
        }
    }

    template<typename ArgsType, typename ReturnType>
    std::string Mediator<ArgsType, ReturnType>::getProblemData() const {
        assertProblemDataSet();
        return static_cast<std::string>(get<ArgsType>(problemData));
    }

    template<typename ArgsType, typename ReturnType>
    std::string Mediator<ArgsType, ReturnType>::getSolution() const {
        assertSolutionSet();
        return static_cast<std::string>(get<ReturnType>(solution));
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::assertSolutionSet() const {
        if (!hold_alternative<ReturnType>(solution)) {
            throw std::runtime_error("Problem hasn't been solved yet.");
        }
    }
}