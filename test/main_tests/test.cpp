#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, EmptyString) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, OneDigit) {
    StringCalc c;
    int actual = c.Add("1");
    ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SampleTest) {
    StringCalc c;
    int actual = c.Add("2,2");
    ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, SampleTest2) {
    StringCalc c;
    int actual = c.Add("1,10");
    ASSERT_EQ(actual, 11);
}

TEST(CalculatorTest, SampleTest3) {
    StringCalc c;
    int actual = c.Add("120,1");
    ASSERT_EQ(actual, 121);
}

TEST(CalculatorTest, LongString) {
    StringCalc c;
    int actual = c.Add("100,20,3");
    ASSERT_EQ(actual, 123);
}

TEST(CalculatorTest, NegativeValue) {
    StringCalc c;
    int actual = c.Add("-2,1");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, ZeroValue) {
    StringCalc c;
    int actual = c.Add("0");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, AlfaValue) {
    StringCalc c;
    int actual = c.Add("a,1");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, AlfaValue2) {
    StringCalc c;
    int actual = c.Add("0,c");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, NewLineString) {
    StringCalc c;
    int actual = c.Add("3\n2");
    ASSERT_EQ(actual, 5);
}

TEST(CalculatorTest, MixedDefaultDelim) {
    StringCalc c;
    int actual = c.Add("1\n3,5");
    ASSERT_EQ(actual, 9);
}

TEST(CalculatorTest, ExpandDelim) {
    StringCalc c;
    int actual = c.Add("//*\n4*1");
    ASSERT_EQ(actual, 5);
}

TEST(CalculatorTest, DefaultAndExpandDelims) {
    StringCalc c;
    int actual = c.Add("//*\n4*1,2");
    ASSERT_EQ(actual, 7);
}

TEST(CalculatorTest, DefaultAndExpandDelims2) {
    StringCalc c;
    int actual = c.Add("//*\n4*1\n1");
    ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, DefaultAndExpandDelims3) {
    StringCalc c;
    int actual = c.Add("//*\n4*1\n1,3");
    ASSERT_EQ(actual, 9);
}

TEST(CalculatorTest, InvalidDelims) {
    StringCalc c;
    int actual = c.Add("//4,5");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, InvalidDelims2) {
    StringCalc c;
    int actual = c.Add("/4,5");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, InvalidDelims3) {
    StringCalc c;
    int actual = c.Add("//;\n4;5*1");
    ASSERT_EQ(actual, -1);
}