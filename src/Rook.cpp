#include "Rook.hpp"
#include "utils.hpp"

Rook::Rook(const std::string& coord) : ChessFigure(coord)
{
}

bool Rook::Move(const std::string& nextCoord)
{
	const bool isNotTheSameColumnOrRow = nextCoord[0] != currentCoord[0] || nextCoord[1] != currentCoord[1];
	const bool isTheSameColumnOrRow = nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1];
	const bool isCorrectSteps = isNotTheSameColumnOrRow && isTheSameColumnOrRow;
	if (Utils::IsFigureInDesk(nextCoord) && isCorrectSteps)
	{
		return true;
	}
	return false;
}
