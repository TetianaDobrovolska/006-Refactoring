#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

class CalculatorTest : public ::testing::Test
{
  protected:
  void SetUp()
  {
    res = new StringCalc;
  }

  void TearDown()
  {
    delete res;
  }

  StringCalc *res;
};

TEST_F(CalculatorTest, Test1) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST_F(CalculatorTest, Test2) {
	int actual = res->Add("2,2");
	EXPECT_EQ(actual, 4);
}

TEST_F(CalculatorTest, Test3) {
	int actual = res->Add("5,2");
	EXPECT_EQ(actual, 7);
}

TEST_F(CalculatorTest, Test4) {
	int actual = res->Add("");
	EXPECT_EQ(actual, 0);
}

TEST_F(CalculatorTest, Test5) {
	int actual = res->Add("0");
	EXPECT_EQ(actual, 0);
}

TEST_F(CalculatorTest, Test6) {
	int actual = res->Add("5");
	EXPECT_EQ(actual, 5);
}

TEST_F(CalculatorTest, Test7) {
	int actual = res->Add("-3");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test8) {
	int actual = res->Add("^&*");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test9) {
	int actual = res->Add(",");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test10) {
	int actual = res->Add("5,");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test11) {
	int actual = res->Add(",9");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test12) {
	int actual = res->Add("2,4,");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test13) {
	int actual = res->Add("22,44");
	EXPECT_EQ(actual, 66);
}

TEST_F(CalculatorTest, Test14) {
	int actual = res->Add("1,20,4,1,12");
	EXPECT_EQ(actual, 38);
}

TEST_F(CalculatorTest, Test15) {
	int actual = res->Add("1,20,4,,12");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test16) {
	int actual = res->Add("1,20\\n4,12");
	EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test17) {
	int actual = res->Add("1\n5\n4\n12");
	EXPECT_EQ(actual, 22);
}

TEST_F(CalculatorTest, Test18) {
	int actual = res->Add("1\n\12");
	EXPECT_EQ(actual, -1);
}