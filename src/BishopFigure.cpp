#include "BishopFigure.hpp"

bool BishopFigure::Move(const std::string& curCoord, const std::string& nextCoord)
{
  return abs(nextCoord[0] - curCoord[0]) == abs(nextCoord[1] - curCoord[1]) ? true : false;
}
