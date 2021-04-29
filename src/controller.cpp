#include "controller.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "queen.hpp"

void Controller::start() {
    return true;
}

bool Controller::isCellBusy(const char& positionAlphabet, const char& positionNumber) {
    return true;
}

void Controller::move(const char& positionAlphabet, const char& positionNumber) {
    FigureCommon *figure  = new Rook('B', '0', 0);
}