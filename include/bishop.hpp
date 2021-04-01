#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "ChessFigure.hpp"

class Bishop : public ChessFigure {
public:
    Bishop(const std::string& coord);
    bool move(const std::string& nextCoord) override;

private:
    bool isValidMove(const std::string &nextCoord) override;
};
#endif // BISHOP_HPP
