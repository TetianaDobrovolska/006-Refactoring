#include "PawnFigure.hpp"

bool PawnFigure::Move(const std::string& curCoord, const std::string& nextCoord)
{
  return nextCoord[0] != curCoord[0] ||
      nextCoord[1] <= curCoord[1] ||
      (nextCoord[1] - curCoord[1] != 1 &&
      (nextCoord[1] != '4' ||
      curCoord[1] != '2')) ? false : true;
}
