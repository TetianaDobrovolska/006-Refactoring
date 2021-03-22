#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, EmptyStringInputTest) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SumTest) {
    StringCalc c;
    int actual = c.Add("1,2");
    ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, ZeroOperandTest) {
    StringCalc c;
    int actual = c.Add("0");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, OneOperandTest) {
    StringCalc c;
    int actual = c.Add("1");
    ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, NegativeInputTest) {
    StringCalc c;
    int actual = c.Add("-1,8");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, MultipleOperandTest) {
    StringCalc c;
    int actual = c.Add("1,2,3,4,5");
    ASSERT_EQ(actual, 15);
}
