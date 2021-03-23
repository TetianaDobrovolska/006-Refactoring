#include "string_calc.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

StringCalc::StringCalc()
{
    defaultDelimiters.push_back(",");
    defaultDelimiters.push_back("\n");
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
    int result = 0;
    size_t pos = 0;
    string token;

    try {
        string delimiter = "";
        string inputStr = "";
        auto parsedDelimiter = parseDelimiter(numbers, inputStr);
        while ((pos = nextDelimiterPosition(inputStr, parsedDelimiter, delimiter)) != string::npos) {
            token = inputStr.substr(0, pos);
            result += convertToIntHelper(token);
            inputStr.erase(0, pos + delimiter.length());
        }
        result += convertToIntHelper(inputStr);
    }
    catch (invalid_argument e1) {
        throw e1;
    }
    catch (exception& e2) {
        cerr << "exception caught: " << e2.what() << '\n';
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
    else if (parsedNum > 1000) {
        parsedNum = 0;
    }
    return parsedNum;
}

size_t StringCalc::nextDelimiterPosition(string inputStr, vector<string> delimiters, string &foundDelimiter)
{
    size_t ret = string::npos;
    for (int i = 0; i < delimiters.size(); i++) {
        auto pos = inputStr.find(delimiters[i]);
        if (pos < ret) {
            ret = pos;
            foundDelimiter = delimiters[i];
        }
    }
    return ret;
}

vector<string> StringCalc::parseDelimiter(string inputStr, string &stringForCalc)
{
    vector<string> ret = defaultDelimiters;
    stringForCalc = inputStr;

    /// To have custom delimiter, length should bigger than 3 letters '/','/', and '\n'
    if (inputStr.length() > 3 && inputStr[0] == '/' && inputStr[1] == '/') {
        auto pos = inputStr.find('\n');
        if (pos != string::npos) {
            string delimiter = inputStr.substr(2, pos - 2);
            ret.clear();
            ret.push_back(delimiter);
            stringForCalc = inputStr.substr(pos + 1, inputStr.length());
        }
    }

    return ret;
}

