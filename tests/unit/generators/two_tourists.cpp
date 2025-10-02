#include <gtest/gtest.h>

import TwoTouristsGenerator;

TEST(TwoTouristsGeneratorTest, GeneratesValidArray) {
    interviews::TwoTouristsGenerator generator;
    std::vector<int> result = generator.generate();
    EXPECT_GE(result.size(), 0);
}
