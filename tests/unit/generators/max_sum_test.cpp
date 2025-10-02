#include <gtest/gtest.h>

import MaxSumGenerator;

TEST(MaxSumGeneratorTest, Generator_DefaultInstantiation_GeneratesValidStrings) {
    interviews::MaxSumGenerator generator;
    
    for (size_t i{ 0 }; i < 10; ++i) {
        std::string result = generator.generate();
        EXPECT_FALSE(result.empty());
        EXPECT_GE(result.size(), 4);
        for (char c : result) {
            EXPECT_TRUE(std::isdigit(c));
        }
    }
}

TEST(MaxSumGeneratorTest, Generator_CustomInstantiation_GeneratesValidStrings) {
    std::array<int, 5> sizes{ 4, 10, 50, 100, 200 };
    for (int size : sizes) {
        interviews::MaxSumGenerator generator(size);
        for (size_t i{ 0 }; i < 10; ++i) {
            std::string result = generator.generate();
            EXPECT_FALSE(result.empty());
            EXPECT_GE(result.size(), 4);
            EXPECT_LE(result.size(), size);
            for (char c : result) {
                EXPECT_TRUE(std::isdigit(c));
            }
        }
    }
}

TEST(MaxSumGeneratorTest, Generator_InvalidMaxSize_ThrowsException) {
    EXPECT_THROW(interviews::MaxSumGenerator(3), std::invalid_argument);
    EXPECT_THROW(interviews::MaxSumGenerator(0), std::invalid_argument);
    EXPECT_THROW(interviews::MaxSumGenerator(-10), std::invalid_argument);
}
