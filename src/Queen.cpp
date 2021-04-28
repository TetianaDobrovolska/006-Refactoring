#include "Queen.hpp"
#include "utils.hpp"

Queen::Queen(const std::string& coord) : ChessFigure(coord)
{
}

bool Queen::Move(const std::string& nextCoord)
{
	const bool isTheSameDiagonal = abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]);
	const bool isTheSameColumn = nextCoord[0] == currentCoord[0];
	const bool isTheSameRow = nextCoord[1] == currentCoord[1];
	const bool isCorrectSteps = isTheSameDiagonal || isTheSameColumn || isTheSameRow;
	if (Utils::IsFigureInDesk(nextCoord) && isCorrectSteps)
	{
		return true;
	}
	return false;
}
