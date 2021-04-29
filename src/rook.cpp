#include "rook.hpp"

Rook::Rook(const char& positionAlphabet, const char& positionNumber, const int& color) :
    FigureCommon(positionAlphabet, positionNumber, color)
{
}

bool Rook::move(const char& positionAlphabet, const char& positionNumber) {
    std::pair<char, char> currenCoords = getCoords();
    if (currenCoords.first == positionAlphabet || currenCoords.second == positionNumber) {
        setCoords(positionAlphabet, positionNumber);
        return true;
    }
    return false;
}