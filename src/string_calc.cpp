#include "string_calc.hpp"
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

StringCalc::StringCalc() : _delimiter(','), _prefix_start("//"), _prefix_end("\n")
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
void StringCalc::parsePrefix(std::string& str, std::string& custom_delimiter) const
{
    std::string prefix_pattern = "^(" + _prefix_start + "." + _prefix_end + ")";
    std::regex rx(prefix_pattern);
    std::smatch m;
    if(std::regex_search(str, m, rx))
    {
        size_t delim_start_index = _prefix_start.length();
        size_t delim_length = m.str().length() - _prefix_start.length() - _prefix_end.length();
        custom_delimiter = m.str().substr(delim_start_index, delim_length);
        str = m.suffix();
    }
}

std::string StringCalc::validate(const std::string& str) const
{
    std::string parsed = str;
    std::string custom_delimiter;
    parsePrefix(parsed, custom_delimiter);
    convertPatternToDelimiter("\n", parsed);
    if(custom_delimiter.length() > 0)
        convertPatternToDelimiter(custom_delimiter, parsed);

    /* Allowed characters: all digits, value_of_delimiter, and whitespace */
    std::string delimiter(1, _delimiter);
    std::string pattern = "-?\\d+\\s*(" + delimiter + "\\s*-?\\d+\\s*)*";
    std::regex rx(pattern);
    bool valid = std::regex_match(parsed, rx);
    if(!valid)
        throw std::invalid_argument("Invalid input argument: " + str);
    return parsed;
}

void StringCalc::convertPatternToDelimiter(const std::string& pattern, std::string& str) const
{
    std::string delimiter(1, _delimiter);
    str = std::regex_replace(str, std::regex(pattern.c_str()), delimiter);
}

std::vector<int> StringCalc::convertStringToIntVect(const std::string& str)
{
    std::vector<int> integers_vector;
    std::string parsed_str = str;

    std::stringstream ss(parsed_str);
    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, _delimiter);
        const auto operand = std::stoi(substr);
        if(operand <= OPERAND_UPPER_LIMIT)
            integers_vector.push_back(operand);
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
    if(numbers.empty())
        return 0;

    // throws "std::invalid_argument" exception on invalid input string
    std::string validated_str = validate(numbers);

    // no negative values are allowed
    if(validated_str.find('-') != std::string::npos)
        return -1;

    int sum = 0;
    std::vector<int> integers = convertStringToIntVect(validated_str);
    for(auto& in : integers)
        sum += in;
    return sum;
}
