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
        throw std::invalid_argument("Wrong arguments");
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
    std::vector<char> separators = allowed;

    char prefix = is.peek();
    if(prefix == EOF){
        result.second = true;
        return result;
    }
    if(prefix == '/'){
        is.get(prefix);
        is.get(prefix);
        if(prefix != '/'){
            return {{}, false};
        }
        is.get(prefix);
        separators = {prefix};
        is.get(prefix);
        if(prefix != '\n'){
            return {{}, false};
        }
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

        if(nextNumber <= 1000){
            result.first.push_back(nextNumber);
        }

        if(is.peek() == EOF){
            result.second = true;
            return result;
        }
        char c = is.peek();
        if(find(separators.begin(), separators.end(), c) == separators.end()){
            result.second = false;
            return result;
        }
        is.get();
    }

}
