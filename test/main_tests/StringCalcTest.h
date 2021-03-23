#pragma once

#include <gtest/gtest.h>

#include "string_calc.hpp"

class StringCalcTest : public ::testing::Test
{
public:
    StringCalcTest();

    StringCalc c;
};
