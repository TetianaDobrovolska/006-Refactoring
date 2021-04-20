#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
	StringCalc() = default;

	~StringCalc() = default;

	int Add(const std::string& numbers);

private:
	std::string::size_type findFirstDelim(const std::string& str,
																				std::vector<std::string>& delims,
																				size_t offset);
	bool isDigit(const std::string& str);
};

#endif

