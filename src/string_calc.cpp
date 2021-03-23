#include "string_calc.hpp"
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> StringCalc::split(const std::string& s)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);

   while (getline(tokenStream, token, m_delimiter))
   {
      tokens.push_back(token);
   }

   return tokens;
}

StringCalc::StringCalc(const char delimiter)
    : m_delimiter(delimiter)
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

    auto tokens = split(numbers);
    auto n = tokens.size();
    if(n < 1 || n > 2) {
        return -1;
    }

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
