#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
	StringCalc();
	~StringCalc();

    int add(const std::string& numbers);

private:
    void parsePrefix(std::string &str, std::string &custom_delimiter) const;
    std::string validate(const std::string& str) const;
    void convertPatternToDelimiter(const std::string& pattern, std::string &str) const;
    std::vector<int> convertStringToIntVect(const std::string& str);

    char _delimiter;
    std::string _prefix_start;
    std::string _prefix_end;
    static const int OPERAND_UPPER_LIMIT = 1000;
};

#endif

