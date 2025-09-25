export module MaxSumGenerator;

#include <string>

import GeneratorBase;

namespace interviews {
    export class MaxSumGenerator : public GeneratorBase<std::string> {
    public:
        std::string generate() override;
    };
}

//TODO use random to generate data
namespace interviews {
    std::string MaxSumGenerator::generate() {
        return "2134143";
    }
}