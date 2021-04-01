#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "ChessFigure.hpp"

class Knight : public ChessFigure {
public:
    Knight(const std::string& coord);
    bool move(const std::string& nextCoord) override;

private:
    bool isValidMove(const std::string& nextCoord) override;
};

#endif // KNIGHT_HPP
