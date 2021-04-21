#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>

class StringCalc
{
public:
    StringCalc();

	~StringCalc();
	
    int Add(const std::string& numbers);

private:
    bool validity(const std::string& numbers);

    const char m_defaultDelimiter = ',';
};

#endif
