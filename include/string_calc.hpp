#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>
#include <set>

class StringCalc
{
public:
	StringCalc();

	~StringCalc();
	
    int Add(const std::string &input_str);
private:
    void parseNumbers(const std::string& str);
    int parsePrefix(const std::string& str);
    bool validateInputString(const std::string& str);
    std::string getAllPossibleChars();

    std::vector<std::string> numbers_ = {};
    std::set<std::string> delimiters_ = {",", "\n"};
    std::string digits_ = "0123456789";
    const int UPPER_BOUND_ = 1000;
};

#endif

