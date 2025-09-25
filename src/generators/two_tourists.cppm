export module TwoTouristsGenerator;

#include <vector>

import GeneratorBase;

namespace interviews {
    export class TwoTouristsGenerator : public GeneratorBase<std::vector<int>> {
    public:
        std::vector<int> generate() override;
    };
}

// TODO use random number generator for this 
namespace interviews {
    std::vector<int> TwoTouristsGenerator::generate() {
        return {1, 243, 4, 543, 65, 6, 675, 342, 34};
    }
}