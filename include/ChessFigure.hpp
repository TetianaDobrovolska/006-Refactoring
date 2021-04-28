#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
public:
	ChessFigure(const std::string& coord);
	virtual bool Move(const std::string& nextCoord) = 0;
	virtual ~ChessFigure();
protected:
	std::string currentCoord;
};

#endif