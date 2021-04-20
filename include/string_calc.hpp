#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
	StringCalc();

	~StringCalc();
	
    int Add(const std::string &numbers);
private:
    std::vector<std::string> parse(const std::string& str);
    void parsePrefix(const std::string& str);
    bool validate(const int& number);
    bool validate(const std::string& number);

    std::string char_delims = ",\n";
    std::string str_delim = "";
    std::string digits = "0123456789";
};

#endif

