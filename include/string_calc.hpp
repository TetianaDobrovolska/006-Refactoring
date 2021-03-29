#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
	
    static int Add(const std::string& numbers);

private:
    StringCalc() = delete;
    ~StringCalc() = delete;
    static std::vector<std::string> split(const std::string& s);
    static std::string processDelimiters(const std::string& s);
    static void parseDelimiters(const std::string& input_delimiters, std::string& regex_delimiters, bool multichar);

    static const char default_delimiter = ',';
};

#endif

