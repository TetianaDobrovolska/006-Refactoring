#ifndef KING_HPP
#define KING_HPP

#include <utility>
#include "figureCommon.hpp"

class King : public FigureCommon
{
    King(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual bool move(const char& positionAlphabet, const char& positionNumber);
};

#endif