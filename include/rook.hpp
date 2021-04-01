#ifndef ROOK_HPP
#define ROOK_HPP

#include "ChessFigure.hpp"

class Rook : public ChessFigure {
public:
    Rook(const std::string& coord);
    bool move(const TargetMove& targetMove) override;

private:
    bool isValidMove(const TargetMove& targetMove) override;
};

#endif // ROOK_HPP
