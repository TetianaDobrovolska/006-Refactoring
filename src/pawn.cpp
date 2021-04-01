#include "pawn.hpp"

Pawn::Pawn(const std::string& coord) : ChessFigure(coord) {}

bool Pawn::move(const TargetMove& targetMove) {
    if (!isValidMove(targetMove)) {
        return false;
    }

    _currentCoord = targetMove.target;
    return true;
}

bool Pawn::isValidMove(const TargetMove& targetMove) {
    const std::string target = targetMove.target;
    if(!isValidTarget(target))
        return false;

    if(targetMove.isKingCheckedAfterMove)
        return false;

    char currentLetter = _currentCoord[0];
    char targetLetter = target[0];
    uint8_t currentNumber = std::atoi(_currentCoord.substr(1, 1).c_str());
    uint8_t targetNumber = std::atoi(target.substr(1, 1).c_str());

    const bool occupiedByOpponent = targetMove.isOccupiedByOpponent;
    const bool isFree = !targetMove.isOccupiedByOpponent &&
                        !targetMove.isOccupiedBySelf;
    const bool isAtInitPos = currentNumber == 2;
    const bool isDiffOne = (targetNumber - currentNumber) == 1;
    const bool isDiffTwo = (targetNumber - currentNumber) == 2;
    const bool movesOneUp = isDiffOne &&
                            isFree;
    const bool movesTwoUp = isDiffTwo &&
                            isAtInitPos &&
                            isFree;
    const bool movesUp = movesOneUp || movesTwoUp;
    const bool isAdjuscentCol = abs(targetLetter - currentLetter) == 1;
    const bool isDiagonal = isAdjuscentCol &&
                            movesOneUp;
    const bool capturesDiagonally = isDiagonal &&
                                    occupiedByOpponent;
    // TODO: account for "en-passant" (requires last opponent's move)

    return (movesUp || capturesDiagonally);
}
