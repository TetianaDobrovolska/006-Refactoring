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

TEST(CalculatorTest, SimpleTest) {
    StringCalc c;
    int actual = c.Add("1,7");
    ASSERT_EQ(actual, 8);
}

TEST(CalculatorTest, EmptyString) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}


TEST(CalculatorTest, OneNumber) {
    StringCalc c;
    int actual = c.Add("12");
    ASSERT_EQ(actual, 12);
}

TEST(CalculatorTest, ThreeNumber) {
    StringCalc c;
    int actual = c.Add("0,1,2");
    ASSERT_EQ(actual, 3);
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
    int actual = c.Add("1\n2");
    ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, MixedDelimiter) {
    StringCalc c;
    int actual = c.Add("1\n2,3");
    ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, CustomDelimiter) {
    StringCalc c;
    int actual = c.Add("//;\n1;2");
    ASSERT_EQ(actual,3);
}

TEST(CalculatorTest, CustomDelimiter2) {
    StringCalc c;
    EXPECT_THROW(c.Add("//§\n6;9"), std::invalid_argument);
}

TEST(CalculatorTest, CustomDelimiter3) {
    StringCalc c;
    int actual = c.Add("//$\n25,6$34");
    ASSERT_EQ(actual,65);
}

TEST(CalculatorTest, CustomDelimiter4) {
    StringCalc c;
    int actual = c.Add("//S\n5,68S3\n12");
    ASSERT_EQ(actual,88);
}

TEST(CalculatorTest, InvalidCustomDelimiterDefinition) {
    StringCalc c;
    EXPECT_THROW(c.Add("//;1;2"), std::invalid_argument);
}

TEST(CalculatorTest, Valid1000Value) {
    StringCalc c;
    int actual = c.Add("//.\n1000.662");
    ASSERT_EQ(actual,1662);
}

TEST(CalculatorTest, InvalidMore1000Value) {
    StringCalc c;
    int actual = c.Add("//q\n1001q7");
    ASSERT_EQ(actual,7);
}

TEST(CalculatorTest, FewSymbolsDelimiter) {
    StringCalc c;
    int actual = c.Add("//[***]\n1***2***3");
    ASSERT_EQ(actual,6);
}


TEST(CalculatorTest, FewSymbolsDelimiter2) {
    StringCalc c;
    int actual = c.Add("//[bwt]\n12bwt3000,5bwt17");
    ASSERT_EQ(actual,34);
}
