#include "bishop.hpp"

Bishop::Bishop(const std::string& coord) : ChessFigure(coord) {}

bool Bishop::move(const TargetMove& targetMove) {
    if (!isValidMove(targetMove)) {
        return false;
    }

    _currentCoord = targetMove.target;
    return true;
}

bool Bishop::isValidMove(const TargetMove& targetMove) {
    const std::string target = targetMove.target;
    if(!isValidTarget(target))
        return false;

    if(targetMove.isKingCheckedAfterMove)
        return false;

    const bool isBlocked = targetMove.isBlockedLineOfSight ||
                           targetMove.isOccupiedBySelf;
    const bool isDiagonal = (abs(target[0] - _currentCoord[0])) == (abs(target[1] - _currentCoord[1]));

    return isDiagonal && (!isBlocked);
}
