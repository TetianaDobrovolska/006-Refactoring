#include "knight.hpp"

Knight::Knight(const std::string& coord) : ChessFigure(coord) {}

bool Knight::move(const std::string& nextCoord) {
    if (!isValidMove(nextCoord)) {
        return false;
    }

    _currentCoord = nextCoord;
    return true;
}

bool Knight::isValidMove(const std::string& nextCoord) {
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8') {
        int dx, dy;
        dx = abs(nextCoord[0] - _currentCoord[0]);
        dy = abs(nextCoord[1] - _currentCoord[1]);
        if (!(abs(nextCoord[0] - _currentCoord[0]) == 1 && abs(nextCoord[1] - _currentCoord[1]) == 2 || abs(nextCoord[0] - _currentCoord[0]) == 2 && abs(nextCoord[1] - _currentCoord[1]) == 1))
          return false;
        else
        return true;
    }
    else return false;
}
