#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

/**
 * Positive tests:
 *  [done] empty string
 *  [done] zero as input
 *  [done] one positive integer
 *  [done] two positive integers
 *  [done] three positive integers
 *
 * Negative tests:
 *  [done] one negative integer
 *  [done] one negative integer and one positive integer
 *  [done] one positive integer and one negative integer
 *  [....] other delimiters
 *  [....] white space
 *
 */

TEST(CalculatorTest, EmptyString) {
   StringCalc c;
   const std::string input = "";
   const int expected = 0;
   int actual = c.Add(input);
   ASSERT_EQ(expected, actual);
}

TEST(CalculatorTest, ZeroInput) {
   StringCalc c;
   const std::string input = "0";
   const int expected = 0;
   int actual = c.Add(input);
   ASSERT_EQ(expected, actual);
}

 TEST(CalculatorTest, OnePositiveInteger) {
    StringCalc c;
    const std::string input = "1";
    const int expected = 1;
    int actual = c.Add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, TwoPositiveIntegers) {
    StringCalc c;
    const std::string input = "1,2";
    const int expected = 3;
    int actual = c.Add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ThreePositiveIntegers) {
    StringCalc c;
    const std::string input = "1,2,3";
    const int expected = 6;
    int actual = c.Add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ErrorOneNegativeInteger) {
    StringCalc c;
    const std::string input = "-2";
    const int expected = -1;
    int actual = c.Add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ErrorOneNegativeIntegerAndOnePositiveInteger) {
    StringCalc c;
    const std::string input = "-1,2";
    const int expected = -1;
    int actual = c.Add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ErrorOnePositiveIntegerAndOneNegativeInteger) {
    StringCalc c;
    const std::string input = "1,-3";
    const int expected = -1;
    int actual = c.Add(input);
    ASSERT_EQ(expected, actual);
 }
