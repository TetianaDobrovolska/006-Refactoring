#include "KnightFigure.hpp"

KnightFigure::KnightFigure(const std::string& coord)
  : ChessFigure(coord)
{ }

KnightFigure::~KnightFigure()
{ }

bool KnightFigure::Move(const std::string& nextCoord)
{
  if(!isCoordValid(nextCoord))
    return false;
  const int dx = abs(nextCoord[0] - currentCoord[0]);
  const int dy = abs(nextCoord[1] - currentCoord[1]);
  return !(dx == 1 && dy == 2 || dx == 2 && dy == 1) ? false : true;
}
