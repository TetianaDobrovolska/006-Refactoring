#include "bishop.hpp"

Bishop::Bishop(const char& positionAlphabet, const char& positionNumber, const int& color) :
    FigureCommon(positionAlphabet, positionNumber, color)
{
}

bool Bishop::move(const char& positionAlphabet, const char& positionNumber) {
    return true;
}