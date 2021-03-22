#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


long StringCalc::Add(string numbers)
{
    std::stringstream ss(numbers);

    vector<int> values = parser(numbers);

    long sum = 0;

    for (auto& value : values) {
       if (value < 0) return -1;
       sum += value;
    }

    return sum;
}

std::vector<int> StringCalc::parser(const string &input)
{
    vector<int> output;
    std::stringstream ss(input);

    for (int i; ss >> i;) {
        output.push_back(i);
        if (ss.peek() == ',' || ss.peek() == '\n')
            ss.ignore();
    }

    return output;
}
