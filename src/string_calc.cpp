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
	if(str.empty()){ return "";}
    size_t slash_pos = str.find("//");
	const std::regex alphabet("[A-Za-z]+");
	std::vector delimeters {'\n', ' '};
	int delimeterCount = 0;
	if(std::regex_search(str, alphabet)) { throw std::invalid_argument("Wrong arguments");}
	if(0 == slash_pos){
		char delimeter;
		delimeter = str[slash_pos +2];
		int temp = 0;
		for(int i = 0; i < str.length(); i++){
			if(isdigit(str[i])) { 
				temp = i; i = str.length();
				if (str[slash_pos +2] == '[') { 
					delimeter = str[slash_pos +3];
					delimeterCount = temp-slash_pos-4;
				}
				else { delimeterCount = 1;}
			}
		}
		str = str.substr(temp, str.length()-1);
		delimeters[1] = delimeter;
	}

	for (const auto &value: delimeters) {
		int temp = 0;
		for (int i = 0; i < str.length(); i++) {
			const bool validateSymbol = ((str[i]==str[i+delimeterCount-1]) && (str[i]==str[i+1]));
			if ((value == delimeters[0] || 
				((value == delimeters[1] && validateSymbol) || 
				temp > 0)) || (delimeterCount == 1 && str[i] == value))
			{
				if (temp == 0) { temp = delimeterCount;}
				std::replace(str.begin()+i, str.begin()+i+1, value, ',');
				temp -= 1;
			}
		}
	}
	if (-1 != str.find(delimeters[1])) { std::cout << "IF" << std::endl;throw std::invalid_argument("Wrong arguments");}
	std::smatch result;
	const std::regex manyCommas("([,])\\1");
	for(int i = 0; i < std::regex_search(str, result, manyCommas);) {
		std::string temp1 = str.substr(0, result.position());
		std::string temp2 = str.substr(result.position(), str.length());
		std::smatch tempResult;
		std::regex_search(temp2, tempResult, manyCommas);
		temp2 = temp2.substr(tempResult.position()+tempResult.length(), temp2.length()-1);
		str = temp1 + temp2;
		if (std::regex_search(str, result, manyCommas) == 0) { i = 1;}
	}
	if(!isdigit(str[0]) || !isdigit(str[str.length()-1])) { throw std::invalid_argument("Wrong arguments");}
    return str;
}

int StringCalc::Add(std::string numbers)
{
 	numbers = Normalization(numbers);
	int sum_of_elems = 0;
	if(numbers.empty()){return sum_of_elems;}
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
