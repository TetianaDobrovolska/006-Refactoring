#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

using CalcArgs = std::pair<std::vector<int>, bool>;

class StringCalc
{
public:
	StringCalc();

	~StringCalc();
	
	int Add(std::string numbers);
private:
    CalcArgs parse(std::string str);
    const std::vector<std::string> allowed = {",", "\n"};
};

#endif

