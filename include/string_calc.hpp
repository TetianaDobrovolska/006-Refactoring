#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>

class StringCalc
{
private:
	bool checkStringValidity(const std::string &);

public:
	StringCalc();

	~StringCalc();

	int Add(std::string numbers);
};

#endif

