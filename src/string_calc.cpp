#include "string_calc.hpp"
#include "utils.hpp"
#include <vector>
#include <algorithm>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

int StringCalc::Add(string numbers)
{
	if (numbers.length() == 0) {
		return 0;
	}

	string customDelimiterStr = RemoveCustomDelimiterFromInput(numbers);

	if (customDelimiterStr.length() > 1) {
		numbers = utils::replace(numbers, customDelimiterStr, ",");
		customDelimiterStr = ",";
	}
	char customDelimiter = customDelimiterStr[0];

	if (any_of(numbers.cbegin(), numbers.cend(), 
		[customDelimiter](char ch) { return !(ch == ',' ||
											  ch == '\n' ||
											  ch == customDelimiter ||
											  isdigit(ch)); 
		})) {
		throw std::invalid_argument("incorrect argument");
	}

	int acc = 0;
	auto beginIter = numbers.cbegin();
	auto endIter = beginIter;
	while (endIter != numbers.cend()) {
		endIter = find_if(beginIter, numbers.cend(),
			[customDelimiter](char ch) { return ch == ',' ||
												ch == '\n' ||
												ch == customDelimiter; 
			});
		int number = stoi(string(beginIter, endIter));
		if (number <= MAX_NUMBER) {
			acc += number;
		}
		beginIter = endIter + 1;
	}

	return acc;
}

string StringCalc::RemoveCustomDelimiterFromInput(string& numbers)
{
	const int LONG_DELIMITER_BEGIN_INDEX = 3;
	const int SHORT_DELIMITER_NUMBER_BEGIN_INDEX = 4;
	string customDelimiter = ",";

	if (numbers.find("//", 0) == 0) {
		if (auto endIndex = numbers.find("]", 0);
			numbers.find("//[", 0) == 0 &&
			endIndex > LONG_DELIMITER_BEGIN_INDEX &&
			endIndex != string::npos) {
			customDelimiter = numbers.substr(LONG_DELIMITER_BEGIN_INDEX, endIndex - LONG_DELIMITER_BEGIN_INDEX);
			numbers = string(numbers.cbegin() + endIndex + 2, numbers.cend());
		} else if (numbers[3] == '\n') {
			customDelimiter = numbers[2];
			numbers = string(numbers.begin() + SHORT_DELIMITER_NUMBER_BEGIN_INDEX, numbers.end());
		} else {
			throw std::invalid_argument("Invalid delimiter");
		}
	}
	return customDelimiter;
}
