#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, Test1) {
 	StringCalc c;
 	int actual = c.Add("3,4");
 	ASSERT_EQ(actual, 7);
}

TEST(CalculatorTest, Test2) {
 	StringCalc c;
 	int actual = c.Add("");
 	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, Test3) {
 	StringCalc c;
 	int actual = c.Add("0");
 	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, Test4) {
 	StringCalc c;
 	int actual = c.Add("3,4,");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test5) {
 	StringCalc c;
 	int actual = c.Add("3,,4");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test6) {
 	StringCalc c;
 	int actual = c.Add(",3");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test7) {
 	StringCalc c;
 	int actual = c.Add(",");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test8) {
 	StringCalc c;
 	int actual = c.Add("7,");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test9) {
 	StringCalc c;
 	int actual = c.Add("34");
 	ASSERT_EQ(actual, 34);
}

TEST(CalculatorTest, Test10) {
 	StringCalc c;
 	int actual = c.Add("1,20");
 	ASSERT_EQ(actual, 21);
}

TEST(CalculatorTest, Test11) {
 	StringCalc c;
 	int actual = c.Add("17,23");
 	ASSERT_EQ(actual, 40);
}

TEST(CalculatorTest, Test12) {
 	StringCalc c;
 	int actual = c.Add("a");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test13) {
 	StringCalc c;
 	int actual = c.Add("1a");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test14) {
 	StringCalc c;
 	int actual = c.Add("5a,11");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test15) {
 	StringCalc c;
 	int actual = c.Add("12,c");
 	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, Test16) {
 	StringCalc c;
 	int actual = c.Add("9,5a");
 	ASSERT_EQ(actual, -1);
}