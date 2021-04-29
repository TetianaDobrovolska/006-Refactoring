#ifndef PAWN_HPP
#define PAWN_HPP

#include <utility>
#include "figureCommon.hpp"

class Pawn : public FigureCommon
{
    Pawn(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual bool move(const char& positionAlphabet, const char& positionNumber);
};

#endif