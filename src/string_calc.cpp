#include "string_calc.hpp"
#include <algorithm>
#include <limits>
#include <sstream>
#include <regex>

const int StringCalc::MAX_OPERAND_VALUE;

void StringCalc::ParseDelimiterDirective(const std::string& numbers, std::stringstream& ss)
{
    // Directive format:
    // "//[<delimiters>]\n"
    //  where <delimiters> is a sequence of one or more chars
    //
    // 1. validate the full directive syntax
    // 2. extract the delimiters inside the group [...] by skippng the initial //[ and final ] char
    // 3. skip the directive in the sstream

    std::smatch directiveString;

    if (std::regex_search(numbers, directiveString, std::regex("^//\\[.+\\]\n"))) {
        for (int i = 3; i < directiveString.length() - 2; i++) {
            m_delimiters.push_back(directiveString.str()[i]);
        }
        ss.ignore(directiveString.length());
    }
}

bool StringCalc::ExtractOperands(const std::string& numbers, std::vector<int>& operands)
{
    // empty string returns 0
    if (numbers == "") {
        operands.push_back(0);
        return true;
    }

    std::stringstream ss{numbers};

    ParseDelimiterDirective(numbers, ss);

    while (!ss.eof()) {
        // skip the delimiters
        // note: some escaped characters (\r, \t, \f, \n) and spaces are automatically removed by
        // the std::stringstream extraction operator >>
        for (char del : m_delimiters) {
            while (ss.peek() == del)
                ss.ignore();
        }

        int operand;
        ss >> operand;
        if (ss.fail()) {
            return false;
        }

        operands.push_back(operand <= MAX_OPERAND_VALUE ? operand : 0);
    }
    return true;
}

int StringCalc::Add(const std::string& numbers)
{
    std::vector<int> operands;
    if (!ExtractOperands(numbers, operands)) {
        throw std::invalid_argument("Invalid operand");
    }

    int sum = 0;
    for (int val : operands) {
        if (val < 0)
            throw std::invalid_argument("Negative operand");
        sum += val;
    }

    return sum;
}
