#include <gtest/gtest.h>

import MaxSumGenerator;

TEST(MaxSumGeneratorTest, GeneratesValidString) {
    interviews::MaxSumGenerator generator;
    std::string result = generator.generate();

    EXPECT_FALSE(result.empty());
    EXPECT_GE(result.size(), 4);
    for (char c : result) {
        EXPECT_TRUE(std::isdigit(c));
    }
}
