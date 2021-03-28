#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>

class StringCalc
{
public:

    int Add(const std::string& numbers);

    // optional
    //std::vector<char>& getAllowedDelimiters();

private:
    void ParseDelimiterDirective(const std::string& numbers, std::function<void(int)> f);
    bool ExtractOperands(const std::string& numbers, std::vector<int> &operands);

    std::vector<char> m_delimiters {',', '\n'};
};

#endif

