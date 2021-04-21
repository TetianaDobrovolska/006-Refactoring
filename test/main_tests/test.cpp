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

TEST(CalculatorTest, AddThreeANumbers) {
	StringCalc c;
	int actual = c.Add("2,4,1");
	ASSERT_EQ(actual, 7);
}

TEST(CalculatorTest, AddFiftyANumbers) {
	std::string input = "1";
	for (auto i = 2; i <= 50; ++i) {
		input = input + ',' + std::to_string(i);
	}
	StringCalc c;
	int actual = c.Add(input);
	ASSERT_EQ(actual, 1275);
}

TEST(CalculatorTest, AddWithNewLineDelimiter) {
	StringCalc c;
	int actual = c.Add("1\n2");
	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, AddWithNewLineAndComaDelimiters) {
	StringCalc c;
	int actual = c.Add("1\n2,3");
	ASSERT_EQ(actual, 6);
}

