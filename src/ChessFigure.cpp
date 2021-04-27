#include "ChessFigure.hpp"

#include <cmath>

namespace {

bool isCoordValid(const std::string& coord)
{
  return coord[0] >= 'A' &&
      coord[0] <= 'H' &&
      coord[1] >= '1' &&
      coord[1] <= '8';
}

}  //namespace

ChessFigure::ChessFigure(FigureType* type, const std::string& coord) 
  : type(type), currentCoord(coord)
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(const std::string& nextCoord)
{
  if (!isCoordValid(nextCoord))
    return false;
  return type->Move(currentCoord, nextCoord) ? true : false;
	/*if (type == PAWN)
	{

		if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
			return false;
		else
			return true;
	}

	else if (type == ROOK)
	{
		if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
			return false;
		else
			return true;
	}

	else if (type == KNIGHT)
	{
		int dx, dy;
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
		if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
			return false;
		else
			return true;
	}

	else if (type == BISHOP)
	{
		if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
			return false;
		else
			return true;
	}

	else if (type == KING)
	{
		if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
			return false;
		else
			return true;
	}

	else if (type == QUEEN)
	{
		if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
			return false;
		else
			return true;
	}
	else
		return false;
	*/
}














































