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
		if (numbers.find_first_not_of("0123456789,") == string::npos)
		{
			string delimiter = ",";
			auto deliPosition = numbers.find(delimiter);
			if (deliPosition == string::npos)
			{
				sum = stoi(numbers);
			}
			else
			{
				size_t start;
				size_t end = 0;

				while ((start = numbers.find_first_not_of(delimiter, end)) != std::string::npos)
				{
					end = numbers.find(delimiter, start);
					sum += stoi(numbers.substr(start, end - start));
				}
			}
		}
		else
		{
			return -1;
		}
	}
	

	return sum;
}
