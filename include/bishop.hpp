#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "ChessFigure.hpp"

class Bishop : public ChessFigure
{
public:
    Bishop(const std::string& coord);
    bool Move(const std::string& nextCoord);
};

#endif // BISHOP_HPP
