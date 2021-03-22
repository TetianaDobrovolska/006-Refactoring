#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

 TEST(CalculatorTest, SampleTest) {
        StringCalc c;
        const int expected_value = 18;
        int actual = c.Add("13,5");
        ASSERT_EQ(actual, expected_value);
 }

 TEST(CalculatorTest, NumberOfOperandsTest) {
        StringCalc c;

        const int expected_result1 = 18;
        int actual = c.Add("13,5");
        ASSERT_EQ(actual, expected_result1);

        const int expected_result2 = 13;
        actual = c.Add("13");
        ASSERT_EQ(actual, expected_result2);

        const int expected_result3 = 37;
        actual = c.Add("13,2,4,5,6,7");
        ASSERT_EQ(actual, expected_result3);

        const int expected_result4 = 9;
        actual = c.Add("3,2,4");
        ASSERT_EQ(actual, expected_result4);

        const int default_result = 0;
        actual = c.Add("");
        ASSERT_EQ(actual, default_result);
 }

 TEST(CalculatorTest, NegativeNumberTest) {
        StringCalc c;

        const int error_result = -1;
        int actual = c.Add("-2, 0");
        ASSERT_EQ(actual, error_result);

        actual = c.Add("0, -4");
        ASSERT_EQ(actual, error_result);

        actual = c.Add("-1");
        ASSERT_EQ(actual, error_result);
 }

