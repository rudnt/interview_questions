module;

#include <vector>

import ISolver;

export module TwoTouristsSolver;

namespace interviews {
    /**
     * @brief Solver for the TwoTourists problem.
     * 
     * Calculates the maximum distance two tourists can travel together along
     * an elevation path, where they can move forward only when elevations
     * are decreasing or equal, and must stop before the next upward slope.
     */
    export class TwoTouristsSolver : public ISolver<std::vector<int>, int> {
    public:
        /**
         * @brief Solves the TwoTourists problem for the given elevation sequence.
         * @param elevations Vector of elevation values representing the path.
         * @return int The maximum distance (number of indices) the tourists can travel.
         */
        int solve(const std::vector<int>&) override;

    private:
        size_t moveLeft(const std::vector<int>&, size_t);
        size_t moveRight(const std::vector<int>&, size_t);
    };
}

namespace interviews {
    int TwoTouristsSolver::solve(const std::vector<int>& elevations) {
        size_t left{ 0 };
        size_t right{ 0 };
        int maxDistance{ 0 };
        while (right + 1 < elevations.size()) {
            left = moveLeft(elevations, right);
            right = moveRight(elevations, right);
            maxDistance = std::max(maxDistance, static_cast<int>(right - left));
        }
        return maxDistance;
    }

    size_t TwoTouristsSolver::moveLeft(const std::vector<int>& elevations, size_t pos) {
        while (pos > 0 && elevations[pos - 1] == elevations[pos]) {
            --pos;
        }
        return pos;
    }

    size_t TwoTouristsSolver::moveRight(const std::vector<int>& elevations, size_t pos) {
        while (pos + 1 < elevations.size() && elevations[pos + 1] < elevations[pos]) {
            ++pos;
        }
        while (pos + 1 < elevations.size() && elevations[pos + 1] >= elevations[pos]) {
            ++pos;
        }
        return pos;
    }
}
