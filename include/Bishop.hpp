#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <string>
#include "ChessFigure.hpp"

class Bishop : public ChessFigure
{
public:
	Bishop(const std::string& coord);
	virtual bool Move(const std::string& nextCoord);
};

#endif