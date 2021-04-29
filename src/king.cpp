#include "king.hpp"

King::King(const char& positionAlphabet, const char& positionNumber, const int& color) :
    FigureCommon(positionAlphabet, positionNumber, color)
{
}

bool King::move(const char& positionAlphabet, const char& positionNumber) {
    return true;
}