#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP


#include <string>


class StringCalc

{
private:
	int const UPPER_LIMIT = 1000;
	int const LOWER_LIMIT = 0;

public:
	StringCalc();
	~StringCalc();	

	int Add(std::string numbers);

};

#endif

