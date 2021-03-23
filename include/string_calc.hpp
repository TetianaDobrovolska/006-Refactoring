#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

#define ERR_INVALID_ARGS -1

class StringCalc
{
public:
    StringCalc();

    StringCalc(char delimiter);

    ~StringCalc();

    int Add(const std::string& numbers);

private:
    bool ExtractOperands(const std::string& numbers, std::vector<int> &operands);
    char m_delimiter;
};

#endif

