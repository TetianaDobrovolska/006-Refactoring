#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
    static constexpr int kMaxNumber = 1000;

    StringCalc() = default;
    ~StringCalc() = default;

    int Add(const std::string& numbers);
private:
    bool IsValidity(const std::string& str);

    size_t AddDelims(const std::string& str);
    void RemoveDelims();

    void Digits(const std::string& str, std::vector<int>& digits);
    std::string::size_type FindFirstDelim(const std::string& str,
                                        std::vector<std::string>& delims,
                                        size_t offset,
                                        size_t& delim_pos);

    std::vector<std::string> delims {",", "\n"};
};

#endif

