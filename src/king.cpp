#include "king.hpp"

King::King(const std::string& coord) : ChessFigure(coord) {}

bool King::move(const std::string& nextCoord) {
    if (!isValidMove(nextCoord)) {
        return false;
    }

    _currentCoord = nextCoord;
    return true;
}

bool King::isValidMove(const std::string& nextCoord) {
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
    {
        if (!(abs(nextCoord[0] - _currentCoord[0]) <= 1 && abs(nextCoord[1] - _currentCoord[1]) <= 1))
            return false;
        else
            return true;
    }
    else return false;
}
