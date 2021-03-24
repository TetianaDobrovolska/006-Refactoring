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
    bool hasPrefix(const std::string& str) const;
    void validate(const std::string& str) const;
    std::string convertNewlinesToDelimiters(const std::string& str) const;
    bool usesCustomDelimiter(std::string& str);
    std::vector<int> convertStringToIntVect(const std::string& str);

    char _delimiter;
};

#endif

