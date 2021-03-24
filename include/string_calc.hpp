#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
    StringCalc();

    ~StringCalc();

    int Add(std::string numbers);

private:
    int convertToIntHelper(std::string token);
    size_t nextDelimiterPosition(std::string inputStr,
        std::vector<std::string> delimiters, std::string &foundDelimiter);
    std::vector<std::string> parseDelimiter(std::string inputStr, std::string &stringForCalc);
    std::vector<std::string> parseDelimiterDefinition(std::string inputStr);

    std::vector<std::string> defaultDelimiters;
};

#endif

