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

    string alternative_delimiters {"\n"};
    regex custom_delimiter_section {"//(\\[(.+)\\]|.)\n"};

    string normalized_string = numbers;
    std::smatch match;
    if (regex_search(numbers, match, custom_delimiter_section)) {
        auto newDelimiter = match[2].str();
        alternative_delimiters += "|";
        if (newDelimiter.empty()) {
            auto sym = match[1].str().at(0);
            alternative_delimiters += isalpha(sym) ? "" : "\\";
            alternative_delimiters += match[1];
        } else {
            for (const auto sym : newDelimiter) {
                alternative_delimiters += isalpha(sym) ? "" : "\\";
                alternative_delimiters += sym;
            }
        }
        normalized_string.erase(0, static_cast<size_t>(match[0].length()));
    }

    int sum = 0;
    const string delimiter(1, default_delimiter);
    normalized_string = regex_replace(normalized_string, regex(alternative_delimiters), delimiter);

    auto tokens = split(normalized_string);

    for (auto token : tokens) {
        auto number = stoi(token);
        if (number < 0) {
            throw invalid_argument("negative");
        }
        if (number < 1001) {
            sum += number;
        }
    }

    return sum;
}
