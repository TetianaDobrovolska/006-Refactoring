#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <stdexcept>

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
     int actual = c.Add("1000");
     ASSERT_EQ(actual, 1'000);
 }

 TEST(CalculatorTest, OutUpperBoundOneParam){
     StringCalc c;
     int actual = c.Add("1001");
     ASSERT_EQ(actual, 0);
 }

 TEST(CalculatorTest, LowerBoundTwoParams){
     StringCalc c;
     int actual = c.Add("0,0");
     ASSERT_EQ(actual, 0);
 }

 TEST(CalculatorTest, UpperBoundTwoParams){
     StringCalc c;
     int actual = c.Add("1000,1000");
     ASSERT_EQ(actual, 2'000);
 }

 TEST(CalculatorTest, OutUpperBoundTwoParams){
     StringCalc c;
     int actual = c.Add("1001,1000");
     ASSERT_EQ(actual, 1'000);
 }

 TEST(CalculatorTest, AllowedOnlyPositive){
     StringCalc c;
     ASSERT_THROW(c.Add("-2"), std::invalid_argument);
 }

 TEST(CalculatorTest, NotANumber){
     StringCalc c;
     ASSERT_THROW(c.Add("a"), std::invalid_argument);
 }

 TEST(CalculatorTest, WrongSeparator){
     StringCalc c;
     ASSERT_THROW(c.Add("1-2"), std::invalid_argument);
 }

 TEST(CalculatorTest, MixedSeparators){
     StringCalc c;
     int actual = c.Add("1,2\n3\n4");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, SpecialSeparatorsValid1){
     StringCalc c;
     int actual = c.Add("//;\n1;2");
     ASSERT_EQ(actual, 3);
 }

 TEST(CalculatorTest, SpecialSeparatorsValid2){
     StringCalc c;
     int actual = c.Add("//;\n1;2;7");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, SpecialSeparatorsValid3){
     StringCalc c;
     int actual = c.Add("//[***]\n1***2***7");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, SpecialSeparatorsValid4){
     StringCalc c;
     int actual = c.Add("//[;ab]\n1;ab2;ab7");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, SpecialSeparatorsNegative1){
     StringCalc c;
     int actual = c.Add("//;\n1;2,7");
     ASSERT_EQ(actual, 10);
 }

 TEST(CalculatorTest, SpecialSeparatorsNegative2){
     StringCalc c;
     ASSERT_THROW(c.Add("/;\n1;2;7"), std::invalid_argument);
 }

 TEST(CalculatorTest, SpecialSeparatorsNegative3){
     StringCalc c;
     ASSERT_THROW(c.Add("//;\n\n1;2;7"), std::invalid_argument);
 }

 TEST(CalculatorTest, SpecialSeparatorsNegative4){
     StringCalc c;
     ASSERT_THROW(c.Add("//[***\n1***2***7"), std::invalid_argument);
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

 TEST(CalculatorTest, RandomTest4){
     StringCalc c;
     int actual = c.Add("123,23,1,2,3\n10,1001");
     ASSERT_EQ(actual, 162);
 }

