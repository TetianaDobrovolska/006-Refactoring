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
    ///// Algorithm description
    // 1. Separate Delimiters definition and string for calculation by calling "parseDelimiter".
    //    If no custom delimiter, defaultDelimiters is returned.
    // 2. Get the nearest position of any delimiter by calling "nextDelimiterPosition"
    //    If multiple delimiters are detected at same position, the longest one is set.
    // 3. Get and parse the number from beginning to detected delimiter position (from step 2).
    //    convertToIntHelper is used to handle ignorance or exceptions as requirements.
    /////

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
        if (pos <= ret) {
            ret = pos;
            if (delimiters[i].length() > foundDelimiter.length()) {
	        foundDelimiter = delimiters[i];
            }
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
            string delimiterDefinitionStr = inputStr.substr(2, pos - 2);
            ret.clear();

            ret = parseDelimiterDefinition(delimiterDefinitionStr);
            stringForCalc = inputStr.substr(pos + 1, inputStr.length());
        }
    }

    return ret;
}

vector<string> StringCalc::parseDelimiterDefinition(string inputDelimiterDefinition)
{
    vector<string> delimiters;
    string currentDelimiterString = "";
    for (int i = 0; i < inputDelimiterDefinition.length(); i++) {
        // If the current character is '[' and not at the end of the string
        // If it is at the end of the string, treat it as a delimiter
        // (we also can throw exception)
        if (inputDelimiterDefinition[i] == '[' && i != inputDelimiterDefinition.length() - 1) {
            string stringFromOpenBracket = inputDelimiterDefinition.substr(i + 1);
            auto closeBracketPos = stringFromOpenBracket.find(']');
            if (closeBracketPos != string::npos) {
                currentDelimiterString = stringFromOpenBracket.substr(0, closeBracketPos);
                i = closeBracketPos; // skip to next character after close bracket position
            }
            else {
                // If cannot find close bracket, treat the current open bracket as a delimiter
                // (we also can throw exception here)
                currentDelimiterString = inputDelimiterDefinition[i];
            }
        }
        else {
            currentDelimiterString = inputDelimiterDefinition[i];
        }
        delimiters.push_back(currentDelimiterString);
    }
    return delimiters;
}

