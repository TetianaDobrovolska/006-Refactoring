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

bool ChessFigure::Move(string nextCoord)
{
    if (!isValidCoord (nextCoord)) { return false; }
    if (type == PAWN)
    {
        if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
            return false;
        else
            return true;
    }
    else if (type == ROOK)
    {
        if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
            return false;
        else
            return true;
    }
    else if (type == KNIGHT)
    {
        int dx, dy;
        dx = abs(nextCoord[0] - currentCoord[0]);
        dy = abs(nextCoord[1] - currentCoord[1]);
        if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
          return false;
        else
        return true;
    }
    else if (type == BISHOP)
    {
        if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
            return false;
        else
            return true;
    }
    else if (type == KING)
    {
        if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
            return false;
        else
            return true;
    }
    else if (type == QUEEN)
    {
        if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
            return false;
        else
            return true;
    }
    else
        return false;
}

bool ChessFigure::isValidCoord(string coord)
{
    const bool isValidChar = coord[0] >= 'A' && coord[0] <= 'H';
    const bool isValidNum  = coord[1] >= '1' && coord[1] <= '8';
    return isValidChar && isValidNum;
}

