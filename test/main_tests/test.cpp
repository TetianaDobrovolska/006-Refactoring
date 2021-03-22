#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, TestStep1_goodInput) {
  StringCalc c;

  /// one number
  std::string input = "235";
  int actual = c.Add(input);
  int expected = 235;
  ASSERT_EQ(actual, expected);

  /// one number and comma
  input = " 235 ,		";
  actual = c.Add(input);
  ASSERT_EQ(actual, expected);

  /// one number and comma
  input = " 235 ,	1	";
  actual = c.Add(input);
  ASSERT_EQ(actual, expected + 1);
}

TEST(CalculatorTest, TestStep1_empty) {
  StringCalc c;
  const int expected = 0;

  /// empty string
  std::string input = "";
  int actual = c.Add(input);
  ASSERT_EQ(actual, expected);

  /// empty with comma
  input = "  ,		";
  actual = c.Add(input);
  ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, TestStep1_exception) {
  StringCalc c;
  const int expected = -1;

  /// conversion exception
  std::string input = "aaaa";
  int actual = c.Add(input);
  ASSERT_EQ(actual, expected);

  /// conversion exception
  input = "1sa,22";
  actual = c.Add(input);
  ASSERT_EQ(actual, expected);

  /// negative number
  input = ",	-2";
  actual = c.Add(input);
  ASSERT_EQ(actual, expected);

  /// negative number
  input = "3,-32";
  actual = c.Add(input);
  ASSERT_EQ(actual, expected);
}
