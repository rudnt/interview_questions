export module Mediator;

#include <memory>
#include <stdexcept>
#include <string>
#include <variant>

import IGenerator;
import IMediator;
import InvalidStateError;
import ISolver;
import ToString;

namespace interviews {
    export template<typename ArgsType, typename ReturnType>
    class Mediator: public IMediator {
    public:
        Mediator(
            std::shared_ptr<IGenerator<ArgsType>> generator,
            std::shared_ptr<ISolver<ArgsType, ReturnType>> solver
        );

        void generateProblemData() override;
        void solveProblem() override;

        std::string getProblemData() const override;
        std::string getSolution() const override;

    private:
        enum class Value { Undefined };

    private:
        std::shared_ptr<IGenerator<ArgsType>> generator;
        std::shared_ptr<ISolver<ArgsType, ReturnType>> solver;

        std::variant<Value, ArgsType> problemData{ Value::Undefined };
        std::variant<Value, ReturnType> solution{ Value::Undefined };

    private:
        void assertProblemDataSet() const;
        void assertSolutionSet() const;
    };
}

namespace interviews {
    template<typename ArgsType, typename ReturnType>
    Mediator<ArgsType, ReturnType>::Mediator(
        std::shared_ptr<IGenerator<ArgsType>> generator,
        std::shared_ptr<ISolver<ArgsType, ReturnType>> solver
    ) {
        this->generator = generator;
        this->solver = solver;
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::generateProblemData() {
        problemData = generator->generate();
        solution = Value::Undefined;
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::solveProblem() {
        assertProblemDataSet();
        solution = solver->solve(std::get<ArgsType>(problemData));
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::assertProblemDataSet() const {
        if (!std::holds_alternative<ArgsType>(problemData)) {
            throw InvalidStateError("Problem data hasn't been generated yet.");
        }
    }

    template<typename ArgsType, typename ReturnType>
    std::string Mediator<ArgsType, ReturnType>::getProblemData() const {
        assertProblemDataSet();
        return toString(std::get<ArgsType>(problemData));
    }

    template<typename ArgsType, typename ReturnType>
    std::string Mediator<ArgsType, ReturnType>::getSolution() const {
        assertSolutionSet();
        return toString(std::get<ReturnType>(solution));
    }

    template<typename ArgsType, typename ReturnType>
    void Mediator<ArgsType, ReturnType>::assertSolutionSet() const {
        if (!std::holds_alternative<ReturnType>(solution)) {
            throw InvalidStateError("Problem hasn't been solved yet.");
        }
    }
}