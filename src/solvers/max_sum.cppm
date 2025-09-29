export module MaxSumSolver;

#include <cstddef>
#include <ranges>
#include <string>
#include <vector>

import ISolver;

namespace interviews {
    export class MaxSumSolver : public ISolver<std::string, int> {
    public:
        int solve(const std::string&) override;
        
    private:
        std::vector<int> getAllTwoDigitNumbers(std::string_view);
        int getMaxSum(const std::vector<int>&);
    };
}

namespace interviews {
    int MaxSumSolver::solve(const std::string& digits) {
        if (digits.size() < 4) {
            throw std::invalid_argument("Need at least 4 numbers to select two non-adjacent");
        }

        auto numbers{ getAllTwoDigitNumbers(digits) };
        return getMaxSum(numbers);
    }

    std::vector<int> MaxSumSolver::getAllTwoDigitNumbers(std::string_view digits) {
        std::vector<int> numbers;
        numbers.reserve(digits.size());
        for (size_t i{ 0 }; i + 1< digits.size(); ++i) {
            auto number { digits | std::views::drop(i) | std::views::take(2) };
            numbers.push_back(std::stoi(std::string(number)));
        }
        return numbers;
    }

    int MaxSumSolver::getMaxSum(const std::vector<int>& numbers) {
        auto maxIter{ std::ranges::max_element(numbers) };
        int max{ *maxIter };

        int sumLeft{
            std::distance(numbers.begin(), maxIter) < 2 
            ? std::numeric_limits<int>::min() 
            : *std::max_element(numbers.begin(), maxIter - 1) + max
        };
        int sumRight{
            std::distance(maxIter, numbers.end()) < 3 
            ? std::numeric_limits<int>::min() 
            : *std::max_element(maxIter + 2, numbers.end()) + max
        };
        int altSum{
            maxIter == numbers.begin() || maxIter + 1 == numbers.end() 
            ? std::numeric_limits<int>::min() 
            : *(maxIter - 1) + *(maxIter + 1)
        };
        return std::max({ sumLeft, sumRight, altSum });
    }
}