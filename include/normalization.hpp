#ifndef NORMALIZATION
#define NORMALIZATION

#include <string>
#include <tuple>
#include <vector>

namespace normalization {
	std::tuple<std::string, std::vector<char>> changeDelimeters(const std::string &userInput);
    std::string commasReduction(const std::string &userInput);
}

#endif