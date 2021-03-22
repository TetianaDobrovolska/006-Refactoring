#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
	StringCalc();
	~StringCalc();

	int Add(std::string numbers);
private:
    bool hasNegatives(const std::string& str);
    std::vector<int> convertStringToIntVect(const std::string& str);
    bool moreThanTwoOperands(const std::vector<int>& vec);
};

#endif

