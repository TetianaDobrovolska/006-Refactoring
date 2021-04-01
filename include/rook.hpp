#ifndef ROOK_HPP
#define ROOK_HPP

#include "ChessFigure.hpp"

class Rook : public ChessFigure {
public:
    Rook(const std::string& coord);
    bool move(const std::string& nextCoord) override;

private:
    bool isValidMove(const std::string& nextCoord) override;
};

#endif // ROOK_HPP
