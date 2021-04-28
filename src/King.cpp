#include "King.hpp"
#include "utils.hpp"

King::King(const std::string& coord) : ChessFigure(coord)
{
}

bool King::Move(const std::string& nextCoord)
{
	const bool isCorrectStep = abs(nextCoord[0] - currentCoord[0]) <= 1 &&
		abs(nextCoord[1] - currentCoord[1]) <= 1;
	if (Utils::IsFigureInDesk(nextCoord) && isCorrectStep)
	{
		return true;
	}
	return false;
}
