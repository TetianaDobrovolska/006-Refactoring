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

bool ChessFigure::CheckMovementBoundary(const std::string& nextCoord)
{
    return (nextCoord[0] >= ChessFigure::FIRST_COL &&
            nextCoord[0] <= ChessFigure::LAST_COL &&
            nextCoord[1] >= ChessFigure::FIRST_ROW &&
            nextCoord[1] <= ChessFigure::LAST_ROW);
}

bool ChessFigure::Move(string nextCoord)
{
    if (!CheckMovementBoundary(nextCoord)) {
        return false;
    }

    int colSteps = abs(nextCoord[0] - currentCoord[0]);
    int rawSteps = abs(nextCoord[1] - currentCoord[1]);
    bool colChanged = colSteps != 0;
    bool rawChanged = rawSteps != 0;
    bool orthogonalMove = colChanged && !rawChanged || !colChanged && rawChanged;
    bool diagonalMove = colSteps == rawSteps;

    switch (type) {
    case PAWN:
        if (colChanged || nextCoord[1] <= currentCoord[1] ||
           (rawSteps != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
            return false;
        else
            return true;

    case ROOK:
        return orthogonalMove;
    case KNIGHT:
        return (colSteps == 1 && rawSteps == 2 || colSteps == 2 && rawSteps == 1);
    case BISHOP:
        return diagonalMove;
    case KING:
        return (colSteps <= 1 && rawSteps <= 1);
    case QUEEN:
        return (diagonalMove || !colChanged || !rawChanged);
    default:
        return false;
    }
}
