#include "normalization.hpp"
#include <string>
#include <vector>
#include <regex>
#include <numeric>
#include <tuple>
#include <iostream>

namespace normalization {
    std::tuple<std::string, std::vector<char>> changeDelimeters(const std::string &userInput){
        std::string str = userInput;
        std::vector<char> delimeters {'\n', ' '};
        std::string serviceSymbols = "//";
        size_t slashPos = str.find(serviceSymbols);
        int delimeterCount = 0;
	    if(0 == slashPos){
	    	char delimeter;
	    	delimeter = str[serviceSymbols.length()];
	    	int temp = 0;
	    	for(int i = 0; i < str.length(); i++){
	    		if(isdigit(str[i])) { 
	    			temp = i; i = str.length();
	    			if (str[serviceSymbols.length()] == '[') { 
	    				delimeter = str[serviceSymbols.length()+1];
	    				delimeterCount = temp-slashPos-4;
	    			}
	    			else { delimeterCount = 1;}
	    		}
	    	}
	    	str = str.substr(temp, str.length()-1);
	    	delimeters[1] = delimeter;
	    }

	    for (const auto &value: delimeters) {
	    	int temp = 0;
	    	for (int i = 0; i < str.length(); i++) {
	    		const bool validateSymbol = ((str[i]==str[i+delimeterCount-1]) && (str[i]==str[i+1]));
	    		if ((value == delimeters[0] || 
	    			((value == delimeters[1] && validateSymbol) || 
	    			temp > 0)) || (delimeterCount == 1 && str[i] == value))
	    		{
	    			if (temp == 0) { temp = delimeterCount;}
	    			std::replace(str.begin()+i, str.begin()+i+1, value, ',');
	    			temp -= 1;
	    		}
	    	}
	    }
        return std::make_tuple(str, delimeters);
    }

    std::string commasReduction(const std::string &userInput){
        std::string str = userInput;
        std::smatch result;
	    const std::regex manyCommas("([,])\\1");
	    for(int i = 0; i < std::regex_search(str, result, manyCommas);) {
		    std::string temp1 = str.substr(0, result.position());
		    std::string temp2 = str.substr(result.position(), str.length());
    		std::smatch tempResult;
	    	std::regex_search(temp2, tempResult, manyCommas);
		    temp2 = temp2.substr(tempResult.position()+tempResult.length(), temp2.length()-1);
		    str = temp1 + temp2;
		    if (std::regex_search(str, result, manyCommas) == 0) { i = 1;}
	    }
        return str;
    }
}