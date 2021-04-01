#ifndef PAWN_HPP
#define PAWN_HPP

#include "ChessFigure.hpp"

class Pawn : public ChessFigure {
public:
    Pawn(const std::string& coord);
    bool move(const std::string& nextCoord) override;

private:
    bool isValidMove(const std::string& nextCoord) override;
};

#endif // PAWN_HPP
