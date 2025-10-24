module;

#include <memory>
#include <stdexcept>
#include <string>
#include <variant>

import IGenerator;
import IMediator;
import InvalidStateError;
import ISolver;
import ToString;

export module Mediator;

namespace interviews {
    /**
     * @brief Concrete implementation of IMediator for coordinating problem solving.
     * 
     * Manages the lifecycle of problem data and solutions, coordinating between
     * a generator and a solver. Ensures proper state management and validates
     * that operations occur in the correct order.
     * 
     * @tparam ArgsType The type of problem input data.
     * @tparam ReturnType The type of the solution result.
     */
    export template<typename ArgsType, typename ReturnType>
    class Mediator: public IMediator {
    public:
        /**
         * @brief Constructs a Mediator with a generator and solver.
         * @param generator Shared pointer to the problem data generator.
         * @param solver Shared pointer to the problem solver.
         * @throws std::invalid_argument if generator or solver is nullptr.
         */
        Mediator(
            std::shared_ptr<IGenerator<ArgsType>> generator,
            std::shared_ptr<ISolver<ArgsType, ReturnType>> solver
        );

        /**
         * @brief Generates new problem input data.
         * 
         * Resets any existing solution state and creates fresh problem data.
         */
        void generateProblemData() override;
        
        /**
         * @brief Solves the problem using the currently generated data.
         * @throws InvalidStateError if problem data hasn't been generated yet.
         */
        void solveProblem() override;

        /**
         * @brief Retrieves the generated problem data as a string.
         * @return std::string String representation of the problem data.
         * @throws InvalidStateError if problem data hasn't been generated yet.
         */
        std::string getProblemData() const override;
        
        /**
         * @brief Retrieves the computed solution as a string.
         * @return std::string String representation of the solution.
         * @throws InvalidStateError if the problem hasn't been solved yet.
         */
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
        if (!generator || !solver) {
            throw std::invalid_argument("Generator and solver must not be nullptr.");
        }

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
