#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, emptyString) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}

 TEST(CalculatorTest, oneNumber) {
 	StringCalc c;
 	int actual = c.Add("2");
 	ASSERT_EQ(actual, 2);
 }

 TEST(CalculatorTest, twoNumber) {
     StringCalc c;
     int actual = c.Add("1,2");
     ASSERT_EQ(actual, 3);
 }

 TEST(CalculatorTest, twoNumber) {
     StringCalc c;
     int actual = c.Add("1.2");
     ASSERT_EQ(actual, -1);
 }

 TEST(CalculatorTest, multipleNumbers) {
     StringCalc c;
     int actual = c.Add("5,2,5,8,9");
     ASSERT_EQ(actual, 29);
 }
 