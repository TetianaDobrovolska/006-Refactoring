#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:

    int Add(const std::string& numbers);

    static constexpr int ERR_INVALID_ARGS = -1;

    // optional
    //std::vector<char>& getAllowedDelimiters();

private:
    bool ExtractOperands(const std::string& numbers, std::vector<int> &operands);

    const std::vector<char> LEGAL_DELIMITERS {',', '\n'};
};

#endif

