#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest) {
    StringCalc c;
    int actual = c.Add("2,2");
    ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, SimpleTest) {
    StringCalc c;
    int actual = c.Add("1,7");
    ASSERT_EQ(actual, 8);
}

TEST(CalculatorTest, EmptyString) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}


TEST(CalculatorTest, OneNumber) {
    StringCalc c;
    int actual = c.Add("12");
    ASSERT_EQ(actual, 12);
}

TEST(CalculatorTest, ThreeNumber) {
    StringCalc c;
    int actual = c.Add("0,1,2");
    ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, Negative) {
    StringCalc c;
    int actual = c.Add("-42");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, WrongArgument) {
    StringCalc c;
    int actual = c.Add("Arg");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, NewLineDelimiter) {
    StringCalc c;
    int actual = c.Add("1\n2");
    ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, MixedDelimiter) {
    StringCalc c;
    int actual = c.Add("1\n2,3");
    ASSERT_EQ(actual, 6);
}
