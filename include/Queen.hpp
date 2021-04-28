#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <string>
#include "ChessFigure.hpp"

class Queen : public ChessFigure
{
public:
	Queen(const std::string& coord);
	virtual bool Move(const std::string& nextCoord);
};

#endif