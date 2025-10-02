#include <gtest/gtest.h>

import InvalidStateError;

TEST(InvalidStateErrorTest, What_ReturnsCorrectMessage) {
    std::string msg{ "Test message" };
    interviews::InvalidStateError error(msg);
    EXPECT_STREQ(error.what(), msg.c_str());
}

TEST(InvalidStateErrorTest, InheritsFromStdException) {
    std::string msg{ "Another test message" };
    interviews::InvalidStateError error(msg);
    std::exception& ex = error;
    EXPECT_STREQ(ex.what(), msg.c_str());
}

TEST(InvalidStateErrorTest, CanBeCaughtAsStdException) {
    EXPECT_THROW({ throw interviews::InvalidStateError("msg"); }, std::exception);
}

TEST(InvalidStateErrorTest, CanBeCaughtAsStdLogicError) {
    EXPECT_THROW({ throw interviews::InvalidStateError("msg"); }, std::logic_error);
}
