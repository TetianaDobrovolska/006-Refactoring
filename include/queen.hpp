#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <utility>
#include "figureCommon.hpp"

class Queen : public FigureCommon
{
    Queen(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual bool move(const char& positionAlphabet, const char& positionNumber);
};

#endif