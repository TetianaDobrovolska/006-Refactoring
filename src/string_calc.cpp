#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <regex>
#include <numeric>
#include <iostream>

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

std::string StringCalc::Normalization(std::string str)
{
    size_t slash_pos = str.find("//");
	const std::regex alphabet("[A-Za-z]+");
	if(std::regex_search(str, alphabet)) { throw std::invalid_argument("Wrong arguments");}
	if(0 == slash_pos){
		std::string delimeter = "";
		char r;
		delimeter = str[slash_pos +2];
		std::map<char, char> rs = { {'\n', ','}, {delimeter[0], ','} };
		std::replace_if(str.begin(), str.end(), [&](char c){ return (rs.find(c) != rs.end())
                                                        && (r = rs[c]); }, r);
		int temp = 0;
		for(int i = 0; i < str.length(); i++){
			if(isdigit(str[i])) { temp = i; i = str.length();}
		}
		str = str.substr(temp, str.length()-1);
	}
	else {
		replace(str.begin(), str.end(), '\n', ',');
	}
	for(int i = 0; i < str.length(); i++){
		const std::regex notNumber("([0-9]+(%{2,}|\\|{2,}|,[^\\w\\s])+)+\
									|((%{2,}|\\|{2,}|,[^\\w\\s])+)+");
		bool regexResult = std::regex_search(str, notNumber);
		if(regexResult || !isdigit(str[0]) || !isdigit(str[str.length()-1])) { 
			throw std::invalid_argument("Wrong arguments");
		}
	}
    return str;
}

int StringCalc::Add(std::string numbers)
{
 	numbers = Normalization(numbers);
	int sum_of_elems = 0;
	if(numbers.empty()){return sum_of_elems;}
	else if(isalpha(numbers[0])) {return -1;}
	std::vector<int> vect;
	for(int i = 0; i != -1;) {
		static const std::regex regular("\\d+");
		std::string temp = numbers.substr(i, numbers.find(",", i+1));
    	std::regex_token_iterator<std::string::iterator> num( temp.begin(), temp.end(), regular);
    	std::string t = *num;
    	int elem = atoi( t.c_str() );
		i = numbers.find(",", i+1);
		if(1000 > elem) { vect.push_back(elem);}
		else { vect.push_back(0);}
	}
	sum_of_elems = std::accumulate(vect.begin(), vect.end(), 0);
	return sum_of_elems;
}
