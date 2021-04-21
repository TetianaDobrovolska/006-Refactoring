#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

class CalculatorTest : public ::testing::Test
{
  protected:
  void SetUp() {
    c = new StringCalc;
  }

  void TearDown() {
    delete c;
  }

  StringCalc *c;
};


TEST_F(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST_F(CalculatorTest, OneDigitNumbersWithDefaultSepTest) {
	int actual = c->Add("2,2");
 	ASSERT_EQ(actual, 4);
}

TEST_F(CalculatorTest, TwoDigitAndOneDigitNumbersWithDefaultSepTest) {
	int actual = c->Add("10,2");
 	ASSERT_EQ(actual, 12);
}

TEST_F(CalculatorTest, NumberWithCharSymbolTest) {
	ASSERT_THROW(c->Add("1a,2"), std::invalid_argument);
}
 
TEST_F(CalculatorTest, ZeroTest) {
	int actual = c->Add("0");
 	ASSERT_EQ(actual, 0);
}

TEST_F(CalculatorTest, OneOperandTest) {
	int actual = c->Add("1");
 	ASSERT_EQ(actual, 1);
}
TEST_F(CalculatorTest, OnlyDefaultSepTest) {
	ASSERT_THROW(c->Add(","), std::invalid_argument);
}

TEST_F(CalculatorTest, EmptyLineTest) {
	int actual = c->Add("");
 	ASSERT_EQ(actual, 0);
}

TEST_F(CalculatorTest, SampleOneNegativeOpTest) {
	ASSERT_THROW(c->Add("-1"), std::invalid_argument);
}
TEST_F(CalculatorTest, FirstNegativeOpTest) {
	ASSERT_THROW(c->Add("-1,1"), std::invalid_argument);
}

TEST_F(CalculatorTest, SecondNegativeOpTest) {
	ASSERT_THROW(c->Add("1,-1"), std::invalid_argument);
}

TEST_F(CalculatorTest, TwoNotNumbersWithDefaultSepTest) {
	ASSERT_THROW(c->Add("a,b"), std::invalid_argument);
}

TEST_F(CalculatorTest, OneNotNumberWithDefaultSepTest) {
	ASSERT_THROW(c->Add("a"), std::invalid_argument);
}

TEST_F(CalculatorTest, ThreeOpsTest) {
	int actual = c->Add("1,2,3");
 	ASSERT_EQ(actual, 6);
}

TEST_F(CalculatorTest, FourOpsTest) {
	int actual = c->Add("1,2,3,4");
 	ASSERT_EQ(actual, 10);
}

TEST_F(CalculatorTest, ExtraDefaultSeparatorTest) {
	ASSERT_THROW(c->Add("1,,2"), std::invalid_argument);
}

TEST_F(CalculatorTest, DefaultSeparatorTest) {
	int actual = c->Add("1\n2");
 	ASSERT_EQ(actual, 3);
}

TEST_F(CalculatorTest, AdditionalSeparatorTest) {
	int actual = c->Add("//;\n1;2");
 	ASSERT_EQ(actual, 3);
}

TEST_F(CalculatorTest, TwoAdditionalSeparatorsTest) {
	int actual = c->Add("//;$\n1;2$6");
 	ASSERT_EQ(actual, 9);
}

TEST_F(CalculatorTest, NotValidSeparatorTest) {
	ASSERT_THROW(c->Add("//;\n1%2"), std::invalid_argument);
}

TEST_F(CalculatorTest, NotValidSeparator2Test) {
	ASSERT_THROW(c->Add("//a\n1]2a3"), std::invalid_argument);
}

TEST_F(CalculatorTest, AdditionalAndDefaultSeparatorTest) {
	int actual = c->Add("//;\n1,2\n3;4");
 	ASSERT_EQ(actual, 10);
}

TEST_F(CalculatorTest, MaxNumberTest) {
	int actual = c->Add("1000,2");
 	ASSERT_EQ(actual, 1002);
}
TEST_F(CalculatorTest, MoreThanMaxNumberTest) {
	int actual = c->Add("1001,2");
 	ASSERT_EQ(actual, 2);
}
TEST_F(CalculatorTest, AditionalSeparatorOpenBracketTest) {
	int actual = c->Add("//[\n1[2[3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, AditionalSeparatorClose1BracketTest) {
	int actual = c->Add("//]\n1]2]3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, OpenBracketAndAdditionalSeparatorsTest) {
	int actual = c->Add("//[*\n1*2[3,4");
 	ASSERT_EQ(actual, 10);
}
TEST_F(CalculatorTest, CloseBracketAndAdditionalSeparatorsTest) {
	int actual = c->Add("//]a\n1]2a3");
 	ASSERT_EQ(actual, 6);
}

TEST_F(CalculatorTest, OneMultSeparatorTest) {
	int actual = c->Add("//[***]\n1***2***3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, OneMultSeparatorSecondTest) {
	int actual = c->Add("//[--]\n1\n2--3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, OneMultSeparatorThirdTest) {
	int actual = c->Add("//[aaa]\n1aaa2aaa3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, OneMultAndDefaultSeparatorsTest) {
	int actual = c->Add("//[&&]\n1&&2,3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, OneMultAndAdditionalSeparatorsTest) {
	int actual = c->Add("//[&&]^\n1^2&&3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, CloseBracketMultSeparatorTest) {
	int actual = c->Add("//[]]\n1]2]3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, OpenBracketMultSeparatorTest) {
	int actual = c->Add("//[[]\n1[2,3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, TwoOpenBracketsMultSeparatorTest) {
	int actual = c->Add("//[[[]\n1[[2[[3");
 	ASSERT_EQ(actual, 6);
}
TEST_F(CalculatorTest, AditionalMultAndDefaultSeparatorsTest) {
	int actual = c->Add("//a[--]\n12--3,4a5");
 	ASSERT_EQ(actual, 24);
}
TEST_F(CalculatorTest, MultAditionalMultDefaultTest) {
	int actual = c->Add("//[**]a[--]\n1**2--3,4a5");
 	ASSERT_EQ(actual, 15);
}
