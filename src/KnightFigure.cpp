#include "KnightFigure.hpp"

bool KnightFigure::Move(const std::string& curCoord, const std::string& nextCoord)
{
  const int dx = abs(nextCoord[0] - curCoord[0]);
  const int dy = abs(nextCoord[1] - curCoord[1]);
  return !(dx == 1 && dy == 2 || dx == 2 && dy == 1) ? false : true;
}
