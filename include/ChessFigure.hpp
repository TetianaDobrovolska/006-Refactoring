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
    bool CheckValidCoordinate(std::string nextCoord);
	virtual bool Move(std::string nextCoord);
	virtual ~ChessFigure();
protected:
	FigureType type;
	std::string currentCoord;
};

class Rook: ChessFigure
{

public:

  bool Move(std::string nextCoord);

};

class Pawn: ChessFigure
{
public:
    bool Move(std::string nextCoord);
};

class Knight: ChessFigure
{
public:
    bool Move(std::string nextCoord);
};

class Bishop: ChessFigure
{
public:
    bool Move(std::string nextCoord);
};

class King: ChessFigure
{
public:
    bool Move(std::string nextCoord);
};

class Queen: ChessFigure
{
public:
    bool Move(std::string nextCoord);
};

#endif
