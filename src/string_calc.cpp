#include "string_calc.hpp"
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

StringCalc::StringCalc() : _delimiter(',')
{
}

StringCalc::~StringCalc()
{
}

/**
 * @brief Checks if string is prefixed with: "//DELIMITER\n"
 *        where "DELIMITER" is a single-character value.
 *        Example:
 *              input-string: "//;\n1;2;3"
 *            with delimiter: ';'
 * @param str: the input string
 * @return: true, if prefixed; false otherwise
 *
 */
bool StringCalc::hasPrefix(const std::string& str) const
{
    return ((str.substr(0,2) == "//") && (str[3] == '\n'));
}

void StringCalc::validate(const std::string& str) const
{
    std::string input = str;
    char delimiter = _delimiter;

    if(hasPrefix(input))
    {
        delimiter = str[2];
        input = str.substr(4);
    } else
    {
        input = convertNewlinesToDelimiters(str);
    }

/* Allowed characters: "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
 * value of delimiter, and whitespace */
    std::string del_str(1, delimiter);
    std::string pattern = "-?\\d+\\s*(" + del_str + "\\s*-?\\d+\\s*)*";
    std::regex rx(pattern);
    bool valid = std::regex_match(input, rx);
    if(!valid)
        throw std::invalid_argument("Invalid input argument: " + str);
}

std::string StringCalc::convertNewlinesToDelimiters(const std::string& str) const
{
    std::string result = str;
    std::replace(result.begin(), result.end(), '\n', _delimiter);
    return result;
}

bool StringCalc::usesCustomDelimiter(std::string& str)
{
    if(hasPrefix(str))
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

/**
 * @brief StringCalc::add
 * @param numbers : a Delimited string of integers >= 0
 *                  optionally prefixed by a custom delimiter:
 *                  "//DELIMITER\n", where "DELIMITER" is the custom delimiter
 *                  e.g.: "//;\n1;2"
 * @return : 0, on empty string
 *          -1, in presence of negative operands
 *           otherwise: the sum of the operands' addition
 *
 * @throws : "std::invalid_argument" exception on invalid input string
 */
int StringCalc::add(const std::string& numbers)
{
    // zero for empty string
    if(numbers.empty())
        return 0;

    // throws "std::invalid_argument" exception on invalid input string
    validate(numbers);

    // no negative values are allowed
    if(numbers.find('-') != std::string::npos)
        return -1;

    // add one or more operands
    int sum = 0;
    std::vector<int> integers = convertStringToIntVect(numbers);
    for(auto& in : integers)
        sum += in;
    return sum;
}
