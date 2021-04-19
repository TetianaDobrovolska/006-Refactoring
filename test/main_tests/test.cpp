#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, EmptyString) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, LongString) {
    StringCalc c;
    int actual = c.Add("123456789");
    ASSERT_EQ(actual, 45);
}

TEST(CalculatorTest, SampleTest) {
    StringCalc c;
    int actual = c.Add("2,2");
    ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, NegativeValue) {
    StringCalc c;
    int actual = c.Add("-2,1");
    ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, ZeroValue) {
    StringCalc c;
    int actual = c.Add("0");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, NewLineString) {
    StringCalc c;
    int actual = c.Add("3\n,2,2");
    ASSERT_EQ(actual, 7);
}
