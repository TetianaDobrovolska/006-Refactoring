#include "string_calc.hpp"

#include <algorithm>

namespace
{

constexpr int kInvalidValue = -1;

}


bool StringCalc::isDigit(const std::string& str)
{
    return std::all_of(str.cbegin(), str.cend(),
                       [](char ch){ return std::isdigit(ch); });
}


int StringCalc::Add(const std::string& numbers)
{
    const std::string delims { ",\n" };

    size_t begin, end = 0;
    int sum = 0;
    while (std::string::npos != (begin = numbers.find_first_not_of(delims, end)))
    {
        end = numbers.find_first_of(delims, begin + 1);
        const std::string tmp = numbers.substr(begin, end - begin);
        if (!isDigit(tmp))
            return kInvalidValue;
        sum += std::stoi(tmp);
    }
    return sum;
}
