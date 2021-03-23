#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
    StringCalc(const char delimiter = ',');

	~StringCalc();
	
    int Add(const std::string& numbers);

private:
    std::vector<std::string> split(const std::string& s);

    const char m_delimiter;
};

#endif

