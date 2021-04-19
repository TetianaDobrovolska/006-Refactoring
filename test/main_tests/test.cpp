#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

 TEST(CalculatorTest, ZeroParams) {
    StringCalc c;
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
 }

 TEST(CalculatorTest, LowerBoundOneParam){
     StringCalc c;
     int actual = c.Add("0");
     ASSERT_EQ(actual, 0);
 }

 TEST(CalculatorTest, UpperBoundOneParam){
     StringCalc c;
     int actual = c.Add("1000000");
     ASSERT_EQ(actual, 1'000'000);
 }

 TEST(CalculatorTest, LowerBoundTwoParams){
     StringCalc c;
     int actual = c.Add("0,0");
     ASSERT_EQ(actual, 0);
 }

 TEST(CalculatorTest, UpperBoundTwoParams){
     StringCalc c;
     int actual = c.Add("1000000,1000000");
     ASSERT_EQ(actual, 2'000'000);
 }

 TEST(CalculatorTest, AllowedOnlyPositive){
     StringCalc c;
     int actual = c.Add("-2");
     ASSERT_EQ(actual, -1);
 }

 TEST(CalculatorTest, NotANumber){
     StringCalc c;
     int actual = c.Add("a");
     ASSERT_EQ(actual, -1);
 }

 TEST(CalculatorTest, WrongSeparator){
     StringCalc c;
     int actual = c.Add("1 2");
     ASSERT_EQ(actual, -1);
 }

 TEST(CalculatorTest, MixedSeparators){
     StringCalc c;
     int actual = c.Add("1,2\n3\n4");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, MoreThanTwoParams){
     StringCalc c;
     int actual = c.Add("1,2,3,4");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, RandomTest1){
     StringCalc c;
     int actual = c.Add("100,20,3");
     ASSERT_EQ(actual, 123);
 }

 TEST(CalculatorTest, RandomTest2){
     StringCalc c;
     int actual = c.Add("123,23,1,2,3");
     ASSERT_EQ(actual, 152);
 }

 TEST(CalculatorTest, RandomTest3){
     StringCalc c;
     int actual = c.Add("123,23,1,2,3\n10");
     ASSERT_EQ(actual, 162);
 }

