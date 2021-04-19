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

TEST(CalculatorTest, Sample2SymbolsTest) {
	StringCalc c;
 	int actual = c.Add("10,2");
 	ASSERT_EQ(actual, 12);
}

TEST(CalculatorTest, SampleDigAndCharTest) {
	StringCalc c;
 	ASSERT_THROW(c.Add("1a,2"), std::invalid_argument);
}
 
TEST(CalculatorTest, SampleOneOp1Test) {
	StringCalc c;
 	int actual = c.Add("0");
 	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleOneOp2Test) {
	StringCalc c;
 	int actual = c.Add("1");
 	ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SampleEmptyLineTest) {
	StringCalc c;
	int actual = c.Add("");
 	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleOneNegativeOpTest) {
	StringCalc c;
 	ASSERT_THROW(c.Add("-1"), std::invalid_argument);
}
TEST(CalculatorTest, SampleFirstNegativeOpTest) {
	StringCalc c;
 	ASSERT_THROW(c.Add("-1,1"), std::invalid_argument);
}

TEST(CalculatorTest, SampleSecondNegativeOpTest) {
	StringCalc c;
 	ASSERT_THROW(c.Add("1,-1"), std::invalid_argument);
}

TEST(CalculatorTest, SampleNotNumbers1Test) {
	StringCalc c;
 	ASSERT_THROW(c.Add("a,b"), std::invalid_argument);
}

TEST(CalculatorTest, SampleNotNumbers2Test) {
	StringCalc c;
 	ASSERT_THROW(c.Add("a"), std::invalid_argument);
}

TEST(CalculatorTest, SampleThreeOpsTest) {
	StringCalc c;
 	int actual = c.Add("1,2,3");
 	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, Sample4OpsTest) {
	StringCalc c;
 	int actual = c.Add("1,2,3,4");
 	ASSERT_EQ(actual, 10);
}

TEST(CalculatorTest, SampleAdditionalSeparator1Test) {
	StringCalc c;
 	ASSERT_THROW(c.Add("1,,2"), std::invalid_argument);
}

TEST(CalculatorTest, SampleAdditionalSeparatorTest) {
	StringCalc c;
 	int actual = c.Add("1\n2");
 	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, SampleAdditionalSeparator2Test) {
	StringCalc c;
 	int actual = c.Add("//;\n1;2");
 	ASSERT_EQ(actual, 3);
}
TEST(CalculatorTest, SampleNotValidSeparatorTest) {
	StringCalc c;
 	ASSERT_THROW(c.Add("//;\n1%2"), std::invalid_argument);
}

TEST(CalculatorTest, SampleValidSeparatorTest) {
	StringCalc c;
 	int actual = c.Add("//;\n1,2\n3;4");
 	ASSERT_EQ(actual, 10);
}