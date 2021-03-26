#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest) {
    StringCalc c;
    const int actual = c.Add("2,2");
    const int expected = 4;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, SimpleTest) {
    StringCalc c;
    const int actual = c.Add("1,7");
    const int expected = 8;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, EmptyString) {
    StringCalc c;
    const int actual = c.Add("");
    const int expected = 0;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, OneNumber) {
    StringCalc c;
    const int actual = c.Add("12");
    const int expected = 12;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, ThreeNumber) {
    StringCalc c;
    const int actual = c.Add("0,1,2");
    const int expected = 3;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, Negative) {
    StringCalc c;
    EXPECT_THROW(c.Add("-42"), std::invalid_argument);
}

TEST(CalculatorTest, WrongArgument) {
    StringCalc c;
    EXPECT_THROW(c.Add("Arg"), std::invalid_argument);
}

TEST(CalculatorTest, NewLineDelimiter) {
    StringCalc c;
    const int actual = c.Add("1\n2");
    const int expected = 3;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, MixedDelimiter) {
    StringCalc c;
    const int actual = c.Add("1\n2,3");
    const int expected = 6;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, UndefinedDelimiter) {
    StringCalc c;
    EXPECT_THROW(c.Add("67?89"), std::invalid_argument);
}

TEST(CalculatorTest, DotInArgument) {
    StringCalc c;
    EXPECT_THROW(c.Add("45.123"), std::invalid_argument);
}

TEST(CalculatorTest, CustomDelimiter) {
    StringCalc c;
    const int actual = c.Add("//;\n1;2");
    const int expected = 3;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, CustomDelimiter2) {
    StringCalc c;
    EXPECT_THROW(c.Add("//§\n6;9"), std::invalid_argument);
}

TEST(CalculatorTest, CustomDelimiter3) {
    StringCalc c;
    const int actual = c.Add("//$\n25,6$34");
    const int expected = 65;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, CustomDelimiter4) {
    StringCalc c;
    const int actual = c.Add("//S\n5,68S3\n12");
    const int expected = 88;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, CustomDelimiter5) {
    StringCalc c;
    const int actual = c.Add("//*%\n1%2*2");
    const int expected = 5;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, InvalidCustomDelimiterDefinition) {
    StringCalc c;
    EXPECT_THROW(c.Add("//;1;2"), std::invalid_argument);
}

TEST(CalculatorTest, Valid1000Value) {
    StringCalc c;
    const int actual = c.Add("//.\n1000.662");
    const int expected = 1662;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, InvalidMore1000Value) {
    StringCalc c;
    const int actual = c.Add("//q\n1001q7");
    const int expected = 7;
    ASSERT_EQ(actual, expected);
}

TEST(CalculatorTest, FewSymbolsDelimiter) {
    StringCalc c;
    const int actual = c.Add("//[***]\n1***2***3");
    const int expected = 6;
    ASSERT_EQ(actual, expected);
}


TEST(CalculatorTest, FewSymbolsDelimiter2) {
    StringCalc c;
    const int actual = c.Add("//[bwt]\n12bwt3000,5bwt17");
    const int expected = 34;
    ASSERT_EQ(actual, expected);
}
