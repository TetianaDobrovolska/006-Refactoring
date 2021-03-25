#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord) : type(type),
currentCoord(coord)
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(string nextCoord)
{
	if (type == PAWN)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
			if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
				return false;
			else
				return true;
		}
		else return false;
			
	}
	
	else if (type == ROOK)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
			if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
				return false;
			else
				return true;

		}
		else return false;
	}
	else if (type == KNIGHT)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
			int dx, dy;
			dx = abs(nextCoord[0] - currentCoord[0]);
			dy = abs(nextCoord[1] - currentCoord[1]);
		    if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
			  return false;
			else
			return true;
		}
		else return false;
	}
	
	else if (type == BISHOP)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
				return false;
			else
				return true;
		}
		else return false;
	}
	
	else if (type == KING)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
			if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
				return false;
			else
				return true;
		}
		else return false;
	}
	else if (type == QUEEN)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
				return false;
			else
				return true;
		}
		else return false;
	}
	else
		return false;
}