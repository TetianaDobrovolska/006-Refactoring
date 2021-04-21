#include "string_calc.hpp"
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

	char customDelimiter = RemoveCustomDelimiterFromInput(numbers);

	if (any_of(numbers.cbegin(), numbers.cend(), 
		[customDelimiter](char ch) { return !(ch == ',' ||
											  ch == '\n' ||
											  ch == customDelimiter ||
											  isdigit(ch)); 
		})) {
		return -1;
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
		acc += stoi(string(beginIter, endIter));
		beginIter = endIter + 1;
	}

	return acc;
}

char StringCalc::RemoveCustomDelimiterFromInput(string& numbers)
{
	char customDelimiter = ',';

	if (numbers.rfind("//", 0) == 0 && numbers[3] == '\n') {
		customDelimiter = numbers[2];
		numbers = string(numbers.begin() + 4, numbers.end());
	}
	return customDelimiter;
}
