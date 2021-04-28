#include "string_calc.hpp"

#include <algorithm>
#include <exception>
#include <iostream>

std::string::size_type StringCalc::FindFirstDelim(const std::string& str,
                                                  std::vector<std::string>& delims,
                                                  size_t offset,
                                                  size_t& delim_pos)
{
    if (offset >= str.size())
    {
        return std::string::npos;
    }

    std::string::size_type pos = str.size();
    for (size_t i = 0; i < delims.size(); ++i)
    {
        size_t tmp = str.find_first_of(delims[i], offset);
        if (std::string::npos == tmp || tmp >= pos)
            continue;
        pos = tmp;
        delim_pos = i;
    }
    return pos;
}

bool StringCalc::IsValidity(const std::string& str)
{
    size_t endDelim = 0;
    if ("//" == str.substr(0, 2))
    {
        size_t startDelim = 2;
        if ("[" == str.substr(startDelim, 1))
        {
            endDelim = str.find("]", startDelim);
            if (std::string::npos == endDelim)
            {
                return false;
            }
            delims.emplace_back(str.substr(startDelim, (endDelim - startDelim)));
            startDelim = endDelim + 1;
        }
        endDelim = str.find_first_of("\n", startDelim);
        if (std::string::npos == endDelim)
        {
            return false;
        }
        for (size_t i = startDelim; i < endDelim; ++i)
        {
            delims.emplace_back(std::string(1, str[i]));
        }
    }

    std::vector<std::string> tmp;
    std::copy(delims.begin(), delims.end(), std::back_inserter(tmp));
    auto validChar = [tmp](char ch)
    {
        return std::isdigit(ch) || '\n' == ch ||
                tmp.end() != std::find(tmp.begin(), tmp.end(), std::string(1, ch));
    };
    return std::all_of(str.begin() + endDelim, str.end(), validChar);
}

int StringCalc::Add(const std::string& numbers)
{
    if (numbers.empty())
    {
        return 0;
    }

    if(!IsValidity(numbers))
    {
        throw std::invalid_argument("Invalid argument");
    }

    size_t begin = 0, end = 0;
    if ("//" == numbers.substr(0, 2))
        begin = numbers.find_first_of("\n", begin) + 1;

    int sum = 0;
    size_t pos = std::string::npos;
    while (std::string::npos != (end = FindFirstDelim(numbers, delims, begin, pos)))
    {
        const std::string tmp = numbers.substr(begin, end - begin);
        int num = std::stoi(tmp);
        sum += kMaxNumber >= num  ? num : 0;
        begin = end + (std::string::npos != pos ? delims[pos].size() : 1);
    }
    delims.erase(delims.begin() + 2, delims.end());
    return sum;
}
