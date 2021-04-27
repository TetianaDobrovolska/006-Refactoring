#include "RookFigure.hpp"

bool RookFigure::Move(const std::string& curCoord, const std::string& nextCoord)
{
  return ((nextCoord[0] != curCoord[0]) &&
      (nextCoord[1] != curCoord[1])) ||
      ((nextCoord[0] == curCoord[0]) &&
      (nextCoord[1] == curCoord[1])) ? false : true;
}
