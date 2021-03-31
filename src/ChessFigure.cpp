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

bool Pawn::Move(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
        return false;
            else
    return true;
}

bool Rook::Move(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
        return false;
    else
        return true;
}

bool Knight::Move(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    int dx, dy;
    dx = abs(nextCoord[0] - currentCoord[0]);
    dy = abs(nextCoord[1] - currentCoord[1]);
    if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
        return false;
    else
        return true;
}

bool Bishop::Move(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
        return false;
    else
        return true;

}

bool King::Move(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
        return false;
    else
        return true;
}

bool Queen::Move(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
        return false;
    else
        return true;

}

bool ChessFigure::CheckValidCoordinate(string nextCoord)
{
    if(!CheckValidCoordinate(nextCoord))
        return false;

    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
        return true;
    else
        return false;
}

bool ChessFigure::Move(string nextCoord)
{

}
