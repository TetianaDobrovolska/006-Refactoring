#ifndef ROOK_HPP
#define ROOK_HPP

#include <string>
#include "ChessFigure.hpp"

class Rook : public ChessFigure
{
public:
	Rook(const std::string& coord);
	virtual bool Move(const std::string& nextCoord);
};

#endif