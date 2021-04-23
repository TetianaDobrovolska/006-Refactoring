#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <exception>
#include <iostream>

class ParametrizedCalculatorTest : public ::testing::TestWithParam <std::tuple<std::string, int>>
{
protected:
   StringCalc c;
};

TEST_P(ParametrizedCalculatorTest, stringCalcTest)
{
    std::string expression = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());
    int actual = c.Add(expression);

    ASSERT_EQ(actual, expected);
}

INSTANTIATE_TEST_CASE_P(
        TDDKata,
        ParametrizedCalculatorTest,
        testing::Values(
            std::make_tuple("", 0),
            std::make_tuple("0", 0),
            std::make_tuple("1", 1),
            std::make_tuple("2,2", 4),
            std::make_tuple("1,10", 11),
            std::make_tuple("120,1", 121),
            std::make_tuple("100,20,", 123),
            std::make_tuple("-2,1", -1),
            std::make_tuple("a,1", -1),
            std::make_tuple("0,c", -1),
            std::make_tuple("3\n2", 5),
            std::make_tuple("1\n3,5", 9),
            std::make_tuple("//*\n4*1", 5),
            std::make_tuple("/*\n4*1,2", 7),
            std::make_tuple("//*\n4*1\n1", 6),
            std::make_tuple("//*\n4*1\n1,3", 9),
            std::make_tuple("//4,5", -1),
            std::make_tuple("/4,5", -1),
            std::make_tuple("//;\n4;5*1", -1),
            std::make_tuple("1001,2", 2),
            std::make_tuple("//[***]\n4***1", 5),
            std::make_tuple("//[***]\n4***1\n1,3", 9),
            std::make_tuple("//[***\n4***1", -1)
));
