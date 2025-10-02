#include <gtest/gtest.h>

import TwoTouristsGenerator;

TEST(TwoTouristsGeneratorTest, Generator_DefaultInitiation_ReturnsValidArray) {
    interviews::TwoTouristsGenerator generator;
    
    for (int i{ 0 }; i < 10; ++i) {
        std::vector<int> result = generator.generate();
        EXPECT_GE(result.size(), 0);
    }
}

TEST(TwoTouristsGeneratorTest, Generator_CustomInitiation_ReturnsValidArray) {
    std::array<int, 5> sizes{ 0, 1, 10, 50, 100 };
    for (int size : sizes) {
        interviews::TwoTouristsGenerator generator(size);
        for (int i{ 0 }; i < 10; ++i) {
            std::vector<int> result = generator.generate();
            EXPECT_GE(result.size(), 0);
            EXPECT_LE(result.size(), size);
        }
    }
}

TEST(TwoTouristsGeneratorTest, Generator_InvalidMaxSize_ThrowsException) {
    EXPECT_THROW(interviews::TwoTouristsGenerator(-10), std::invalid_argument);
    EXPECT_THROW(interviews::TwoTouristsGenerator(-1), std::invalid_argument);
}
