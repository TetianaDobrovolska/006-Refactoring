#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cctype>
#include <set>

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(const std::string& input_str)
{
    if(!validateInputString(input_str)){
        throw std::invalid_argument("Not valid string!");
    }
    parseNumbers(input_str);

    int out = 0;
    for (auto number : numbers_) {
        int num = std::stoi(number);
        if (num <= UPPER_BOUND_){
            out += std::stoi(number);
        }
    }
    return out;//Not Implemented yet
}

bool StringCalc::validateInputString(const std::string& str){
    if(str.empty()){
        return true;
    }

    // lambda accepts parsed prefix str between "//" and "\n"
    auto check_prefix = [](const std::string& s) -> bool{
        if(s.empty()){
            return false;
        }
        if(s[0] == '['){
            auto pos = s.find(']');
            if(pos == std::string::npos){
                return false;
            }
            if(pos == 1){
                return false;
            }
        }
        return true;
    };

    //if string starts with "//" need to validate prefix up to \n
    auto pos = 0;
    if(str.find("//") == 0){
        pos = str.find('\n');
        if(pos == std::string::npos){
            return false;
        }
        auto begin_position = 2; // 1st char after //
        if(!check_prefix(str.substr(begin_position, pos - begin_position))){
            return false;
        };
        if(!std::isdigit(str[pos + 1])){
            return false;
        }
    }
    auto beg = parsePrefix(str);
    auto possibleChars = getAllPossibleChars();
    if(!std::isdigit(str[beg])){
        return false;
    }
    while (beg != std::string::npos){
        pos = str.find_first_of(possibleChars, beg);
        if (pos == -1){
            //last digit
            pos = str.size();
            if(str.substr(beg, pos - beg).find_first_not_of(digits_, 0) != std::string::npos){
                return false; // not a digit
            }
            return true;
        }
        if(str.substr(beg, pos - beg).find_first_not_of(digits_, 0) != std::string::npos){
            return false; // not a digit
        }
        beg = pos;
        pos = str.find_first_of(digits_, beg);
        if(delimiters_.count(str.substr(beg, pos - beg)) == 0){
            return false;
        }
        beg = pos;
    }
    return true;
}

void StringCalc::parseNumbers(const std::string& str){
    if(str.empty()){
        return;
    }
    auto pos = parsePrefix(str);
    auto allChars = getAllPossibleChars();
    auto beg = pos;
    while (beg != std::string::npos){
        pos = str.find_first_not_of(digits_, beg);
        if(pos == -1){
            pos = str.size();
        }
        numbers_.push_back(str.substr(beg, pos - beg));
        beg = str.find_first_of(digits_, pos);
    }
}

std::string StringCalc::getAllPossibleChars(){
    std::set<char> chars;
    for(const auto& str_delim: delimiters_){
        for(const auto ch: str_delim){
            chars.insert(ch);
        }
    }
    std::string result = "";
    for(const auto& i: chars){
        result.push_back(i);
    }
    return result;
}

int StringCalc::parsePrefix(const std::string &str){
    int begin_pos = 0;
    if (str.find("//") != 0){
        return begin_pos;
    }
    std::string delim = "";
    auto pos = str.find('\n');
    begin_pos += 2; // move over "//"
    delim = str.substr(begin_pos, pos - begin_pos);
    begin_pos = pos + 1; // next after found \n, will be return further

    if (delim.size() == 1){
        delimiters_.insert(delim);
        return begin_pos;
    }

    if (delim[0] == '['){
        pos = delim.find(']');
        delimiters_.insert(delim.substr(1, pos - 1));
    }
    pos += 1;
    while (pos < delim.size()) {
        delimiters_.insert(std::string(1, delim[pos]));
    }
    return begin_pos;

}
