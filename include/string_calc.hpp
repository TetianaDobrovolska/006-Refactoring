#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
private:
	void checkStringValidity(const std::string &);
	void checkCustomDeliminary(std::string &);
	int sumValues(const std::string &, const std::vector<int> &);
	void calculateDelimetersPosition(const std::string &, std::vector<int> &);

public:
	StringCalc();

	~StringCalc();

	int Add(std::string numbers);
};

#endif

