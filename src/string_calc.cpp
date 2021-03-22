#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
    std::vector<int> operands;
    std::stringstream ss(numbers);
    int sum = 0;

    for (int i; ss >> i;) {
        operands.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();

        if(i < 0)
            return -1;
    }

    if(operands.size() > 2) {
        return -1;
    }

    for (std::size_t i = 0; i < operands.size(); i++)
        sum+= operands[i];

	return sum;
}
