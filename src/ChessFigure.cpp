#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(const string &initialCoord) : currentCoord(initialCoord)
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::CheckMovementBoundary(const std::string& nextCoord)
{
    bool validColumn = nextCoord[0] >= ChessFigure::FIRST_COL && nextCoord[0] <= ChessFigure::LAST_COL;
    bool validRaw =    nextCoord[1] >= ChessFigure::FIRST_ROW && nextCoord[1] <= ChessFigure::LAST_ROW;

    return validColumn && validRaw;
}

int ChessFigure::GetColSteps(const string &nextCoord)
{
    return abs(nextCoord[0] - currentCoord[0]);
}

int ChessFigure::GetRowSteps(const string &nextCoord)
{
    return abs(nextCoord[1] - currentCoord[1]);
}

bool ChessFigure::ColChanged(const string &nextCoord)
{
    return GetColSteps(nextCoord) != 0;
}

bool ChessFigure::RowChanged(const string &nextCoord)
{
    return GetRowSteps(nextCoord) != 0;
}

bool ChessFigure::OrthogonalMove(const string &nextCoord)
{
    bool colChanged = ColChanged(nextCoord);
    bool rawChanged = RowChanged(nextCoord);

    return colChanged && !rawChanged || !colChanged && rawChanged;
}

bool ChessFigure::DiagonalMove(const string &nextCoord)
{
    return GetColSteps(nextCoord) == GetRowSteps(nextCoord);
}
