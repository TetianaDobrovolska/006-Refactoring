#include "string_calc.hpp"

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(const std::string& numbers)
{
    int sum = 0;
    for (auto s : numbers) {
        if (std::isdigit(s)) {
            sum += s - '0';
        }
    }
    return sum;
}
