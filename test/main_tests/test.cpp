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




TEST(CalculatorTest, StringWrongArg) {

 	StringCalc c;

 	int actual = c.Add("2,-1");

 	ASSERT_EQ(actual, -1);

 }




TEST(CalculatorTest, SumFiveEL) {

 	StringCalc c;

 	int actual = c.Add("5,100,20,5,1");

 	ASSERT_EQ(actual, 131);

 }




TEST(CalculatorTest, SumFiveElWrongArg) {

 	StringCalc c;

 	int actual = c.Add("5,100,-10,5,1");

 	ASSERT_EQ(actual, -1);

 }




TEST(CalculatorTest, SumFiveNewLine) {

 	StringCalc c;

 	int actual = c.Add("5,100\n20,5\n1");

 	ASSERT_EQ(actual, 131);

 }