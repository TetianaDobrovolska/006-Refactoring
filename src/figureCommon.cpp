#include "figureCommon.hpp"
#include <utility>

FigureCommon::FigureCommon(const char& positionAlphabet, const char& positionNumber, const int& color) :
        m_positionAlphabet(positionAlphabet), m_positionNumber(positionNumber), m_color(color)
{
}

void FigureCommon::setCoords(const char& positionAlphabet, const char& positionNumber) {
    m_positionAlphabet = positionAlphabet;
    m_positionNumber = positionNumber;
}

std::pair<char, char> FigureCommon::getCoords() {
    std::pair<char, char> tempCoords {m_positionAlphabet, m_positionNumber};
    return tempCoords;
}