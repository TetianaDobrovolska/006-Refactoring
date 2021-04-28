#ifndef PAWN_HPP
#define PAWN_HPP

#include <string>
#include "ChessFigure.hpp"

class Pawn : public ChessFigure
{
public:
	Pawn(const std::string& coord);
	virtual bool Move(const std::string& nextCoord);
};

#endif