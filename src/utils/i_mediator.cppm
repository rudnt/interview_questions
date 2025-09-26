export module IMediator;

#include <string>

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