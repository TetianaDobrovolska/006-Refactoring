#include "KingFigure.hpp"

KingFigure::KingFigure(const std::string& coord)
  : ChessFigure(coord)
{ }

KingFigure::~KingFigure()
{ }

bool KingFigure::Move(const std::string& nextCoord)
{
  return (isCoordValid(nextCoord) &&
      !(abs(nextCoord[0] - currentCoord[0]) <= 1 &&
        abs(nextCoord[1] - currentCoord[1]) <= 1)) ? false : true;
}
