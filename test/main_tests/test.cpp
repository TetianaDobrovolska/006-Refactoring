#include "gtest/gtest.h"

#include "string_calc.hpp"

#include <iostream>



TEST(CalculatorTest, TestName) {

  EXPECT_EQ(1, 1);

  EXPECT_TRUE(true);

}



TEST(CalculatorTest, SampleTest) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("1,2"), 3);

 }





TEST(CalculatorTest, EmptyString) {

 	StringCalc c;

 	ASSERT_EQ(c.Add(""), 0);

 }





TEST(CalculatorTest, Symbol0) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("0"), 0);

 }





TEST(CalculatorTest, Symbol1) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("1"), 1);

 }





TEST(CalculatorTest, StringWrongArg) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("5,-1"), std::invalid_argument);

 }





TEST(CalculatorTest, StringWrongArgFirst) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("-2,10"), std::invalid_argument);

 }



TEST(CalculatorTest, SumFiveEL) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("5,100,20,5,1"), 131);

 }





TEST(CalculatorTest, SumFiveElWrongArg) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("5,100,-10,5,1"), std::invalid_argument);



 }







TEST(CalculatorTest, SumFiveNewLine) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("5\n100\n20,5\n1"), 131);

 }





TEST(CalculatorTest, SumFiveNewLineComma) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("5,100\n20,5\n1"), 131);

 }







TEST(CalculatorTest, SumFiveNewLineCommaWrongArgument) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("5,100\n20,5\n1,-1000"), std::invalid_argument);

 }



TEST(CalculatorTest, CheckSum) {

 	StringCalc c;

 	ASSERT_EQ( c.Add("1001,2\n1200"), 2);

 }







TEST(CalculatorTest, CheckSumThousand) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("1000,2\n999"), 2001);



 }



TEST(CalculatorTest, InvalidArgument) {

 	StringCalc c;	

 	ASSERT_THROW(c.Add("5,100\n20,1,-1"), std::invalid_argument);



}


TEST(CalculatorTest, SumFiveNewLineDelimiterMoreThanOne) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("//:::\n5,100*20/5:::1"), 131);

 }





TEST(CalculatorTest, SumWithoutSlashDelimiter) {

 	StringCalc c;

 	ASSERT_EQ(c.Add("(:::5:,10020::5,1"), 6);

 }