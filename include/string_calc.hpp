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
    size_t nextDelimiterPosition(std::string inputStr, std::string &foundDelimiter);

    std::vector<std::string> defaultDelimiters;
};

#endif

