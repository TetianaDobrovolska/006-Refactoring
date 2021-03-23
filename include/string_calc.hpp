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
    bool hasNegatives(const std::string& str) const;
    std::string convertNewlinesToDelimiters(const std::string& str) const;
    std::vector<int> convertStringToIntVect(const std::string& str) const;

    static inline const char _delimiter = ',';
};

#endif

