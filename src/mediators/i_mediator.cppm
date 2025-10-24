module;

#include <string>

export module IMediator;

namespace interviews {
    /**
     * @brief Interface for coordinating problem generation and solving.
     * 
     * Mediator coordinates the interaction between generators and solvers,
     * managing the lifecycle of problem data and solutions.
     */
    export class IMediator {
    public:
        virtual ~IMediator() = default;

        /**
         * @brief Generates new problem input data.
         * 
         * Resets any existing solution state and creates fresh problem data.
         */
        virtual void generateProblemData() = 0;
        
        /**
         * @brief Solves the problem using the currently generated data.
         * @throws InvalidStateError if problem data hasn't been generated yet.
         */
        virtual void solveProblem() = 0;

        /**
         * @brief Retrieves the generated problem data as a string.
         * @return std::string String representation of the problem data.
         * @throws InvalidStateError if problem data hasn't been generated yet.
         */
        virtual std::string getProblemData() const = 0;
        
        /**
         * @brief Retrieves the computed solution as a string.
         * @return std::string String representation of the solution.
         * @throws InvalidStateError if the problem hasn't been solved yet.
         */
        virtual std::string getSolution() const = 0;
    };
}
