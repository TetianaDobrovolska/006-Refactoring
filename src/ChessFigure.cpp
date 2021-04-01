#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(const string& coord) : _currentCoord(coord), _regex("^[A-H][1-8]") {}
ChessFigure::~ChessFigure() {}

bool ChessFigure::isValidTarget(const std::string& target) {
    return std::regex_match(target, _regex);
}

