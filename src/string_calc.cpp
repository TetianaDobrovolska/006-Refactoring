#include "string_calc.hpp"

namespace {

constexpr int kMaxCount = 2;
constexpr int kInvalidValue = -1;

}  //namespace

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(const std::string& numbers)
{
    int sum = 0;
    int count = 0;
    for (auto s : numbers) {
        if (std::isdigit(s)) {
            sum += s - '0';
            count++;
        }
    }
    return kMaxCount >= count ? sum : kInvalidValue;
}
