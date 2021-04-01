#ifndef KING_HPP
#define KING_HPP

#include "ChessFigure.hpp"

class King : public ChessFigure {
public:
    King(const std::string& coord);
    bool move(const std::string& nextCoord) override;

private:
    bool isValidMove(const std::string& nextCoord) override;
};

#endif // KING_HPP
