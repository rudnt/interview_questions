#include <gtest/gtest.h>

import TwoTouristsSolver;

TEST(TwoTouristsSolverTest, Solve_ValidPositiveInput_ReturnsMaxDistance) {
    interviews::TwoTouristsSolver solver;
    EXPECT_EQ(solver.solve({0, 0, 0, 0, 0}), 4);
    EXPECT_EQ(solver.solve({1, 1, 1, 1, 1}), 4);
    EXPECT_EQ(solver.solve({1, 2, 3, 4, 5}), 4);
    EXPECT_EQ(solver.solve({5, 4, 3, 2, 1}), 4);
    EXPECT_EQ(solver.solve({1, 3, 3, 3, 1}), 3);
    EXPECT_EQ(solver.solve({5, 4, 5, 5, 5, 5, 5, 5, 3, 2, 1}), 8);
    EXPECT_EQ(solver.solve({6, 6, 6, 4, 3, 5, 5, 5, 3}), 7);
    EXPECT_EQ(solver.solve({2, 3, 5, 1, 4, 5}), 3);
    EXPECT_EQ(solver.solve({1, 3, 1, 3, 1, 3}), 2);
}

TEST(TwoTouristsSolverTest, Solve_ValidNegativeInput_ReturnsMaxDistance) {
    interviews::TwoTouristsSolver solver;
    EXPECT_EQ(solver.solve({-1, -1, -1, -1, -1}), 4);
    EXPECT_EQ(solver.solve({-1, -2, -3, -4, -5}), 4);
    EXPECT_EQ(solver.solve({-5, -4, -3, -2, -1}), 4);
    EXPECT_EQ(solver.solve({-4, -3, -3, -3, -5}), 3);
    EXPECT_EQ(solver.solve({-5, -4, -5, -5, -5, -5, -5, -5, -3, -2, -1}), 9);
    EXPECT_EQ(solver.solve({-6, -6, -6, -9, -8, -5, -5, -5, -13}), 7);
    EXPECT_EQ(solver.solve({-2, -3, -5, -1, -4, -5}), 3);
    EXPECT_EQ(solver.solve({-1, -3, -1, -3, -1, -3}), 2);
}

TEST(TwoTouristsSolverTest, Solve_ValidMixedInput_ReturnsMaxDistance) {
    interviews::TwoTouristsSolver solver;
    EXPECT_EQ(solver.solve({-1, -1, -1, -1, -1}), 4);
    EXPECT_EQ(solver.solve({1, 0, -1, -4, -5}), 4);
    EXPECT_EQ(solver.solve({-5, -4, 1, 2, 5}), 4);
    EXPECT_EQ(solver.solve({-4, 3, 3, 3, -5}), 3);
    EXPECT_EQ(solver.solve({-5, -4, -5, -5, -5, -5, -5, -5, 3, 7, 11}), 9);
    EXPECT_EQ(solver.solve({-6, -6, -6, -9, 2, 5, 5, 5, -13}), 7);
    EXPECT_EQ(solver.solve({-2, -3, -5, 1, 0, -5}), 3);
    EXPECT_EQ(solver.solve({-1, -3, 1, 0, 11, -3}), 2);
}

TEST(TwoTouristsSolverTest, Solve_EmptyArray_ReturnsZero) {
    interviews::TwoTouristsSolver solver;
    EXPECT_EQ(solver.solve({}), 0);
}

TEST(TwoTouristsSolverTest, Solve_SingleElementArray_ReturnsZero) {
    interviews::TwoTouristsSolver solver;
    EXPECT_EQ(solver.solve({10}), 0);
    EXPECT_EQ(solver.solve({-5}), 0);
    EXPECT_EQ(solver.solve({0}), 0);
}

TEST(TwoTouristsSolverTest, Solve_TwoElementArray_ReturnsOne) {
    interviews::TwoTouristsSolver solver;
    EXPECT_EQ(solver.solve({10, 20}), 1);
    EXPECT_EQ(solver.solve({-5, -10}), 1);
    EXPECT_EQ(solver.solve({0, 0}), 1);
}
