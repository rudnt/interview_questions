module;

#include <vector>
#include <limits>
#include <random>

import IGenerator;

export module TwoTouristsGenerator;

namespace interviews {
    export class TwoTouristsGenerator : public IGenerator<std::vector<int>> {
    public:
        explicit TwoTouristsGenerator(int maxSize = 100);

        std::vector<int> generate() override;

    private:
        std::random_device rd;
        std::mt19937 mt{rd()};
        std::uniform_int_distribution<int> sizeDistribution;
    };
}

namespace interviews {
    TwoTouristsGenerator::TwoTouristsGenerator(int maxSize)
    {
        if (maxSize < 0) {
            throw std::invalid_argument("Max size must be a positive number");
        }
        sizeDistribution = std::uniform_int_distribution<int>(0, maxSize);
    }

    std::vector<int> TwoTouristsGenerator::generate() {
        std::vector<int> result;
        auto resultSize{ sizeDistribution(mt) };
        result.reserve(resultSize);

        std::uniform_int_distribution numbersDist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        for (int i{ 0 }; i < resultSize; ++i) {
            result.push_back(numbersDist(mt));
        }
        return result;
    }
}
