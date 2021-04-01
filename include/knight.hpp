#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "ChessFigure.hpp"

class Knight : public ChessFigure {
public:
    Knight(const std::string& coord);
    bool move(const TargetMove& targetMove) override;

private:
    bool isValidMove(const TargetMove& targetMove) override;
};

#endif // KNIGHT_HPP
