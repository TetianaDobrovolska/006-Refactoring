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

RookFigureType::RookFigureType(std::string coord) : ChessFigure(coord)
{
}

bool RookFigureType::Move(std::string nextCoord)
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

KnightFigureType::KnightFigureType(std::string coord) : ChessFigure(coord)
{
}

bool KnightFigureType::Move(std::string nextCoord)
{
	int dx, dy;
	if (isCoordValid(nextCoord))
	{
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
		if (!(dx == 1 && dy == 2 || dx == 2 && dy == 1))
			return false;
		else
			return true;
	}
	return false;
}

BishopFigureType::BishopFigureType(std::string coord) : ChessFigure(coord)
{
}

bool BishopFigureType::Move(std::string nextCoord)
{
	int dx, dy;
	if (isCoordValid(nextCoord))
	{
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
		if (!(dx == dy))
			return false;
		else
			return true;
	}
	return false;
}

PawnFigureType::PawnFigureType(std::string coord) : ChessFigure(coord)
{
}

bool PawnFigureType::Move(std::string nextCoord)
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

KingFigureType::KingFigureType(std::string coord) : ChessFigure(coord)
{
}

bool KingFigureType::Move(std::string nextCoord)
{
	int dx, dy;
	if (isCoordValid(nextCoord))
	{
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
		if (!(dx <= 1 && dy <= 1))
			return false;
		else
			return true;
	}
	return false;
}

QueenFigureType::QueenFigureType(std::string coord) : ChessFigure(coord)
{
}

bool QueenFigureType::Move(std::string nextCoord)
{
	int dx, dy;
	if (isCoordValid(nextCoord))
	{
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
		if (!(dx == dy || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
			return false;
		else
			return true;
	}
	return false;
}

bool ChessFigure::isCoordValid(std::string currentCoord)
{
	if (currentCoord[0] >= 'A' && currentCoord[0] <= 'H' && currentCoord[1] >= '1' && currentCoord[1] <= '8')
	{
		return true;
	}
	return false;
}
