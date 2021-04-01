#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "ChessFigure.hpp"

class Queen : public ChessFigure{
public:
    Queen(const std::string& coord);
    bool move(const std::string& nextCoord) override;

private:
    bool isValidMove(const std::string& nextCoord) override;
};

#endif // QUEEN_HPP
