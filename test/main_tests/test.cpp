#include "gtest/gtest.h"

#include "string_calc.hpp"

#include <iostream>



TEST(CalculatorTest, TestName) {

  EXPECT_EQ(1, 1);

  EXPECT_TRUE(true);

}



TEST(CalculatorTest, SampleTest) {

 	StringCalc c;

 	int actual = c.Add("1,2");

 	ASSERT_EQ(actual, 3);

 }




TEST(CalculatorTest, EmptyString) {

 	StringCalc c;

 	int actual = c.Add("");

 	ASSERT_EQ(actual, 0);

 }




TEST(CalculatorTest, Symbol0) {

 	StringCalc c;

 	int actual = c.Add("0");

 	ASSERT_EQ(actual, 0);

 }




TEST(CalculatorTest, Symbol1) {

 	StringCalc c;

 	int actual = c.Add("1");

 	ASSERT_EQ(actual, 1);

 }




TEST(CalculatorTest, StringSub) {

 	StringCalc c;

 	int actual = c.Add("2,-1");

 	ASSERT_EQ(actual, -1);

 }

