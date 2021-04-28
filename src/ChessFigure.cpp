#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(std::string coord) : currentCoord(coord)
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::isCoordValid(string coord)
{
	bool isValidX = coord[0] >= 'A' && coord[0] <= 'H';
	bool isValidY = coord[1] >= '1' && coord[1] <= '8';
	return isValidX && isValidY;
}

PawnFigure::PawnFigure(string coord) : ChessFigure(coord)
{
}

bool PawnFigure::Move(std::string nextCoord)
{
	if (isCoordValid(nextCoord))
	{
        if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
            return false;
        else
            return true;
	}
	return false;
}

RookFigure::RookFigure(string coord) : ChessFigure(coord)
{
}

bool RookFigure::Move(std::string nextCoord)
{
	if (isCoordValid(nextCoord))
	{
        if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
            return false;
        else
            return true;
	}
	return false;
}

KnightFigure::KnightFigure(string coord) : ChessFigure(coord)
{
}

bool KnightFigure::Move(std::string nextCoord)
{
	if (isCoordValid(nextCoord))
	{
		int dx, dy;
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
		if (!(dx == 1 && dy == 2 || dx == 2 && dy == 1))
			return false;
		else
			return true;
	}
	return false;
}

BishopFigure::BishopFigure(string coord) : ChessFigure(coord)
{
}

bool BishopFigure::Move(std::string nextCoord)
{
	if (isCoordValid(nextCoord))
	{
		if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
            return false;
        else
            return true;
	}
	return false;
}

KingFigure::KingFigure(string coord) : ChessFigure(coord)
{
}

bool KingFigure::Move(std::string nextCoord)
{
	if (isCoordValid(nextCoord))
	{
		if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
            return false;
        else
            return true;
	}
	return false;
}

QueenFigure::QueenFigure(string coord) : ChessFigure(coord)
{
}

bool QueenFigure::Move(std::string nextCoord)
{
	if (isCoordValid(nextCoord))
	{
		if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
            return false;
        else
			return true;
	}
	return false;
}
