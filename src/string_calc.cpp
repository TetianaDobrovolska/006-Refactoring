#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

int convertToInt(string string) {
	int number = 0;

	for(auto ch : string) {
		int num = ch - '0';
		if((num >= 0)and(num <=9))
			number = (number * 10) + num;
		else
			return -1;
	}
	return number;
}

int StringCalc::Add(string numbers)
{
	std::vector<std::string> vect;
	std::stringstream ss(numbers);
	int result = 0;
	
    std::string item;
	while (std::getline(ss, item, ',')) {
		vect.push_back(item);
	}
	
	if(vect.size() > 2)
		result = -1;

    for (std::size_t i = 0; i < vect.size() and result != -1; i++) {
		int num = convertToInt(vect[i]);
		if(num >=0)
			result += num;
		else 
			result = -1;
	}
        
	return result;
}