#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <string>
#include "ChessFigure.hpp"

class Knight : public ChessFigure
{
public:
	Knight(const std::string& coord);
	virtual bool Move(const std::string& nextCoord);
};

#endif