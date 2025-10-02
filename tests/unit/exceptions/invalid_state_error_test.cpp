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
    std::string msg{ "Catch me if you can" };
    try {
        throw interviews::InvalidStateError(msg);
    } catch (const std::exception& ex) {
        EXPECT_STREQ(ex.what(), msg.c_str());
    } catch (...) {
        FAIL() << "Should have been caught as std::exception";
    }
}

TEST(InvalidStateErrorTest, CanBeCaughtAsStdLogicError) {
    std::string msg{ "Catch me if you can" };
    try {
        throw interviews::InvalidStateError(msg);
    } catch (const std::logic_error& ex) {
        EXPECT_STREQ(ex.what(), msg.c_str());
    } catch (...) {
        FAIL() << "Should have been caught as std::exception";
    }
}
