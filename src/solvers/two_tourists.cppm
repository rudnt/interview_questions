/*
Max distance between two tourists.

We have vector of elevation data and two tourists starting a journey from the same spot.
Tourists can not go downhill. Each tourist goes in opposite direction.

Find maximum distance between tourists.
*/
export module TwoTouristsSolver;

#include <vector>

import SolverBase;

namespace interviews {
    export class TwoTouristsSolver : public SolverBase<std::vector<int>, int> {
    public:
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