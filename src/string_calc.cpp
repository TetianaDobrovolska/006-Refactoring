#include "string_calc.hpp"
#include <algorithm>
#include <limits>
#include <sstream>

const int StringCalc::ERR_INVALID_ARGS;

void StringCalc::ParseDelimiterDirective(const std::string& numbers, std::function<void(int)> f)
{
    // directive format: "//x\n" where x is the delimiter char
    if (numbers.length() < 4)
        return;

    std::string twoSlashes(numbers, 0, 2);

    if (twoSlashes == "//" && numbers[3] == '\n') {
        char delimiter = numbers[2];
        f(delimiter);
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

    ParseDelimiterDirective(numbers, [this, &ss](int i){ m_delimiters.push_back(i); ss.ignore(4); });

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
        operands.push_back(operand);
    }
    return true;
}

int StringCalc::Add(const std::string& numbers)
{
    std::vector<int> operands;
    if (!ExtractOperands(numbers, operands)) {
        return ERR_INVALID_ARGS;
    }

    long sum = 0;
    for (int val : operands) {
        if (val < 0)
            return ERR_INVALID_ARGS;
        sum += val;
    }

    if ((sum < 0) || (sum > static_cast<long>(std::numeric_limits<int>::max()))) {
        return ERR_INVALID_ARGS;
    }
    return static_cast<int>(sum);
}
