#ifndef KING_HPP
#define KING_HPP

#include "ChessFigure.hpp"

class King : public ChessFigure
{
public:
    King(const std::string& coord);
    bool Move(const std::string& nextCoord);
};

#endif // KING_HPP
