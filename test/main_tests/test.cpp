#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, AddZeroNumbers) {
  StringCalc c;
  int actual = c.Add("");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, AddOneNumber) {
	StringCalc c;
	int actual = c.Add("1");
	ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, AddTwoNumbers) {
	StringCalc c;
	int actual = c.Add("1,2");
	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, AddNegativeNumber) {
	StringCalc c;
	int actual = c.Add("-666");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, AddNotANumber) {
	StringCalc c;
	int actual = c.Add("k");
	ASSERT_EQ(actual, -1);
}

