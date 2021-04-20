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

