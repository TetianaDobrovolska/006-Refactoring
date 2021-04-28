#include "Bishop.hpp"
#include "utils.hpp"

Bishop::Bishop(const std::string& coord) : ChessFigure(coord)
{
}

bool Bishop::Move(const std::string& nextCoord)
{
	const bool isCorrectSteps = abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]);
	if (Utils::IsFigureInDesk(nextCoord) && isCorrectSteps)
	{
		return true;
	}
	return false;
}
