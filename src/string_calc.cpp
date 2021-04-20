#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cctype>

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(const std::string& numbers)
{
    auto result = parse(numbers);

    int out = 0;
    for (auto number : result) {
        if(!validate(number)){
            throw std::invalid_argument("Invalid number");
        }
        int num = std::stoi(number);
        if (!validate(num)){
            throw std::invalid_argument("Invalid number");
        }
        if (num <= 1000){
            out += std::stoi(number);
        }
    }
    return out;//Not Implemented yet
}

bool StringCalc::validate(const int &number){
    return number >= 0;
}

bool StringCalc::validate(const std::string &number){
    if(number.find_first_not_of(digits) != std::string::npos){
        return false;
    }
    return true;
}

std::vector<std::string> StringCalc::parse(const std::string& str){
    std::vector<std::string> result = {};

    parsePrefix(str);

    std::string::size_type beg, pos = 0;
    if(str.find("//") == 0){
       pos = str.find('\n') + 1;
       if (!std::isdigit(str[pos])){
           throw std::invalid_argument("not valid sring");
       }
    }
    if(str_delim != ""){
        while ( (beg = str.find_first_of(digits, pos)) != std::string::npos){
            pos = str.find_first_of(char_delims, beg + 1);
            auto pos2 = str.find(str_delim, beg + 1);
            if (pos == std::string::npos){
                pos = pos2;
            } else {
                pos = std::min(pos, pos2);
            }
            result.push_back(str.substr(beg, pos - beg));
        }
    } else {
        while ((beg = str.find_first_not_of(char_delims, pos)) != std::string::npos){
            pos = str.find_first_of(char_delims, beg + 1);
            result.push_back(str.substr(beg, pos - beg));
        }
    }

    return result;
}

void StringCalc::parsePrefix(const std::string &str){
    if (str.find("//") != 0){
        return;
    }
    std::string delim = "";
    auto pos = str.find('\n');
    if(pos != std::string::npos){
        const int begin = 2;
        delim = str.substr(begin, pos - begin);
    } else {
        return;
    }

    if(delim.size() == 0){
        return;
    }

    if (delim.size() == 1){
        char_delims.push_back(delim[0]);
        return;
    }

    if (delim.find('[') == 0 &&
        delim.find(']') == (delim.size() - 1) &&
        delim.size() > 2)
    {
        str_delim += delim.substr(1, delim.size() - 2);
        return;
    } else if(delim.find('[')==0 && delim.find(']') == std::string::npos) {
        return;
    }
    else
    {
        char_delims += delim;
        return;
    }

}
