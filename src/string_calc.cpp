#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

int convertToInt(string str) {
	if ("" == str)
		return -1;
	int number = 0;

	for(auto ch : str) {
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
	if ("" == numbers)
		return 0;
	std::vector<std::string> vect;
	int result = 0;
	
    std::string item;
	std::regex re("[\n,]");
	std::sregex_token_iterator first{numbers.begin(), numbers.end(), re, -1}, last;
	std::vector<std::string> tokens{first, last};
	for (auto t : tokens) {
		vect.push_back(t);
	}
	
	for (std::size_t i = 0; i < vect.size() and result != -1; i++) {
		int num = convertToInt(vect[i]);
		if(num >=0)
			result += num;
		else 
			result = -1;
	}
        
	return result;
}