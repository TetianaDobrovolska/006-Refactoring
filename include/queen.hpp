#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "ChessFigure.hpp"

class Queen : public ChessFigure
{
public:
    Queen(const std::string& coord);
    bool Move(const std::string& nextCoord);
};

#endif // QUEEN_HPP
