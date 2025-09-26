export module MaxSumGenerator;

#include <string>

import IGenerator;

namespace interviews {
    export class MaxSumGenerator : public IGenerator<std::string> {
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