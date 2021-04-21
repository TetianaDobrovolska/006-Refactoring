#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool ParseInputString(const string&, vector<int>&);

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(const string& numbers)
{
	vector<int> arguments;

	bool correct_arguments = ParseInputString(numbers, arguments);

	if (correct_arguments == 0)
	{
		return -1;
	}

	int sum = 0;
	for (const int& argument : arguments)
	{
		sum += argument;
	}
	return sum;
}


bool ParseInputString(const string& source_string, vector<int>& arguments) {
	const size_t string_size = source_string.size();

	if (string_size == 0)
	{
		arguments.push_back(0);
		return 1;
	}

	string part_of_string;
	int position = 0;

	for (const auto& later : source_string) {
		if (later != ',')
		{
			if (!isdigit(later))
			{
				return 0;
			}

			part_of_string += later;

			if (position == string_size -1)
			{
				arguments.push_back(stoi(part_of_string));
				return 1;
			}
		}
		else if (part_of_string.empty())
		{
			return 0;
		}
		else
		{
			arguments.push_back(stoi(part_of_string));
			part_of_string = "";
		}
		position++;
	}

	return 0;

}