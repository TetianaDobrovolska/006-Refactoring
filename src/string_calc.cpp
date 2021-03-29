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
        if (!all_of(token.begin(), token.end(), ::isdigit)) {
            throw invalid_argument("not a number");
        }
        tokens.push_back(token);
    }

    return tokens;
}

void StringCalc::parseDelimiters(const string& input_delimiters, string &regex_delimiters, bool multichar)
{
    for (const auto sym : input_delimiters) {
        regex_delimiters += multichar ? "" : "|";
        regex_delimiters += isalpha(sym) ? "" : "\\";
        regex_delimiters += sym;
    }
}

string StringCalc::processDelimiters(const string &input_string)
{
    const regex custom_delimiter_section {"//(\\[(.+)\\]|.+)\n"};
    string processed_string = input_string;
    string alternative_delimiters {"\n"};
    std::smatch match;

    enum {
        HEADER_SECTION_INDEX,
        DELIMITER_GROUP_INDEX,
        BRACKETS_GROUP_INDEX
    };

    if (regex_search(processed_string, match, custom_delimiter_section)) {
        if (match[HEADER_SECTION_INDEX].first != processed_string.cbegin()) {
            throw invalid_argument("wrong delimiters definition position");
        }
        const auto multichar_delimiter = match[BRACKETS_GROUP_INDEX].str();
        if (multichar_delimiter.empty()) {
            parseDelimiters(match[DELIMITER_GROUP_INDEX], alternative_delimiters, false);
        } else {
            alternative_delimiters += "|";
            parseDelimiters(multichar_delimiter, alternative_delimiters, true);
        }
        processed_string.erase(match[HEADER_SECTION_INDEX].first, match[HEADER_SECTION_INDEX].second);
    }

    const string delimiter(1, default_delimiter);
    processed_string = regex_replace(processed_string, regex(alternative_delimiters), delimiter);
    return processed_string;
}

int StringCalc::Add(const string &numbers)
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
