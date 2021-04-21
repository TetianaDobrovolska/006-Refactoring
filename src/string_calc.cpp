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
	
	if (any_of(numbers.cbegin(), numbers.cend(), [](char ch) { return !(ch == ',' || isdigit(ch)); })) {
		return -1;
	}

	int acc = 0;
	auto beginIter = numbers.cbegin();
	auto endIter = beginIter;
	while (endIter != numbers.cend()) {
		endIter = find_if(beginIter, numbers.cend(), [](char ch) { return ch == ','; });
		acc += stoi(string(beginIter, endIter));
		beginIter = endIter + 1;
	}

	return acc;
}
