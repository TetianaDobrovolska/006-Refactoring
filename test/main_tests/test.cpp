#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <stdexcept>

class CalculatorTest : public ::testing::Test {
protected:
    StringCalc c;
};

 TEST_F(CalculatorTest, ZeroParams) {
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
 }

 TEST_F(CalculatorTest, LowerBoundOneParam){
     int actual = c.Add("0");
     ASSERT_EQ(actual, 0);
 }

 TEST_F(CalculatorTest, UpperBoundOneParam){
     int actual = c.Add("1000");
     ASSERT_EQ(actual, 1'000);
 }

 TEST_F(CalculatorTest, OutUpperBoundOneParam){
     int actual = c.Add("1001");
     ASSERT_EQ(actual, 0);
 }

 TEST_F(CalculatorTest, LowerBoundTwoParams){
     int actual = c.Add("0,0");
     ASSERT_EQ(actual, 0);
 }

 TEST_F(CalculatorTest, UpperBoundTwoParams){
     int actual = c.Add("1000,1000");
     ASSERT_EQ(actual, 2'000);
 }

 TEST_F(CalculatorTest, OutUpperBoundTwoParams){
     int actual = c.Add("1001,1000");
     ASSERT_EQ(actual, 1'000);
 }

 TEST_F(CalculatorTest, AllowedOnlyPositive){
     ASSERT_THROW(c.Add("-2"), std::invalid_argument);
 }

 TEST_F(CalculatorTest, NotANumber){
     ASSERT_THROW(c.Add("a"), std::invalid_argument);
 }

 TEST_F(CalculatorTest, WrongSeparator){
     ASSERT_THROW(c.Add("1-2"), std::invalid_argument);
 }

 TEST_F(CalculatorTest, MixedSeparators){
     int actual = c.Add("1,2\n3\n4");
     ASSERT_EQ(actual, 10);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsValid1){
     int actual = c.Add("//;\n1;2");
     ASSERT_EQ(actual, 3);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsValid2){
     int actual = c.Add("//;\n1;2;7");
     ASSERT_EQ(actual, 10);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsValid3){
     int actual = c.Add("//[***]\n1***2***7");
     ASSERT_EQ(actual, 10);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsValid4){
     int actual = c.Add("//[;ab]\n1;ab2;ab7");
     ASSERT_EQ(actual, 10);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsNegative1){
     int actual = c.Add("//;\n1;2,7");
     ASSERT_EQ(actual, 10);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsNegative2){
     ASSERT_THROW(c.Add("/;\n1;2;7"), std::invalid_argument);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsNegative3){
     ASSERT_THROW(c.Add("//;\n\n1;2;7"), std::invalid_argument);
 }

 TEST_F(CalculatorTest, SpecialSeparatorsNegative4){
     ASSERT_THROW(c.Add("//[***\n1***2***7"), std::invalid_argument);
 }

 TEST_F(CalculatorTest, MoreThanTwoParams){
     int actual = c.Add("1,2,3,4");
     ASSERT_EQ(actual, 10);
 }

 TEST_F(CalculatorTest, RandomTest1){
     int actual = c.Add("100,20,3");
     ASSERT_EQ(actual, 123);
 }

 TEST_F(CalculatorTest, RandomTest2){
     int actual = c.Add("123,23,1,2,3");
     ASSERT_EQ(actual, 152);
 }

 TEST_F(CalculatorTest, RandomTest3){
     int actual = c.Add("123,23,1,2,3\n10");
     ASSERT_EQ(actual, 162);
 }

 TEST_F(CalculatorTest, RandomTest4){
     int actual = c.Add("123,23,1,2,3\n10,1001");
     ASSERT_EQ(actual, 162);
 }

