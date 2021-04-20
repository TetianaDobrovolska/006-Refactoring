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

TEST(CalculatorTest, EmptyTest) {
  StringCalc c;
  int actual = c.Add("");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, OneDigit) {
  StringCalc c;
  int actual = c.Add("1");
  ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, TwoDigits) {
  StringCalc c;
  int actual = c.Add("1,2");
  ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, OnlyPositive) {
  StringCalc c;
  int actual = c.Add("-1");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, OnlyPositive2) {
  StringCalc c;
  int actual = c.Add("1,-2");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, OnlyDigits) {
  StringCalc c;
  int actual = c.Add("a");
  ASSERT_EQ(actual, -1);
}
