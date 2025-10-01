#include <gtest/gtest.h>

import ToString;

TEST(ToStringTest, IntToString) {
    EXPECT_EQ(interviews::toString(42), "42");
}