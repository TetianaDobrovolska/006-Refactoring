#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

const int CHAR_INDEX_IN_COORD = 0;
const int NUM_INDEX_IN_COORD = 1;

ChessFigure::ChessFigure(std::string coord) : currentCoord(coord)
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::isValidCoord(string coord)
{
    const bool isValidChar = coord[0] >= 'A' && coord[0] <= 'H';
    const bool isValidNum  = coord[1] >= '1' && coord[1] <= '8';
    return isValidChar && isValidNum;
}

RookFigure::RookFigure(string coord) : ChessFigure(coord)
{
}

bool RookFigure::Move(string nextCoord)
{
    const bool isInvalidCoord = !isValidCoord(nextCoord);
    const bool isSameCoord = nextCoord == currentCoord;
    const bool isNotInSameRowOrCol = (nextCoord[CHAR_INDEX_IN_COORD] != currentCoord[CHAR_INDEX_IN_COORD])
                                     && (nextCoord[NUM_INDEX_IN_COORD] != currentCoord[NUM_INDEX_IN_COORD]);
    
    return !(isInvalidCoord || isSameCoord || isNotInSameRowOrCol);
}

KnightFigure::KnightFigure(string coord) : ChessFigure(coord)
{
}

bool KnightFigure::Move(string nextCoord)
{
    const bool isNextCoordValid = isValidCoord(nextCoord);
    
    int dx, dy;
    dx = abs(nextCoord[CHAR_INDEX_IN_COORD] - currentCoord[CHAR_INDEX_IN_COORD]);
    dy = abs(nextCoord[NUM_INDEX_IN_COORD] - currentCoord[NUM_INDEX_IN_COORD]);
    const bool isValidKnightMove = ((dx == 1 && dy == 2) || (dx == 2 && dy == 1));

    return isNextCoordValid && isValidKnightMove;
}

BishopFigure::BishopFigure(string coord) : ChessFigure(coord)
{
}

bool BishopFigure::Move(string nextCoord)
{
    const bool isNextCoordValid = isValidCoord(nextCoord);
    
    int dx, dy;
    dx = abs(nextCoord[CHAR_INDEX_IN_COORD] - currentCoord[CHAR_INDEX_IN_COORD]);
    dy = abs(nextCoord[NUM_INDEX_IN_COORD] - currentCoord[NUM_INDEX_IN_COORD]);
    const bool isOnDiagonalLine = dx == dy;

    return isNextCoordValid && isOnDiagonalLine;
}

PawnFigure::PawnFigure(string coord) : ChessFigure(coord)
{
}

bool PawnFigure::Move(string nextCoord)
{
    const bool isInvalidCoord = !isValidCoord(nextCoord);
    const bool isNotSameCharInCoord = nextCoord[CHAR_INDEX_IN_COORD] != currentCoord[CHAR_INDEX_IN_COORD];
    const bool isInvalidNumInCoordMove = nextCoord[NUM_INDEX_IN_COORD] <= currentCoord[NUM_INDEX_IN_COORD]
                                         || (nextCoord[NUM_INDEX_IN_COORD] - currentCoord[NUM_INDEX_IN_COORD] != 1
                                             && (currentCoord[NUM_INDEX_IN_COORD] != '2' || nextCoord[NUM_INDEX_IN_COORD] != '4'));
    
    return !(isInvalidCoord || isNotSameCharInCoord || isInvalidNumInCoordMove);
}

KingFigure::KingFigure(string coord) : ChessFigure(coord)
{
}

bool KingFigure::Move(string nextCoord)
{
    const bool isNextCoordValid = isValidCoord(nextCoord);
    
    int dx, dy;
    dx = abs(nextCoord[CHAR_INDEX_IN_COORD] - currentCoord[CHAR_INDEX_IN_COORD]);
    dy = abs(nextCoord[NUM_INDEX_IN_COORD] - currentCoord[NUM_INDEX_IN_COORD]);
    const bool isValidKingMove = dx <= 1 && dy <= 1;

    return isNextCoordValid && isValidKingMove;
}

QueenFigure::QueenFigure(string coord) : ChessFigure(coord)
{
}

bool QueenFigure::Move(string nextCoord)
{
    const bool isNextCoordValid = isValidCoord(nextCoord);
    
    int dx, dy;
    dx = abs(nextCoord[CHAR_INDEX_IN_COORD] - currentCoord[CHAR_INDEX_IN_COORD]);
    dy = abs(nextCoord[NUM_INDEX_IN_COORD] - currentCoord[NUM_INDEX_IN_COORD]);
    const bool isOnDiagonalLine = dx == dy;

    const bool isSameRowOrSameCol = nextCoord[CHAR_INDEX_IN_COORD] == currentCoord[CHAR_INDEX_IN_COORD]
                                    || nextCoord[NUM_INDEX_IN_COORD] == currentCoord[NUM_INDEX_IN_COORD];

    return isNextCoordValid && (isOnDiagonalLine || isSameRowOrSameCol);
}

