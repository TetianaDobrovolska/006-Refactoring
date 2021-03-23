#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <regex>

using namespace std;

vector<string> StringCalc::split(const std::string& s)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);

   while (getline(tokenStream, token, default_delimiter))
   {
      tokens.push_back(token);
   }

   return tokens;
}

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

int StringCalc::Add(const string &numbers)
{
    if (numbers.empty()) {
        return 0;
    }

    regex alternative_delimiters("\n");
    string delimiter(1, default_delimiter);
    string normalized_string = regex_replace(numbers, alternative_delimiters, delimiter);

    auto tokens = split(normalized_string);

    int sum = 0;
    try {
        for (auto token : tokens) {
            auto number = stoi(token);
            if (number < 0) {
                return -1;
            }
            sum += number;
        }
    }  catch (...) {
        return -1;
    }
    return sum;
}
