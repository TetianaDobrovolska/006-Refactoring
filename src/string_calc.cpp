#include "string_calc.hpp"
#include <algorithm>
#include <limits>
#include <sstream>

const int StringCalc::MAX_OPERAND_VALUE;

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

    long sum = 0;
    for (int val : operands) {
        if (val < 0)
            throw std::invalid_argument("Negative operand");
        sum += val;
    }

    if ((sum < 0) || (sum > static_cast<long>(std::numeric_limits<int>::max()))) {
        throw std::invalid_argument("Operands have invalid size");
    }
    return static_cast<int>(sum);
}
