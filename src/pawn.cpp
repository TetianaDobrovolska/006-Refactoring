#include "pawn.hpp"

Pawn::Pawn(const char& positionAlphabet, const char& positionNumber, const int& color) :
    FigureCommon(positionAlphabet, positionNumber, color)
{
}

bool Pawn::move(const char& positionAlphabet, const char& positionNumber) {
    return true;
}