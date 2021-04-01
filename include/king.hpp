#ifndef KING_HPP
#define KING_HPP

#include "ChessFigure.hpp"

class King : public ChessFigure {
public:
    King(const std::string& coord);
    bool move(const TargetMove& targetMove) override;

private:
    bool isValidMove(const TargetMove& targetMove) override;
};

#endif // KING_HPP
