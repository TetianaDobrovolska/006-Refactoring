#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "ChessFigure.hpp"

class Bishop : public ChessFigure {
public:
    Bishop(const std::string& coord);
    bool move(const TargetMove& targetMove) override;

private:
    bool isValidMove(const TargetMove& targetMove) override;
};
#endif // BISHOP_HPP
