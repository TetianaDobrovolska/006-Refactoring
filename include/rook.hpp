#ifndef ROOK_HPP
#define ROOK_HPP

#include <utility>
#include "figureCommon.hpp"

class Rook : public FigureCommon
{
public:
    Rook(const char& positionAlphabet, const char& positionNumber, const int& color);
    virtual bool move(const char& positionAlphabet, const char& positionNumber) override;
};

#endif