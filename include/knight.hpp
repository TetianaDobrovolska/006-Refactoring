#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "ChessFigure.hpp"

class Knight : public ChessFigure
{
public:
    Knight(const std::string& coord);
    bool Move(const std::string& nextCoord);
};

#endif // KNIGHT_HPP
