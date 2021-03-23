#include "string_calc.hpp"
#include <vector>
#include <sstream>
#include <algorithm>

StringCalc::StringCalc()
{
}

StringCalc::~StringCalc()
{
}

bool StringCalc::hasNegatives(const std::string& str) const
{
    return (str.find('-') != std::string::npos);
}

std::string StringCalc::convertNewlinesToDelimiters(const std::string& str) const
{
    std::string result = str;
    std::replace(result.begin(), result.end(), '\n', _delimiter);
    return result;
}

std::vector<int> StringCalc::convertStringToIntVect(const std::string& str) const
{
    std::vector<int> integers_vector;
    std::string converted_str = convertNewlinesToDelimiters(str);

    std::stringstream ss(converted_str);
    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, _delimiter);
        integers_vector.push_back(std::stoi(substr));
    }

    return integers_vector;
}

int StringCalc::Add(const std::string& numbers) const
{
    // zero for empty string
    if(numbers.empty())
        return 0;

    // no negative values are allowed
    if(hasNegatives(numbers))
        return -1;

    // add one or more operands
    int result = 0;
    std::vector<int> integers = convertStringToIntVect(numbers);
    for(auto& in : integers)
        result += in;
    return result;
}
