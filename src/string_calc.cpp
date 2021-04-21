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

bool StringCalc::checkStringValidity(const string &str)
{
	const char validSymbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ','};
	
	for (size_t i = 0; i < str.size(); i++)
	{
		bool found = false;

		for (char ch : validSymbols)
		{
			if(str[i] == ch)
				found = true;
		}

		if (!found)
			return false;		
	}
	return true;	
}


int StringCalc::Add(string numbers)
{
	if(numbers.size() == 0)
		return 0;
	
	if (checkStringValidity(numbers) == false)
		return -1;

	vector<int> delimetersPositions;
	int lastIndex = numbers.size() -1;

	if((numbers[0] != ',') && (numbers[lastIndex] != ','))
	{
		for (size_t i = 0; i < numbers.size(); i++)
		{
			if(numbers[i] == ',')
			{
				if(numbers[i+1] != ',')
					delimetersPositions.push_back(i);
				else
					return -1;
			}
		}
	}
	else
		return -1;
		
	if (delimetersPositions.empty())
	{
		return std::stoi(numbers);
	}

	vector<int> nums;
	string tmp;

	nums.push_back(std::stoi(numbers.substr(0, delimetersPositions[0])));

	for (size_t i = 0; i < delimetersPositions.size(); i++)
	{
		if (i + 1 < delimetersPositions.size())
		{
			tmp = numbers.substr(delimetersPositions[i]+1);
		}
		else
		{
			int len = delimetersPositions[i+1] - (delimetersPositions[i] + 1);
			tmp = numbers.substr(delimetersPositions[i]+1, len);
		}
		nums.push_back(std::stoi(tmp));
	}
	
	int summ = 0;

	for (auto &i : nums)
	{
		summ +=i;
	}
	
//	int a = std::stoi(numbers.substr(0, delimetersPositions[0]));
//	int b = std::stoi(numbers.substr(delimetersPositions[0]+1));

	return summ;
}
