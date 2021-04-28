#ifndef PAWN_HPP
#define PAWN_HPP

#include "ChessFigure.hpp"

class Pawn : public ChessFigure
{
public:
    Pawn(const std::string& coord);
    bool Move(const std::string& nextCoord);
    int Distance(const char &, const char &);
};

#endif // PAWN_HPP
