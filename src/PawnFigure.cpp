#include "PawnFigure.hpp"

PawnFigure::PawnFigure(const std::string& coord)
  : ChessFigure(coord)
{ }

PawnFigure::~PawnFigure()
{ }

bool PawnFigure::Move(const std::string& nextCoord)
{
  return isCoordValid(nextCoord) &&
      (nextCoord[0] != currentCoord[0] ||
      nextCoord[1] <= currentCoord[1] ||
      (nextCoord[1] - currentCoord[1] != 1 &&
      (nextCoord[1] != '4' ||
      currentCoord[1] != '2'))) ? false : true;
}
