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
	void GetRegEx(const std::string& input);
	int ConvertToInt(const std::string& str);
	
	std::string m_defaultDelimiters;
	std::string m_additionalDelimiters;
	std::string m_multDelimetr;
	
	static const int MAX_NUMBER = 1000;
};

#endif

