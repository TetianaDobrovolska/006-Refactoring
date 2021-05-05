#include "RookFigure.hpp"

RookFigure::RookFigure(const std::string& coord)
  : ChessFigure(coord)
{ }

RookFigure::~RookFigure()
{ }

bool RookFigure::Move(const std::string& nextCoord)
{
  return isCoordValid(nextCoord) &&
      (((nextCoord[0] != currentCoord[0]) &&
      (nextCoord[1] != currentCoord[1])) ||
      ((nextCoord[0] == currentCoord[0]) &&
      (nextCoord[1] == currentCoord[1]))) ? false : true;
}
