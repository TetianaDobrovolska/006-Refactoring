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
	uint8_t sum = 0;
	if (numbers != "")
	{
		if (numbers.find_first_not_of("012,") == string::npos)
		{
			string delimiter = ",";
			auto deliPosition = numbers.find(delimiter);
			if (deliPosition == string::npos)
			{
				sum = stoi(numbers);
			}
			else
			{
				const uint8_t a = stoi(numbers.substr(0, 1));
				const uint8_t b = stoi(numbers.substr(deliPosition+1, 1));
				sum = a + b;
			}
		}
		else
		{
			return -1;
		}
	}
	

	return sum;
}
