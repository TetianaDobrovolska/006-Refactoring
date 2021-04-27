#include "KingFigure.hpp"

bool KingFigure::Move(const std::string& curCoord, const std::string& nextCoord)
{
  return !(abs(nextCoord[0] - curCoord[0]) <= 1 &&
      abs(nextCoord[1] - curCoord[1]) <= 1) ? false : true;
}