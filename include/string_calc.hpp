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
	const int MAX_LEN = 1000;
	std::string Normalization(const std::string &userInput);
};

#endif

