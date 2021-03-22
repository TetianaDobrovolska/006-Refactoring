#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
	StringCalc();

	~StringCalc();
	
        long Add(std::string numbers);
        std::vector<int> parser(const std::string& input);

};

#endif

