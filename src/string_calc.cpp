#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

StringCalc::StringCalc()
{
}

StringCalc::~StringCalc()
{
}

int StringCalc::ConvertOperand(std::string operand)
{
    int result = 0;

    // empty string interpreted as 0
    if (!operand.length())
        return result;
    try {
        result = std::stoi(operand);
    }
    catch(const std::out_of_range&) {
        return ERR_INVALID_ARGS;
    }
    catch(const std::invalid_argument&) {
        return ERR_INVALID_ARGS;
    }
    // negative numbers not allowed
    if (result < 0)
        return ERR_INVALID_ARGS;

    return result;
}

int StringCalc::Add(std::string numbers)
{
    int result = 0;

    size_t commaPos = numbers.find(',');

    // single operand (no comma)
    if (commaPos == std::string::npos) {
        return ConvertOperand(numbers);
    }
    // multiple operands (2 for now)
    else {
        std::string op1str = numbers.substr(0, commaPos);
        std::string op2str = numbers.substr(commaPos + 1);
        int op1 = ConvertOperand(op1str);
        int op2 = ConvertOperand(op2str);

        if (op1 == ERR_INVALID_ARGS || op2 == ERR_INVALID_ARGS) {
            return ERR_INVALID_ARGS;
        }
        // sum of half ints leads to int overflow
        const int halfInt = std::numeric_limits<int>::max() / 2;
        if (op1 > halfInt && op2 > halfInt) {
            return ERR_INVALID_ARGS;
        }
        result = op1 + op2;
    }

    return result;
}
