#ifndef ROOK_HPP
#define ROOK_HPP

#include "ChessFigure.hpp"

class Rook : public ChessFigure
{
public:
    Rook(const std::string& coord);
    bool Move(const std::string& nextCoord);
};

#endif // ROOK_HPP
