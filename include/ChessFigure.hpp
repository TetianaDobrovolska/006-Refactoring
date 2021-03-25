#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
	
public:
	enum FigureType
	{
		ROOK,
		KNIGHT,
		BISHOP,
		PAWN,
		KING,
		QUEEN
	};
	ChessFigure(FigureType type,std::string coord);
	bool Move(std::string nextCoord);
	virtual ~ChessFigure();
private:
	FigureType type;
	std::string currentCoord;
};

#endif