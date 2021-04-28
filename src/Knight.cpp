#include "Knight.hpp"
#include "utils.hpp"

Knight::Knight(const std::string& coord) : ChessFigure(coord)
{
}

bool Knight::Move(const std::string& nextCoord)
{
	int dx = abs(nextCoord[0] - currentCoord[0]);
	int dy = abs(nextCoord[1] - currentCoord[1]);
	const bool isCorrectSteps = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
	if (Utils::IsFigureInDesk(nextCoord) && isCorrectSteps)
	{
		return true;
	}
	return false;
}
