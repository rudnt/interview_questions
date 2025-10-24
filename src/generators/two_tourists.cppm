module;

#include <vector>
#include <limits>
#include <random>

import IGenerator;

export module TwoTouristsGenerator;

namespace interviews {
    /**
     * @brief Generator for the TwoTourists problem that creates random elevation sequences.
     * 
     * Generates random vectors of integers representing elevation data for the
     * TwoTourists problem, which involves finding the maximum distance tourists
     * can travel while maintaining specific elevation constraints.
     */
    export class TwoTouristsGenerator : public IGenerator<std::vector<int>> {
    public:
        /**
         * @brief Constructs a TwoTouristsGenerator with configurable size bounds.
         * @param maxSize Maximum number of elevation points to generate.
         * @throws std::invalid_argument if maxSize is negative.
         */
        explicit TwoTouristsGenerator(int maxSize = 100);

        /**
         * @brief Generates a random sequence of elevation values.
         * @return std::vector<int> A vector of random integer elevations.
         */
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
