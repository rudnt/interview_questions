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
    std::string msg{ "Catch me if you can" };
    try {
        throw interviews::NotImplementedError(msg);
    } catch (const std::exception& ex) {
        EXPECT_STREQ(ex.what(), msg.c_str());
    } catch (...) {
        FAIL() << "Should have been caught as std::exception";
    }
}

TEST(NotImplementedErrorTest, CanBeCaughtAsStdLogicError) {
    std::string msg{ "Catch me if you can" };
    try {
        throw interviews::NotImplementedError(msg);
    } catch (const std::logic_error& ex) {
        EXPECT_STREQ(ex.what(), msg.c_str());
    } catch (...) {
        FAIL() << "Should have been caught as std::exception";
    }
}
