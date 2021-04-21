#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <regex>
#include <iostream>

using namespace std;

namespace{
inline bool HasComment(const string& input){
	return 0 == input.find("//");
}

inline bool IsEmptyString(const string& str){
	return "" == str;
}
std::pair <string,string> CutCommentCutString(const string& input, const string& sep){
	int position = input.find(sep);
	return std::make_pair(input.substr(std::string("\\").length(), position - std::string("\\").length()), input.substr(position + sep.length()));
}
}

StringCalc::StringCalc(): m_defaultDelimiters("\n,")
						, m_additionalDelimiters("")
						, m_multDelimetr("")
{
}


StringCalc::~StringCalc()
{
}

int StringCalc::ConvertToInt(const string& str) {
	if (IsEmptyString(str))
		throw std::invalid_argument("Invalid. Empty string");
	int number = 0;

	for(auto ch : str) {
		int current_digit = ch - '0';
		if((current_digit < 0) or (current_digit > 9))
			throw std::invalid_argument("Invalid. Not number");
		number = (number * 10) + current_digit;	
	}
	if (number > MAX_NUMBER)
		number = 0;
	return number;
}

void StringCalc::GetRegEx(const string& input){
	if (IsEmptyString(input))
		return;
	if(0 == input.find("[")) {
		int comment_pos_end = input.find("]");
		if (comment_pos_end != std::string::npos) {
			string delim = input.substr(1, comment_pos_end - 1);
			std::string delimetrChar = delim.substr(0, 1);
			m_multDelimetr += "(\\" + delimetrChar + "{" + std::to_string(delim.length()) + "})|";
			GetRegEx(input.substr(comment_pos_end + 1));
		}
		else {
			m_additionalDelimiters += input.substr(0, 1);
			GetRegEx(input.substr(1));
		}
	}
	else {
		if("]" == input.substr(0, 1))
			m_additionalDelimiters += "\\";
		m_additionalDelimiters += input.substr(0, 1);
		GetRegEx(input.substr(1));
	}
}

int StringCalc::Add(const string& numbers)
{
	std::pair <string,string> input = std::make_pair(std::string(""), numbers);
	if (HasComment(numbers)) {
		input = CutCommentCutString(numbers, "\n");
		GetRegEx(input.first);
	}
	string delimString = m_multDelimetr + "[" + m_defaultDelimiters + m_additionalDelimiters + "]";
	std::regex re(delimString);
	
	if (IsEmptyString(input.second))
		return 0;
	
	std::sregex_token_iterator first{input.second.begin(), input.second.end(), re, -1}, last;
	std::vector<std::string> tokens{first, last};
	int result = 0;
	for (auto t : tokens) {
		int num = ConvertToInt(t);
		result += num;
	}
        
	return result;
}