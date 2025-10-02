module;

#include <string>
#include <random>

import IGenerator;

export module MaxSumGenerator;

namespace interviews {
    export class MaxSumGenerator : public IGenerator<std::string> {
    public:
        explicit MaxSumGenerator(int maxSize = 100);

        std::string generate() override;

    private:
        std::random_device rd;
        std::mt19937 mt{rd()};
        std::uniform_int_distribution<int> sizeDistribution;
    };
}

namespace interviews {
    MaxSumGenerator::MaxSumGenerator(int maxSize)
    {
        if (maxSize < 4) {
            throw std::invalid_argument("Max size must be at least 4");
        }
        sizeDistribution = std::uniform_int_distribution<int>(4, maxSize);
    }
    
    std::string MaxSumGenerator::generate() {
        std::string result;
        auto resultSize{ sizeDistribution(mt) };
        result.reserve(resultSize);
        
        std::uniform_int_distribution digitDist(0, 9);
        for (int i{ 0 }; i < resultSize; ++i) {
            result += std::to_string(digitDist(mt));
        }
        return result;
    }
}
