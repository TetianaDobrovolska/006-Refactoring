#include "gtest/gtest.h"

#include "string_calc.hpp"

#include <iostream>


using namespace std;

class CheckSumMultipleParametersTests :public ::testing::TestWithParam<std::tuple<int, std::string>> {
protected:
   StringCalc c;
};

TEST_P(CheckSumMultipleParametersTests, CheckSum) {
    int expected = std::get<0>(GetParam());
    std::string numberstring = std::get<1>(GetParam());
    ASSERT_EQ(expected, c.Add(numberstring));
}

INSTANTIATE_TEST_CASE_P(
       CheckSumTests,
       CheckSumMultipleParametersTests,
        ::testing::Values(
                std::make_tuple(3, "1,2"),
                std::make_tuple(0, ""),
                std::make_tuple(0, "0"),
                std::make_tuple(1, "1"),
                std::make_tuple(131, "5,100,20,5,1"),
                std::make_tuple(131, "5\n100\n20,5\n1"),
                std::make_tuple(131, "5,100,20,5\n1"),
                std::make_tuple(2, "1001,2\n1200"),
                std::make_tuple(2001, "1000,2\n999"),
                std::make_tuple(131, "//:::\n5,100*20/5:::1"),
                std::make_tuple(11, ":::5,121::5,1")
));


TEST(CalculatorTest, StringWrongArg) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("5,-1"), std::invalid_argument);

 }





TEST(CalculatorTest, StringWrongArgFirst) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("-2,10"), std::invalid_argument);

 }




TEST(CalculatorTest, SumFiveElWrongArg) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("5,100,-10,5,1"), std::invalid_argument);



 }



TEST(CalculatorTest, SumFiveNewLineCommaWrongArgument) {

 	StringCalc c;

 	ASSERT_THROW(c.Add("5,100\n20,5\n1,-1000"), std::invalid_argument);

 }



TEST(CalculatorTest, InvalidArgument) {

 	StringCalc c;	

 	ASSERT_THROW(c.Add("5,100\n20,1,-1"), std::invalid_argument);



}

