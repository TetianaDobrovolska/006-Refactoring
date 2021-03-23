#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>

#define ERR_INVALID_ARGS -1

class StringCalc
{
public:
    StringCalc();

    ~StringCalc();

    int Add(std::string numbers);

private:
    int ConvertOperand(std::string operand);
};

#endif

