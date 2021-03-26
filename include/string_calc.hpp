#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
    StringCalc();

	~StringCalc();
	
    int Add(const std::string& numbers) const;

private:
    std::vector<std::string> split(const std::string& s) const;
    std::string processDelimiters(const std::string& s) const;
    void parseDelimiters(const std::string input_delimiters, std::string& regex_delimiters, bool multichar) const;

    const char default_delimiter = ',';
};

#endif

