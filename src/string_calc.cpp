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
    std::vector<std::string> tmp;
    std::copy(delims.begin(), delims.end(), std::back_inserter(tmp));
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
            tmp.emplace_back(str.substr(startDelim + 1, (endDelim - startDelim - 1)));
            startDelim = endDelim + 1;
        }
        endDelim = str.find_first_of("\n", startDelim);
        if (std::string::npos == endDelim)
        {
            return false;
        }
        for (size_t i = startDelim; i < endDelim; ++i)
        {
            tmp.emplace_back(std::string(1, str[i]));
        }
    }

    auto validChar = [tmp](char ch)
    {
        auto longDelim = [ch](auto it)
        {
            return it.find(ch) != std::string::npos;
        };
        return std::isdigit(ch) || '\n' == ch ||
                tmp.end() != std::find_if(tmp.begin(), tmp.end(), longDelim);
    };
    return std::all_of(str.begin() + endDelim, str.end(), validChar);
}

size_t StringCalc::AddDelims(const std::string& str)
{
    size_t endDelim = 0;
    if ("//" != str.substr(0, 2))
        return endDelim;

    size_t startDelim = 2;
    if ("[" == str.substr(startDelim, 1))
    {
        endDelim = str.find("]", startDelim);
        delims.emplace_back(str.substr(startDelim + 1, (endDelim - startDelim - 1)));
        startDelim = endDelim + 1;
    }
    endDelim = str.find_first_of("\n", startDelim);
    for (size_t i = startDelim; i < endDelim; ++i)
    {
        delims.emplace_back(std::string(1, str[i]));
    }
    return endDelim + 1;
}

void StringCalc::StringCalc::RemoveDelims()
{
    delims.erase(delims.begin() + 2, delims.end());
}

void StringCalc::Digits(const std::string& str, std::vector<int>& digits)
{
    size_t begin = AddDelims(str);
    size_t end = std::string::npos;
    size_t pos = std::string::npos;
    while (std::string::npos != (end = FindFirstDelim(str, delims, begin, pos)))
    {
        const std::string tmp = str.substr(begin, end - begin);
        digits.push_back(std::stoi(tmp));
        begin = end + (std::string::npos != pos ? delims[pos].size() : 1);
    }
    RemoveDelims();
}

int StringCalc::Add(const std::string& numbers)
{
    int sum = 0;
    if (numbers.empty())
    {
        return sum;
    }
    if(!IsValidity(numbers))
    {
        throw std::invalid_argument("Invalid argument");
    }

    std::vector<int> digits;
    Digits(numbers, digits);
    for (auto i : digits)
    {
        sum += kMaxNumber < i ? 0 : i;
    }
    return sum;
}
