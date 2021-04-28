#ifndef KING_HPP
#define KING_HPP

#include <string>
#include "ChessFigure.hpp"

class King : public ChessFigure
{
public:
	King(const std::string& coord);
	virtual bool Move(const std::string& nextCoord);
};

#endif