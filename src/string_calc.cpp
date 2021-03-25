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
    std::string delimeters = getSeparators(numbers);    

    for (int i; ss >> i;) {
        operands.push_back(i);    
        int val =  char(ss.peek());
        if (delimeters.find(val) != std::string::npos || val == '/')
            ss.ignore();

        if(i < 0)
            return -1;
    }

    for (std::size_t i = 0; i < operands.size(); i++)
        sum+= operands[i];

	return sum;
}

string StringCalc::getSeparators(string numbers)
{
    std::string delimeters = ",\n";
    if((numbers.length() > 3) && (numbers.substr(0, 2) == "//"))
    {
        auto endDelimeterindex = numbers.find_first_of('\n');
        delimeters = numbers.substr( 2, endDelimeterindex -2);
    }

    return delimeters+",\n";
}
