#include "Pawn.hpp"
#include "utils.hpp"

Pawn::Pawn(const std::string& coord) : ChessFigure(coord)
{
}

bool Pawn::Move(const std::string& nextCoord)
{
	const bool isTheSameColumn = nextCoord[0] == currentCoord[0];
	const bool isOneStepForward = nextCoord[1] - currentCoord[1] == 1;
	const bool isFirstTwoStepsMove = currentCoord[1] == '2' && nextCoord[1] == '4';
	const bool isCorrectStepsNumber = isOneStepForward || isFirstTwoStepsMove;
	const bool isCorrectStep = isTheSameColumn && isCorrectStepsNumber;
	if (Utils::IsFigureInDesk(nextCoord) && isCorrectStep)
	{
		return true;
	}
	return false;
}
