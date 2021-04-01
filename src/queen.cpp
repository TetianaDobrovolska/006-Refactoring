#include "queen.hpp"

Queen::Queen(const std::string& coord) : ChessFigure(coord) {}

bool Queen::move(const TargetMove& targetMove) {
    if (!isValidMove(targetMove)) {
        return false;
    }

    _currentCoord = targetMove.target;
    return true;
}

bool Queen::isValidMove(const TargetMove& targetMove) {
    const std::string target = targetMove.target;
    if(!isValidTarget(target))
        return false;

    if(targetMove.isKingCheckedAfterMove)
        return false;

    const uint8_t dx = abs(target[0] - _currentCoord[0]);
    const uint8_t dy = abs(target[1] - _currentCoord[1]);
    const bool isSameCol = (dx == 0);
    const bool isSameRow = (dy == 0);
    const bool isHorisontal = isSameRow && (!isSameCol);
    const bool isVerticalal = (!isSameRow) && isSameCol;
    const bool isDiagonal = (dx == dy);
    const bool isQueenMove = (isHorisontal || isVerticalal || isDiagonal);
    const bool isBlocked = targetMove.isBlockedLineOfSight ||
                           targetMove.isOccupiedBySelf;

    return isQueenMove && (!isBlocked);
}
