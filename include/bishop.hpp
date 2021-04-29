#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <utility>
#include "figureCommon.hpp"

class Bishop : public FigureCommon
{
    Bishop(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual bool move(const char& positionAlphabet, const char& positionNumber);
};

#endif