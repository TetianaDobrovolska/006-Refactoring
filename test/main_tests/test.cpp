#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <tuple>

TEST(CalculatorTest, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

class ParametrizedTest : public testing::TestWithParam < std::tuple<std::string, int> >
{
public:
    ~ParametrizedTest() override;
};

ParametrizedTest::~ParametrizedTest()
{

}

TEST_P(ParametrizedTest, stringCalcTest)
{
    std::string expression = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());
    if (expected != -1) {
        int actual = StringCalc::Add(expression);
        ASSERT_EQ(actual, expected);
    } else {
        EXPECT_THROW(StringCalc::Add(expression), std::invalid_argument);
    }
}

INSTANTIATE_TEST_SUITE_P(TDDKata, ParametrizedTest,
                         testing::Values(
                             std::make_tuple("1,2", 3),
                             std::make_tuple("2,2", 4),
                             std::make_tuple("1,7", 8),
                             std::make_tuple("1", 1),
                             std::make_tuple("12", 12),
                             std::make_tuple("", 0),
                             std::make_tuple("25,2", 27),
                             std::make_tuple("0,1,2", 3),
                             std::make_tuple("2,3,4,5", 14),
                             std::make_tuple("-2,3", -1),
                             std::make_tuple("-2", -1),
                             std::make_tuple("-42", -1),
                             std::make_tuple("Arg", -1),
                             std::make_tuple("67?89", -1),
                             std::make_tuple("45.123", -1),
                             std::make_tuple("1\n2", 3),
                             std::make_tuple("1\n2,3", 6),
                             std::make_tuple("//;\n1;2", 3),
                             std::make_tuple("//;\n2;3",5),
                             std::make_tuple("//$\n25,6$34", 65),
                             std::make_tuple("//S\n5,68S3\n12", 88),
                             std::make_tuple("//.\n1000.662", 1662),
                             std::make_tuple("//q\n1001q7", 7),
                             std::make_tuple("//§\n6;9", -1),
                             std::make_tuple("//;1;2", -1),
                             std::make_tuple("//[***]\n1***2***3", 6),
                             std::make_tuple("//[bwt]\n12bwt3000,5bwt17", 34),
                             std::make_tuple("//*%\n1%2*2",5),
                             std::make_tuple("5,6//*\n1,2,2",-1)
                             ));
