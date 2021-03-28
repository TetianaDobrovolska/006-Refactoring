#include "string_calc.hpp"
#include <algorithm>
#include <limits>
#include <sstream>

const int StringCalc::ERR_INVALID_ARGS;

bool StringCalc::ExtractOperands(const std::string& numbers, std::vector<int>& operands)
{
    if (numbers == "") {
        return ERR_INVALID_ARGS;
    }

    //TODO: remove spaces and check extra chars

    std::stringstream ss{numbers};
    int operand;

    while (!ss.eof()) {
        // skip the delimiters
        // note: some escaped characters (\r, \t, \f, \n) and spaces are automatically removed by
        // the std::stringstream extraction operator >>
        for (char del : LEGAL_DELIMITERS) {
            while (ss.peek() == del)
                ss.ignore();
        }

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
