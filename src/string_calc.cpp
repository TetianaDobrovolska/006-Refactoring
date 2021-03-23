#include "string_calc.hpp"
#include <iostream>
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
    string inputStr = numbers;
    int result = 0;

    size_t pos = 0;
    string token;

    try {
        while ((pos = inputStr.find(delimiter)) != string::npos) {
            token = inputStr.substr(0, pos);
            result += convertToIntHelper(token);
            inputStr.erase(0, pos + delimiter.length());
        }
        result += convertToIntHelper(inputStr);
    } catch (exception& e) {
        cerr << "exception caught: " << e.what() << '\n';
        result = -1;
    }

    return result;
}

int StringCalc::convertToIntHelper(string token)
{
    //cout << token << endl;

    // remove space
    token.erase(token.begin(), find_if(token.begin(), token.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));

    // empty string has value 0
    if (token.length() == 0) {
        return 0;
    }

    auto foundNonDigit = find_if(token.begin(), token.end(), [](unsigned char ch) {
        return (!isspace(ch) && !isdigit(ch)) && ch != '-';
    });

    if (foundNonDigit != end(token)) {
        throw invalid_argument("Contains non-digit character");
    }

    // Convert to int
    int parsedNum = stoi(token);
    if (parsedNum < 0) {
        throw out_of_range("Must bigger than 0");
    }
    return parsedNum;
}

