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
    std::vector<std::string> separators = allowed;

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

        std::string token;
        std::getline(is, token, '\n');
        if(token.size() == 1){
            separators = {token};
        } else {
            if(*token.begin() == '[' && token.back() == ']'){
                token = token.substr(1, token.size() - 2);
                separators = {token};
            } else {
                return {{}, false};
            }
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

        std::string val = "";
        char c;
        if(separators[0].size() == 1){
            c = is.peek();
            val.push_back(c);
            is.get();
        } else {
            for(uint i = 0; i < separators[0].size(); ++i){
                c = is.peek();
                if(c != separators[0][i]){
                    return {{}, false};
                }
                is.get();
            }
            val = separators[0];
        }
        if(find(separators.begin(), separators.end(), val) == separators.end()){
            result.second = false;
            return result;
        }
    }

}
