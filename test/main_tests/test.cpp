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
 	EXPECT_EQ(actual, 4);
}

TEST(CalculatorTest, SampleOneDigit) {
 	StringCalc c;
 	int actual = c.Add("1");
 	ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SampleLongOneDigit) {
 	StringCalc c;
 	int actual = c.Add("1223");
 	ASSERT_EQ(actual, 1223);
}

TEST(CalculatorTest, SampleEmptyString) {
 	StringCalc c;
 	int actual = c.Add("");
 	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleThreeDigit) {
 	StringCalc c;
 	int actual = c.Add("1,2,3");
 	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, SampleThreePlusDigit) {
 	StringCalc c;
 	int actual = c.Add("1,2,30");
 	ASSERT_EQ(actual, 33);
}

TEST(CalculatorTest, SampleSlashDelimeter) {
 	StringCalc c;
 	int actual = c.Add("1\n2");
 	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, SampleSlashAndStandartDelimeters) {
 	StringCalc c;
 	int actual = c.Add("1\n2,3");
 	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, SampleAdditionalSeparator) {
	StringCalc c;
 	int actual = c.Add("//;\n1;2\n3");
 	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, SampleInvalid) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("1\nb,a"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidSecond) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("b"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidThird) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("1, 2,,,"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidFourth) {
 	StringCalc c;
 	ASSERT_THROW(c.Add(",,,"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidFifth) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("%%%"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidSixth) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("|"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidSeventh) {
 	StringCalc c;
 	ASSERT_THROW(c.Add(","), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidEighth) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("1,2,3,<<<<"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidNinth) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("1,"), std::invalid_argument);
}

TEST(CalculatorTest, SampleInvalidTenth) {
 	StringCalc c;
 	ASSERT_THROW(c.Add("1,2..."), std::invalid_argument);
}