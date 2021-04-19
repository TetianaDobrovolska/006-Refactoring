#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cctype>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
    int out = 0;
    auto result = parse(numbers);
    if (!result.second){
        return -1;
    }
    for (auto number : result.first) {
        out += number;
    }
    return out;//Not Implemented yet
}

CalcArgs StringCalc::parse(std::string str){
    CalcArgs result = {{}, false};

    int nextNumber = 0;
    std::istringstream is(str);
    if(is.peek() == EOF){
        result.second = true;
        return result;
    }
    while(true){
        if(!std::isdigit(is.peek())){
            result.second = false;
            return result;
        }

        is >> nextNumber;
        if (nextNumber < 0){
            result.second = false;
            return result;
        }
        if (result.first.size() < 3){
            result.first.push_back(nextNumber);
        } else {
            result.second = false;
            return result;
        }
        if(is.peek() == EOF){
            result.second = true;
            return result;
        }
        if(is.peek() != ','){
            result.second = false;
            return result;
        }
        is.get();
    }

}
