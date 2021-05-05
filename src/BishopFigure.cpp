#include "BishopFigure.hpp"

BishopFigure::BishopFigure(const std::string& coord)
  : ChessFigure(coord)
{ }

BishopFigure::~BishopFigure()
{ }

bool BishopFigure::Move(const std::string& nextCoord)
{
  return (isCoordValid(nextCoord) &&
      abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])) ? true : false;
}
