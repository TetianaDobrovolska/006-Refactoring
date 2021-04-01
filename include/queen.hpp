#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "ChessFigure.hpp"

class Queen : public ChessFigure{
public:
    Queen(const std::string& coord);
    bool move(const TargetMove& targetMove) override;

private:
    bool isValidMove(const TargetMove& targetMove) override;
};

#endif // QUEEN_HPP
