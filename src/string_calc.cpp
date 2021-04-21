#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>

StringCalc::StringCalc()
{
}

StringCalc::~StringCalc()
{
}

bool StringCalc::validity(const std::string& numbers)
{
    for (auto s:numbers)
    {
        if(s != m_defaultDelimiter && !std::isdigit(s))
        {
            return false;
        }
    }
    return true;
}

int StringCalc::Add(const std::string& numbers)
{
    if (numbers.empty())
    {
           return 0;
    }

    if(!validity(numbers))
    {
        return -1;
    }

    std::stringstream stream(numbers);
    std::string segment;
    int sum = 0;
    while(std::getline(stream, segment, m_defaultDelimiter))
    {
       sum += std::stoi(segment);
    }
    return sum;
}
