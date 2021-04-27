#include "QueenFigure.hpp"

bool QueenFigure::Move(const std::string& curCoord, const std::string& nextCoord)
{
  const int dx = abs(nextCoord[0] - curCoord[0]);
  const int dy = abs(nextCoord[1] - curCoord[1]);
  return !(dx == dy ||
      nextCoord[0] == curCoord[0] ||
      nextCoord[1] == curCoord[1]) ? false : true;
}
