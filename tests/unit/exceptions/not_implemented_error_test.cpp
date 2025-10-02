#include <gtest/gtest.h>

import NotImplementedError;

TEST(NotImplementedErrorTest, What_ReturnsCorrectMessage) {
    std::string msg{ "Test message" };
    interviews::NotImplementedError error(msg);
    EXPECT_STREQ(error.what(), msg.c_str());
}

TEST(NotImplementedErrorTest, InheritsFromStdException) {
    std::string msg{ "Another test message" };
    interviews::NotImplementedError error(msg);
    std::exception& ex = error;
    EXPECT_STREQ(ex.what(), msg.c_str());
}

TEST(NotImplementedErrorTest, CanBeCaughtAsStdException) {
    EXPECT_THROW({ throw interviews::NotImplementedError("msg"); }, std::exception);
}

TEST(NotImplementedErrorTest, CanBeCaughtAsStdLogicError) {
    EXPECT_THROW({ throw interviews::NotImplementedError("msg"); }, std::logic_error);
}
