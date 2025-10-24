module;

#include <string>
#include <random>

import IGenerator;

export module MaxSumGenerator;

namespace interviews {
    /**
     * @brief Generator for the MaxSum problem that creates random digit strings.
     * 
     * Generates random strings of digits (0-9) that can be used as input
     * for the MaxSum problem, which involves finding the maximum sum of
     * two non-adjacent two-digit numbers.
     */
    export class MaxSumGenerator : public IGenerator<std::string> {
    public:
        /**
         * @brief Constructs a MaxSumGenerator with configurable size bounds.
         * @param maxSize Maximum length of generated digit strings (must be at least 4).
         * @throws std::invalid_argument if maxSize is less than 4.
         */
        explicit MaxSumGenerator(int maxSize = 100);

        /**
         * @brief Generates a random string of digits.
         * @return std::string A string containing random digits 0-9.
         */
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
