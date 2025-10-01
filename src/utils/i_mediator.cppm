module;

#include <string>

export module IMediator;

namespace interviews {
    export class IMediator {
    public:
        virtual ~IMediator() = default;

        virtual void generateProblemData() = 0;
        virtual void solveProblem() = 0;

        virtual std::string getProblemData() const = 0;
        virtual std::string getSolution() const = 0;
    };
}