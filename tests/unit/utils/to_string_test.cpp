#include <string>

#include <gtest/gtest.h>

import ToString;

using namespace std::string_literals;

TEST(ToStringTest, IntToString) {
    EXPECT_EQ(interviews::toString(0), "0");
    EXPECT_EQ(interviews::toString(42), "42");
    EXPECT_EQ(interviews::toString(231243), "231243");
    EXPECT_EQ(interviews::toString(-5), "-5");
    EXPECT_EQ(interviews::toString(-3421), "-3421");
}

TEST(ToStringTest, DoubleToString) {
    EXPECT_EQ(interviews::toString(0.0), "0.000000");
    EXPECT_EQ(interviews::toString(42.0), "42.000000");
    EXPECT_EQ(interviews::toString(231243.123), "231243.123000");
    EXPECT_EQ(interviews::toString(-5.5), "-5.500000");
    EXPECT_EQ(interviews::toString(-3421.9876), "-3421.987600");
}

TEST(ToStringTest, StringToString) {
    EXPECT_EQ(interviews::toString(""s), "");
    EXPECT_EQ(interviews::toString("Hello"s), "Hello");
    EXPECT_EQ(interviews::toString("Test String 123!"s), "Test String 123!");
    EXPECT_EQ(interviews::toString("Test String .223!"s), "Test String .223!");
}

TEST(ToStringTest, CharPointerToString) {
    const char* empty = "";
    const char* hello = "Hello";
    const char* test1 = "Test String 123!";
    const char* test2 = "Test String .223!";
    
    EXPECT_EQ(interviews::toString(empty), "");
    EXPECT_EQ(interviews::toString(hello), "Hello");
    EXPECT_EQ(interviews::toString(test1), "Test String 123!");
    EXPECT_EQ(interviews::toString(test2), "Test String .223!");
}

TEST(ToStringTest, BoolToString) {
    EXPECT_EQ(interviews::toString(true), "true");
    EXPECT_EQ(interviews::toString(false), "false");
}

TEST(ToStringTest, CharToString) {
    EXPECT_EQ(interviews::toString('a'), "a");
    EXPECT_EQ(interviews::toString('Z'), "Z");
    EXPECT_EQ(interviews::toString('1'), "1");
    EXPECT_EQ(interviews::toString('@'), "@");
    EXPECT_EQ(interviews::toString(' '), " ");
}

TEST(ToStringTest, IntsVectorToString) {
    EXPECT_EQ(interviews::toString(std::vector<int>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<int>{1, 2, 3}), "[1, 2, 3]");
    EXPECT_EQ(interviews::toString(std::vector<int>{-1, 0, 1}), "[-1, 0, 1]");
    EXPECT_EQ(interviews::toString(std::vector<int>{42}), "[42]");
}

TEST(ToStringTest, DoublesVectorToString) {
    EXPECT_EQ(interviews::toString(std::vector<double>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<double>{1.1, 2.2, 3.3}), "[1.100000, 2.200000, 3.300000]");
    EXPECT_EQ(interviews::toString(std::vector<double>{-1.5, 0.0, 1.5}), "[-1.500000, 0.000000, 1.500000]");
    EXPECT_EQ(interviews::toString(std::vector<double>{42.42}), "[42.420000]");
}

TEST(ToStringTest, StringsVectorToString) {
    EXPECT_EQ(interviews::toString(std::vector<std::string>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<std::string>{"Hello", "World"}), R"([Hello, World])");
    EXPECT_EQ(interviews::toString(std::vector<std::string>{"Test", "String", "123!"}), R"([Test, String, 123!])");
    EXPECT_EQ(interviews::toString(std::vector<std::string>{"Single"}), R"([Single])");
}

TEST(ToStringTest, BoolsVectorToString) {
    EXPECT_EQ(interviews::toString(std::vector<bool>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<bool>{true, false, true}), "[true, false, true]");
    EXPECT_EQ(interviews::toString(std::vector<bool>{false, false, false}), "[false, false, false]");
    EXPECT_EQ(interviews::toString(std::vector<bool>{true}), "[true]");
}

TEST(ToStringTest, CharsVectorToString) {
    EXPECT_EQ(interviews::toString(std::vector<char>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<char>{'a', 'b', 'c'}), "[a, b, c]");
    EXPECT_EQ(interviews::toString(std::vector<char>{'X', 'Y', 'Z'}), "[X, Y, Z]");
    EXPECT_EQ(interviews::toString(std::vector<char>{'1'}), "[1]");
}

TEST(ToStringTest, NestedIntsVectorsToString) {
    EXPECT_EQ(interviews::toString(std::vector<std::vector<int>>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<int>>{{1, 2}, {3, 4}}), "[[1, 2], [3, 4]]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<int>>{{-1, 0}, {0, 1}}), "[[-1, 0], [0, 1]]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<int>>{{42}}), "[[42]]");
}

TEST(ToStringTest, NestedDoublesVectorsToString) {
    EXPECT_EQ(interviews::toString(std::vector<std::vector<double>>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<double>>{{42.}}), "[[42.000000]]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<double>>{{1, 2}, {3, 4}}), "[[1.000000, 2.000000], [3.000000, 4.000000]]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<double>>{{-1, 0}, {0, 1}}), "[[-1.000000, 0.000000], [0.000000, 1.000000]]");
}

TEST(ToStringTest, NestedStringsVectorsToString) {
    EXPECT_EQ(interviews::toString(std::vector<std::vector<std::string>>{}), "[]");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<std::string>>{{"Hello", "World"}, {"Test", "String"}}), R"([[Hello, World], [Test, String]])");
    EXPECT_EQ(interviews::toString(std::vector<std::vector<std::string>>{{"Single"}}), R"([[Single]])");
}
