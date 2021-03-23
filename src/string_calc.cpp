#include "string_calc.hpp"
#include <vector>
#include <sstream>
#include <algorithm>

StringCalc::StringCalc() : _delimiter(',')
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

bool StringCalc::usesCustomDelimiter(std::string& str)
{
    /* A user defined delimiter is only allowed if the
     * input-string is prefixed with: "//?\n"
     * where "?" is a single-character value. Eg:
     * input-string "//;\n1;2;3" with delimiter ";" */
    if((str.substr(0,2) == "//") && (str[3] == '\n'))
    {
        _delimiter = str[2];
        str = str.substr(4);
        return true;
    }
    return false;
}

std::vector<int> StringCalc::convertStringToIntVect(const std::string& str)
{
    std::vector<int> integers_vector;
    std::string parsed_str = str;
    if(!usesCustomDelimiter(parsed_str))
        parsed_str = convertNewlinesToDelimiters(parsed_str);

    std::stringstream ss(parsed_str);
    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, _delimiter);
        integers_vector.push_back(std::stoi(substr));
    }

    return integers_vector;
}

int StringCalc::add(const std::string& numbers)
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
