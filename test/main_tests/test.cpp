#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <limits>

#define ERR_INVALID_ARGS -1

TEST(CalculatorTest, EmptyStringOrZeroOperands)
{
    StringCalc c;

    int actual = c.Add("");
    ASSERT_EQ(actual, 0);

    actual = c.Add("0");
    ASSERT_EQ(actual, 0);

    actual = c.Add("0,0");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, RegularOperands)
{
    StringCalc c;

    int actual = c.Add("0,123");
    ASSERT_EQ(actual, 123);

    actual = c.Add("456,0");
    ASSERT_EQ(actual, 456);

    actual = c.Add("123,456");
    ASSERT_EQ(actual, 579);
}

TEST(CalculatorTest, InvalidString)
{
    StringCalc c;

    int actual = c.Add("abc");
    ASSERT_EQ(actual, ERR_INVALID_ARGS);

    // note: skip this for now
//    actual = c.Add(",1,2");
//    ASSERT_EQ(actual, ERR_INVALID_ARGS);
}

TEST(CalculatorTest, NegativeOperandsMultipleDigits)
{
    StringCalc c;
    int actual = c.Add("-123");
    ASSERT_EQ(actual, ERR_INVALID_ARGS);

    actual = c.Add("0,-123");
    ASSERT_EQ(actual, ERR_INVALID_ARGS);

    actual = c.Add("-123,-456");
    ASSERT_EQ(actual, ERR_INVALID_ARGS);
}

TEST(CalculatorTest, TooLargeOperand)
{
    StringCalc c;
    long invalidIntValue = static_cast<long>(std::numeric_limits<int>::max()) + 10;
    std::string biggerThanInt = std::to_string(invalidIntValue);

    int actual = c.Add(biggerThanInt);
    ASSERT_EQ(actual, ERR_INVALID_ARGS);
}

TEST(CalculatorTest, TooLargeSum)
{
    StringCalc c;

    const int halfInt = std::numeric_limits<int>::max() / 2;
    const int operand1 = halfInt + 5;
    const int operand2 = halfInt + 10;
    // e.g. 1073741828,1073741833 ==> 2147483661
    std::string tooLargeSum{std::to_string(operand1) + "," + std::to_string(operand2)};

    int actual = c.Add(tooLargeSum);
    ASSERT_EQ(actual, ERR_INVALID_ARGS);
}
