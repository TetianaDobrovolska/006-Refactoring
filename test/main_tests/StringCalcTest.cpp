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
//    int actual = c.Add("aaaa");
//    ASSERT_EQ(actual, -1);
// Step5
    ASSERT_THROW(c.Add("aaaa"), std::invalid_argument);
}

TEST_F(StringCalcTest, TestStep1_exception_conversionWithComma) {
//    int actual = c.Add("22,aaaa");
//    ASSERT_EQ(actual, -1);
// Step5
    ASSERT_THROW(c.Add("22,aaaa"), std::invalid_argument);
}

TEST_F(StringCalcTest, TestStep1_exception_negativeNumber) {
    int actual = c.Add("-2");
    ASSERT_EQ(actual, -1);
}

TEST_F(StringCalcTest, TestStep1_exception_negativeNumberWithComma) {
    int actual = c.Add("55,-2");
    ASSERT_EQ(actual, -1);
}

TEST_F(StringCalcTest, TestStep2_threeNumbers_good) {
    int actual = c.Add("2, 3, 40");
    ASSERT_EQ(actual, 45);
}

TEST_F(StringCalcTest, TestStep2_threeNumbers_goodWithZero) {
    int actual = c.Add("2, 3, 0");
    ASSERT_EQ(actual, 5);
}

TEST_F(StringCalcTest, TestStep2_twoNumbersAndEmpty) {
    int actual = c.Add("2, 3, ");
    ASSERT_EQ(actual, 5);
}

TEST_F(StringCalcTest, TestStep3_onlyNewSeparator) {
    int actual = c.Add("2\n 3\n 1\n 4\n 4");
    ASSERT_EQ(actual, 14);
}

TEST_F(StringCalcTest, TestStep3_mixedSeparator) {
    int actual = c.Add("2, 3\n 1, 4\n 4");
    ASSERT_EQ(actual, 14);
}

TEST_F(StringCalcTest, TestStep4_customDelimiter_good_spaceAsDelimiter) {
    int actual = c.Add("// \n2  3  1  4		 4 100  30 90 90 70");
    ASSERT_EQ(actual, 394);
}

TEST_F(StringCalcTest, TestStep4_customDelimiter_good_characterAsDelimiter) {
    int actual = c.Add("//a\n2 a 3 a 1 a 4	a	 4a 100 a 30 a90 a90 a70");
    ASSERT_EQ(actual, 394);
}

TEST_F(StringCalcTest, TestStep4_customDelimiter_exception_noNewLine) {
//    int actual = c.Add("// 2  3  1  4		 4 100  30 90 90 70");
//    ASSERT_EQ(actual, -1);
//  Step5
    ASSERT_THROW(c.Add("// 2 3  1   211 222"), std::invalid_argument);
}

TEST_F(StringCalcTest, TestStep4_customDelimiter_exception_oneSplash) {
//    int actual = c.Add("/ \n 2  3  1  4		 4 100  30 90 90 70");
//    ASSERT_EQ(actual, -1);
//  Step5
    ASSERT_THROW(c.Add("/ \n 2 3  1   211 222"), std::invalid_argument);
}

TEST_F(StringCalcTest, TestStep4_customDelimiter_exception_wrongCustomeDelimiter) {
//    int actual = c.Add("//a\n 2 b 3 b 1 b 4	b	 4b 100b  30 b90 b90b 70");
//    ASSERT_EQ(actual, -1);
//  Step5
    ASSERT_THROW(c.Add("//a\n 2b 3b  1 b  211b 222"), std::invalid_argument);
}

TEST_F(StringCalcTest, TestStep6_ignoreNumberOver1000) {
    int actual = c.Add("1000, 1003, 40");
    ASSERT_EQ(actual, 1040);
}

TEST_F(StringCalcTest, TestStep6_allOver1000) {
    int actual = c.Add("1002, 1003, 1040");
    ASSERT_EQ(actual, 0);
}

