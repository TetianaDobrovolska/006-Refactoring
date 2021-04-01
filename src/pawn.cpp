#include "pawn.hpp"

Pawn::Pawn(const std::string& coord) : ChessFigure(coord) {}

bool Pawn::move(const std::string& nextCoord) {
    if (!isValidMove(nextCoord)) {
        return false;
    }

    _currentCoord = nextCoord;
    return true;
}

bool Pawn::isValidMove(const std::string& nextCoord) {
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8') {
        if (nextCoord[0] != _currentCoord[0] || nextCoord[1] <= _currentCoord[1] || (nextCoord[1] - _currentCoord[1] != 1 && (_currentCoord[1] != '2' || nextCoord[1] != '4')))
            return false;
        else
            return true;
    }
    else return false;
}
