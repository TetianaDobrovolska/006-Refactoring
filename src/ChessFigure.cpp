#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(const std::string& coord) :
currentCoord(coord)
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::check_coordinates(const char letter, const char number)
{
    const bool letter_is_valid = letter >= 'A' && letter <= 'H';
    const bool number_is_valid = number >= '1' && number <= '8';
    return letter_is_valid && number_is_valid;
}

bool ChessFigure::Move(string nextCoord)
{
    const MoveData data {
        nextCoord.at(0),
        nextCoord.at(1),
        abs(data.nextX - currentX()),
        abs(data.nextY - currentY()),
        data.nextX != currentX(),
        data.nextY != currentY()
    };

    if (!check_coordinates(data.nextX, data.nextY)) {
        return false;
    }

    return moveFigure(data);
}

bool BishopFigure::moveFigure(const ChessFigure::MoveData &data)
{
    return data.isDiagonal();
}

bool KnightFigure::moveFigure(const ChessFigure::MoveData &data)
{
    return (data.dx == 1 && data.dy == 2) || (data.dx == 2 && data.dy == 1);
}

bool RookFigure::moveFigure(const ChessFigure::MoveData &data)
{
    return (data.isXchanged && !data.isYchanged) || (!data.isXchanged && data.isYchanged);
}

bool PawnFigure::moveFigure(const ChessFigure::MoveData &data)
{
    if (data.isXchanged) return false;
    if (data.nextY <= currentY()) return false;

    return (currentY() == '2' && data.nextY == '4') || data.nextY - currentY() == 1;
}

bool KingFigure::moveFigure(const ChessFigure::MoveData &data)
{
    return data.dx <= 1 && data.dy <= 1;
}

bool QueenFigure::moveFigure(const ChessFigure::MoveData &data)
{
    return data.isDiagonal() || !data.isXchanged || !data.isYchanged;
}
