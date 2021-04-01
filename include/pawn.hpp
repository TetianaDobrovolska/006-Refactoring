#ifndef PAWN_HPP
#define PAWN_HPP

#include "ChessFigure.hpp"

class Pawn : public ChessFigure {
public:
    Pawn(const std::string& coord);
    bool move(const TargetMove& targetMove) override;

private:
    bool isValidMove(const TargetMove& targetMove) override;
};

#endif // PAWN_HPP
