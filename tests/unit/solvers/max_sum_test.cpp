#include <gtest/gtest.h>

import MaxSumSolver;

TEST(MaxSumSolverTest, Solve_ValidInput_ReturnsMaxSum) {
    interviews::MaxSumSolver solver;
    EXPECT_EQ(solver.solve("123456"), 56 + 34);
    EXPECT_EQ(solver.solve("9854321076"), 98 + 76);
    EXPECT_EQ(solver.solve("22111222333"), 33 + 23);
    EXPECT_EQ(solver.solve("000123456789"), 89 + 67);
    EXPECT_EQ(solver.solve("1899811"), 89 + 98);
    EXPECT_EQ(solver.solve("898898"), 98 + 98);
}

TEST(MaxSumSolverTest, Solve_InsufficientDigits_ThrowsException) {
    interviews::MaxSumSolver solver;
    EXPECT_THROW(solver.solve("123"), std::invalid_argument);
    EXPECT_THROW(solver.solve("1"), std::invalid_argument);
    EXPECT_THROW(solver.solve(""), std::invalid_argument);
}

TEST(MaxSumSolverTest, Solve_ExactFourDigits_ReturnsCorrectSum) {
    interviews::MaxSumSolver solver;
    EXPECT_EQ(solver.solve("1234"), 12 + 34);
    EXPECT_EQ(solver.solve("5678"), 56 + 78);
    EXPECT_EQ(solver.solve("9090"), 90 + 90);
    EXPECT_EQ(solver.solve("9889"), 98 + 89);
}

TEST(MaxSumSolverTest, Solve_RepeatedDigits_ReturnsCorrectSum) {
    interviews::MaxSumSolver solver;
    EXPECT_EQ(solver.solve("111111"), 11 + 11);
    EXPECT_EQ(solver.solve("2222222"), 22 + 22);
    EXPECT_EQ(solver.solve("33333333"), 33 + 33);
}

TEST(MaxSumSolverTest, Solve_RepeatedMax_ReturnsMaxSum) {
    interviews::MaxSumSolver solver;
    EXPECT_EQ(solver.solve("1199231243419923199321432"), 99 + 99);
    EXPECT_EQ(solver.solve("433211234323214232143"), 43 + 43);
}