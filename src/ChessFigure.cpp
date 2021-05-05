#include "ChessFigure.hpp"

ChessFigure::ChessFigure(const std::string& coord)
  : currentCoord(coord)
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::isCoordValid(const std::string& coord)
{
  return coord[0] >= kFirstLetter &&
      coord[0] <= kLastLetter &&
      coord[1] >= kFirstDigit &&
      coord[1] <= kLastDigit;
}
