#include "QueenFigure.hpp"

QueenFigure::QueenFigure(const std::string& coord)
  : ChessFigure(coord)
{ }

QueenFigure::~QueenFigure()
{ }

bool QueenFigure::Move(const std::string& nextCoord)
{
  if(!isCoordValid(nextCoord))
    return false;
  const int dx = abs(nextCoord[0] - currentCoord[0]);
  const int dy = abs(nextCoord[1] - currentCoord[1]);
  return !(dx == dy ||
      nextCoord[0] == currentCoord[0] ||
      nextCoord[1] == currentCoord[1]) ? false : true;
}
