#include "rook.hpp"

Rook::Rook(const std::string& coord) : ChessFigure(coord) {}

bool Rook::move(const TargetMove& targetMove) {
    if (!isValidMove(targetMove)) {
        return false;
    }

    _currentCoord = targetMove.target;
    return true;
}

bool Rook::isValidMove(const TargetMove& targetMove) {
    const std::string target = targetMove.target;
    if(!isValidTarget(target))
        return false;

    if(targetMove.isKingCheckedAfterMove)
        return false;

    const bool isSameCol = (target[0] == _currentCoord[0]);
    const bool isSameRow = (target[1] == _currentCoord[1]);
    const bool isHorisontal = isSameRow && (!isSameCol);
    const bool isVerticalal = (!isSameRow) && isSameCol;
    const bool isRookMove = isHorisontal || isVerticalal;
    const bool isBlocked = targetMove.isBlockedLineOfSight ||
                           targetMove.isOccupiedBySelf;

    return isRookMove && (!isBlocked);
}
