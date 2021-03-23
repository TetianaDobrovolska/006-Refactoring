#include "StringCalcTest.h"

StringCalcTest::StringCalcTest()
{
}

TEST_F(StringCalcTest, TestStep1_goodInput_oneNumber) {
    int actual = c.Add("235");
    ASSERT_EQ(actual, 235);
}

TEST_F(StringCalcTest, TestStep1_goodInput_oneNumberAndComma) {
    int actual = c.Add(" 235 , 		");
    ASSERT_EQ(actual, 235);
}

TEST_F(StringCalcTest, TestStep1_goodInput_twoNumberAndComma) {
    int actual = c.Add(" 235 , 		1 	");
    ASSERT_EQ(actual, 236);
}

TEST_F(StringCalcTest, TestStep1_goodInput_Zero) {
    int actual = c.Add("0");
    ASSERT_EQ(actual, 0);
}

TEST_F(StringCalcTest, TestStep1_emptyString) {
    int actual = c.Add("");
    ASSERT_EQ(actual, 0);
}

TEST_F(StringCalcTest, TestStep1_emptyStringWithComma) {
    int actual = c.Add("   ,");
    ASSERT_EQ(actual, 0);
}

TEST_F(StringCalcTest, TestStep1_exception_conversion) {
    int actual = c.Add("aaaa");
    ASSERT_EQ(actual, -1);
}

TEST_F(StringCalcTest, TestStep1_exception_conversionWithComma) {
    int actual = c.Add("22,aaaa");
    ASSERT_EQ(actual, -1);
}

TEST_F(StringCalcTest, TestStep1_exception_negativeNumber) {
    int actual = c.Add("-2");
    ASSERT_EQ(actual, -1);
}

TEST_F(StringCalcTest, TestStep1_exception_negativeNumberWithComma) {
    int actual = c.Add("55,-2");
    ASSERT_EQ(actual, -1);
}
