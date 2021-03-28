#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <limits>

class CalculatorTest : public ::testing::Test {
protected:
    StringCalc c;
};

TEST_F(CalculatorTest, EmptyStringOrZeroOperands)
{
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);

    actual = c.Add("0");
    ASSERT_EQ(actual, 0);

    actual = c.Add("0,0");
    ASSERT_EQ(actual, 0);
}

TEST_F(CalculatorTest, RegularOperands)
{
    int actual = c.Add("0,123");
    ASSERT_EQ(actual, 123);

    actual = c.Add("456,0");
    ASSERT_EQ(actual, 456);

    actual = c.Add("123,456");
    ASSERT_EQ(actual, 579);
}

TEST_F(CalculatorTest, InvalidString)
{
    ASSERT_THROW(c.Add("abc"), std::invalid_argument);

    // note: skip this for now
//    ASSERT_THROW(c.Add(",1,2"), std::invalid_argument);
}

TEST_F(CalculatorTest, NegativeOperandsMultipleDigits)
{
    ASSERT_THROW(c.Add("-123"), std::invalid_argument);
    ASSERT_THROW(c.Add("0,-123"), std::invalid_argument);
    ASSERT_THROW(c.Add("123,-456"), std::invalid_argument);
}

// NOTE: some escaped characters (\r, \t, \f, \n) and spaces are
// automatically removed by the std::stringstream extraction operator >>
// when extracting an int number from the strem
TEST_F(CalculatorTest, MultipleOperands)
{
    int actual = c.Add("1,2,3,4,5");
    ASSERT_EQ(actual, 15);

    actual = c.Add("1, 2,  3,   4,5");
    ASSERT_EQ(actual, 15);
}

TEST_F(CalculatorTest, MultipleOperandsAllDelimiters)
{
    int actual = c.Add("1,2\n3,4\n5");
    ASSERT_EQ(actual, 15);
}

TEST_F(CalculatorTest, InvalidMultipleOperands)
{
    ASSERT_THROW(c.Add("1,2,-3,4,5"), std::invalid_argument);
    ASSERT_THROW(c.Add("1,2,xx,4,5"), std::invalid_argument);
    ASSERT_THROW(c.Add("1,2, ,4,5"), std::invalid_argument);
}

TEST_F(CalculatorTest, CustomDelimiter)
{
    int actual = c.Add("//;\n1,2;3,4,5");
    ASSERT_EQ(actual, 15);
}

TEST_F(CalculatorTest, InvalidCustomDelimiterSequence)
{
    ASSERT_THROW(c.Add("/;\n1,2;3,4,5"), std::invalid_argument);
    ASSERT_THROW(c.Add(";\n1,2;3,4,5"), std::invalid_argument);

    // TBD is this to be considered a valid case? \n is a legal separator
    // if placed at the beginning of the string it shall be simply skipped by the parser
    ASSERT_THROW(c.Add("\n1,2;3,4,5"), std::invalid_argument);
}

TEST_F(CalculatorTest, TooLargeOperand)
{
    long invalidIntValue = static_cast<long>(std::numeric_limits<int>::max()) + 10;
    std::string biggerThanInt = std::to_string(invalidIntValue);

    ASSERT_THROW(c.Add(biggerThanInt), std::invalid_argument);
}

TEST_F(CalculatorTest, TooLargeSum)
{
    const int halfInt = std::numeric_limits<int>::max() / 2;
    const int operand1 = halfInt + 5;
    const int operand2 = halfInt + 10;
    // e.g. 1073741828,1073741833 ==> 2147483661
    std::string tooLargeSum{std::to_string(operand1) + "," + std::to_string(operand2)};

    ASSERT_THROW(c.Add(tooLargeSum), std::invalid_argument);
}
