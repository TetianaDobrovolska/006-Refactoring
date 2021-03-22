#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest) {
	// Arange
	StringCalc c;
	const std::string input = "2,2";

	// Act
	int actual = c.Add(input);
	
	// Assert
	const int expected = 4;
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, SampleTest2) {
	// Arange
	StringCalc c;
	const std::string input = "3,2";

	// Act
	int actual = c.Add(input);
	
	// Assert
	const int expected = 5;
	ASSERT_EQ(actual, expected);
}

