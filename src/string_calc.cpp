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

void StringCalc::checkStringValidity(const string &str)
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
			throw std::invalid_argument("Invalid argument");		
	}
}

void StringCalc::checkCustomDeliminary(std::string &numbers)
{
	if((numbers.find("//") == 0) && (numbers.find("\n") == 3))
	{
		char customDeliminary = numbers[2];
		numbers.erase(0, 4);
		std::replace(numbers.begin(), numbers.end(), customDeliminary, ',');
	}
}

int StringCalc::sumValues(const std::string &numbers, const std::vector<int> &delimetersPositions)
{
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
		if(i < 1000)
		{
			summ +=i;
		}
	}

	return summ;
}

void StringCalc::calculateDelimetersPosition(const std::string &numbers, std::vector<int> &delimetersPositions)
{
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
					throw std::invalid_argument("Invalid argument");
			}
		}
	}
	else
		throw std::invalid_argument("Invalid argument");
			
}


int StringCalc::Add(string numbers)
{
	if(numbers.size() == 0)
		return 0;

	checkCustomDeliminary(numbers);
	
	std::replace(numbers.begin(), numbers.end(), '\n', ',');

	checkStringValidity(numbers);

	vector<int> delimetersPositions;

	calculateDelimetersPosition(numbers, delimetersPositions);

	if (delimetersPositions.empty())
	{
		return std::stoi(numbers);
	}

	int summ = sumValues(numbers, delimetersPositions);

	return summ;
}
