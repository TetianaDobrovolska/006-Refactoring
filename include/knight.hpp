#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <utility>
#include "figureCommon.hpp"

class Knight : public FigureCommon
{
    Knight(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual bool move(const char& positionAlphabet, const char& positionNumber);
};

#endif