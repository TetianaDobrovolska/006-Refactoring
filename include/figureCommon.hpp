#ifndef FIGURE_COMMON_HPP
#define FIGURE_COMMON_HPP

#include <utility>

class FigureCommon 
{

public:
    FigureCommon(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual ~FigureCommon(){};
    virtual bool move(const char& positionAlphabet, const char& positionNumber) = 0;
    std::pair<char, char> getCoords();
    void setCoords(const char& positionAlphabet, const char& positionNumber);
    
private:
    char m_positionAlphabet;
    char m_positionNumber;
    int m_color;
};


#endif