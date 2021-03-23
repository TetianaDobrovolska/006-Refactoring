#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>

class StringCalc
{
public:
    StringCalc();

    ~StringCalc();

    int Add(std::string numbers);

private:
    int convertToIntHelper(std::string token);
    const std::string delimiter = ",";
};

#endif

