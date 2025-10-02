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
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution digit_dist(0, 9);
        
        auto resultSize{ sizeDistribution(mt) };
        std::string result;
        result.reserve(resultSize);
        for (int i{ 0 }; i < resultSize; ++i) {
            result += std::to_string(digit_dist(mt));
        }
        return result;
    }
}
