#include "string_calc.hpp"

#include <algorithm>
#include <exception>
#include <iostream>

namespace
{

constexpr int kInvalidValue = -1;
constexpr int kMaxNumber = 1000;

}


bool StringCalc::isDigit(const std::string& str)
{
    return std::all_of(str.cbegin(), str.cend(),
                       [](char ch){ return std::isdigit(ch); });
}

std::string::size_type StringCalc::findFirstDelim(const std::string& str,
                                                  std::vector<std::string>& delims,
                                                  size_t offset)
{
    if (offset >= str.size())
    {
        return std::string::npos;
    }

    std::string::size_type pos = str.size();
    for (size_t i = 0; i < delims.size(); ++i)
    {
        size_t tmp = str.find_first_of(delims[i], offset);
        if (std::string::npos != tmp && tmp < pos)
        {
            pos = tmp;
        }
    }
    return pos;
}

int StringCalc::Add(const std::string& numbers)
{
    try
    {
        if (numbers.empty())
        {
            return 0;
        }
        std::vector<std::string> delims = {",", "\n"};

        size_t begin = 0, end = 0;
        if ("//" == numbers.substr(0, 2))
        {
            const size_t startDelim = 2;
            const size_t endDelim = numbers.find_first_of("\n", startDelim);
            if (std::string::npos == endDelim)
            {
                throw kInvalidValue;
            }
            for (size_t i = startDelim; i < endDelim; ++i)
            {
                delims.emplace_back(std::string(1, numbers[i]));
            }
            begin = endDelim + 1;
        }

        int sum = 0;
        while (std::string::npos != (end = findFirstDelim(numbers, delims, begin)))
        {
            const std::string tmp = numbers.substr(begin, end - begin);
            if (!isDigit(tmp))
                throw kInvalidValue;
            int num = std::stoi(tmp);
            sum += kMaxNumber >= num  ? num : 0;
            begin = end + 1;
        }
        return sum;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
