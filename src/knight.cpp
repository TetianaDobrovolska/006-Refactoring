#include "knight.hpp"

Knight::Knight(const std::string& coord) : ChessFigure(coord) {}

bool Knight::move(const TargetMove &targetMove) {
    if (!isValidMove(targetMove)) {
        return false;
    }

    _currentCoord = targetMove.target;
    return true;
}

bool Knight::isValidMove(const TargetMove& targetMove) {
    const std::string target = targetMove.target;
    if(!isValidTarget(target))
        return false;

    if(targetMove.isKingCheckedAfterMove)
        return false;

    const uint8_t dx = abs(target[0] - _currentCoord[0]);
    const uint8_t dy = abs(target[1] - _currentCoord[1]);
    const bool isKnightMove = (((dx == 1) && (dy == 2)) || ((dx == 2) && (dy == 1)));
    const bool isBlocked = targetMove.isOccupiedBySelf;
    return isKnightMove && (!isBlocked);
}
