#include "king.hpp"

King::King(const std::string& coord) : ChessFigure(coord) {}

bool King::move(const TargetMove& targetMove) {
    if (!isValidMove(targetMove)) {
        return false;
    }

    _currentCoord = targetMove.target;
    return true;
}

bool King::isValidMove(const TargetMove& targetMove) {
    const std::string target = targetMove.target;
    if(!isValidTarget(target))
    return false;

    const uint8_t dx = abs(target[0] - _currentCoord[0]);
    const uint8_t dy = abs(target[1] - _currentCoord[1]);
    const bool isKingMove = ((dx <= 1) && (dy <= 1));
    const bool isBlocked = targetMove.isGuarded ||
                           targetMove.isOccupiedBySelf;
    // TODO: account for draw (no move if all are guarded); requires state of all surrounding blocks (occupied? guarded?)

    return isKingMove && !isBlocked;
}
