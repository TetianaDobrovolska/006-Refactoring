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

TEST(CalculatorTest, SampleOneDigit) {
 	StringCalc c;
 	int actual = c.Add("1");
 	ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SampleLongOneDigit) {
 	StringCalc c;
 	int actual = c.Add("1223");
 	ASSERT_EQ(actual, 1223);
}

TEST(CalculatorTest, SampleEmptyString) {
 	StringCalc c;
 	int actual = c.Add("");
 	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleThreeDigit) {
 	StringCalc c;
 	int actual = c.Add("1,2,3");
 	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, SampleThreePlusDigit) {
 	StringCalc c;
 	int actual = c.Add("1,2,30");
 	ASSERT_EQ(actual, 33);
}