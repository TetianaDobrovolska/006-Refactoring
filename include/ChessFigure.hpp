#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
	
public:
	ChessFigure(std::string coord);
	virtual bool Move(std::string nextCoord) = 0;
	virtual ~ChessFigure();
	bool isCoordValid(std::string currentCoord);
	std::string currentCoord;
};

class RookFigureType : public ChessFigure
{
public:
	RookFigureType(std::string coord);
	bool Move(std::string nextCoord) override;
};

class KnightFigureType : public ChessFigure
{
public:
	KnightFigureType(std::string coord);
	bool Move(std::string nextCoord) override;
};

class BishopFigureType : public ChessFigure
{
public:
	BishopFigureType(std::string coord);
	bool Move(std::string nextCoord) override;
};

class PawnFigureType : public ChessFigure
{
public:
	PawnFigureType(std::string coord);
	bool Move(std::string nextCoord) override;
};

class KingFigureType : public ChessFigure
{
public:
	KingFigureType(std::string coord);
	bool Move(std::string nextCoord) override;
};

class QueenFigureType : public ChessFigure
{
public:
	QueenFigureType(std::string coord);
	bool Move(std::string nextCoord) override;
};

#endif
