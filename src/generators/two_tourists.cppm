module;

#include <vector>

import IGenerator;

export module TwoTouristsGenerator;

namespace interviews {
    export class TwoTouristsGenerator : public IGenerator<std::vector<int>> {
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
