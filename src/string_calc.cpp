#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <regex>

using namespace std;

vector<string> StringCalc::split(const std::string& s) const
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

string StringCalc::processDelimiters(const string &input_string) const
{
    const regex custom_delimiter_section {"//(\\[(.+)\\]|.)\n"};
    string processed_string = input_string;
    string alternative_delimiters {"\n"};
    std::smatch match;

    enum {
        HEADER_SECTION_INDEX,
        DELIMITER_GROUP_INDEX,
        BRACKETS_GROUP_INDEX
    };

    if (regex_search(input_string, match, custom_delimiter_section)) {
        const auto newDelimiter = match[BRACKETS_GROUP_INDEX].str();
        alternative_delimiters += "|";
        if (newDelimiter.empty()) {
            const auto sym = match[DELIMITER_GROUP_INDEX].str().at(0);
            alternative_delimiters += isalpha(sym) ? "" : "\\";
            alternative_delimiters += match[DELIMITER_GROUP_INDEX];
        } else {
            for (const auto sym : newDelimiter) {
                alternative_delimiters += isalpha(sym) ? "" : "\\";
                alternative_delimiters += sym;
            }
        }
        processed_string.erase(0, static_cast<size_t>(match[HEADER_SECTION_INDEX].length()));
    }

    const string delimiter(1, default_delimiter);
    processed_string = regex_replace(processed_string, regex(alternative_delimiters), delimiter);
    return processed_string;
}

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

int StringCalc::Add(const string &numbers) const
{
    if (numbers.empty()) {
        return 0;
    }

    int sum = 0;
    const string normalized_string = processDelimiters(numbers);
    const auto tokens = split(normalized_string);

    for (auto token : tokens) {
        const auto number = stoi(token);
        if (number < 0) {
            throw invalid_argument("negative");
        }
        if (number < 1001) {
            sum += number;
        }
    }

    return sum;
}
