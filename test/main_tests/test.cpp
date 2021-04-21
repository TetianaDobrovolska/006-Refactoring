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
	EXPECT_THROW(res->Add("-3"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test8) {
	EXPECT_THROW(res->Add("^&*"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test9) {
	EXPECT_THROW(res->Add(","), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test10) {
	EXPECT_THROW(res->Add("5,"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test11) {
	EXPECT_THROW(res->Add(",9"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test12) {
	EXPECT_THROW(res->Add("2,4,"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
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
	EXPECT_THROW(res->Add("1,20,4,,12"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test16) {
	EXPECT_THROW(res->Add("1,20\\n4,12"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test17) {
	int actual = res->Add("1\n5\n4\n12");
	EXPECT_EQ(actual, 22);
}

TEST_F(CalculatorTest, Test18) {
	EXPECT_THROW(res->Add("1\n\12"), std::invalid_argument);
	//EXPECT_EQ(actual, -1);
}

TEST_F(CalculatorTest, Test19) {
	int actual = res->Add("//%\n1%2,3\n4");
	EXPECT_EQ(actual, 10);
}

TEST_F(CalculatorTest, Test20) {
	int actual = res->Add("//%1%2,3\n4");
	EXPECT_EQ(actual, 4);
}

TEST_F(CalculatorTest, Test21) {
	int actual = res->Add("2222,3\n432");
	EXPECT_EQ(actual, 435);
}

TEST_F(CalculatorTest, Test22) {
	int actual = res->Add("2222,3333");
	EXPECT_EQ(actual, 0);
}

TEST_F(CalculatorTest, Test23) {
	int actual = res->Add("//%$!\n1%$!2,3\n4");
	EXPECT_EQ(actual, 10);
}