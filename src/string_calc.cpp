#include "string_calc.hpp"
#include "normalization.hpp"
#include <vector>
#include <regex>
#include <numeric>
#include <tuple>
#include <iostream>

StringCalc::StringCalc()
{
}

StringCalc::~StringCalc()
{
}

std::string StringCalc::Normalization(const std::string &userInput)
{
	if(userInput.empty()){ return "";}
	std::vector<char> delimeters;
	std::string str = "";
	int delimeterCount = 0;
	const std::regex alphabet("[A-Za-z]+");
	if(std::regex_search(str, alphabet)) { throw std::invalid_argument("Wrong arguments");}
	tie(str, delimeters) = normalization::changeDelimeters(userInput);
	str = normalization::commasReduction(str);
	if(-1 != str.find(delimeters[1])) { throw std::invalid_argument("Wrong arguments");}
    return str;
}

int StringCalc::Add(std::string numbers)
{
	int sum_of_elems = 0;
	if(numbers.empty()){return sum_of_elems;}
 	std::string str = Normalization(numbers);
	if(!isdigit(str[0]) || !isdigit(str[str.length()-1])) { throw std::invalid_argument("Wrong arguments");}
	std::vector<int> vect;
	for(int i = 0; i != -1;) {
		static const std::regex regular("\\d+");
		std::string temp = str.substr(i, str.find(",", i+1));
    	std::regex_token_iterator<std::string::iterator> num( temp.begin(), temp.end(), regular);
    	std::string t = *num;
    	int elem = atoi( t.c_str() );
		i = str.find(",", i+1);
		if(MAX_LEN > elem) { vect.push_back(elem);}
		else { vect.push_back(0);}
	}
	sum_of_elems = std::accumulate(vect.begin(), vect.end(), 0);
	return sum_of_elems;
}
