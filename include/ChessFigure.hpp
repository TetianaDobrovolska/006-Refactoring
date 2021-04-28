#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
public:
	ChessFigure(std::string coord);
	virtual bool Move(std::string nextCoord) = 0;
	virtual ~ChessFigure();
protected:
	std::string currentCoord;
	bool isCoordValid(std::string coord);
};

class RookFigure : public ChessFigure
{
public:
	RookFigure (std::string coord);
	bool Move(std::string nextCoord) override;
};

class KnightFigure : public ChessFigure
{
public:
	KnightFigure (std::string coord);
	bool Move(std::string nextCoord) override;
};

class BishopFigure : public ChessFigure
{
public:
	BishopFigure (std::string coord);
	bool Move(std::string nextCoord) override;
};

class PawnFigure : public ChessFigure
{
public:
	PawnFigure (std::string coord);
	bool Move(std::string nextCoord) override;
};

class KingFigure : public ChessFigure
{
public:
	KingFigure (std::string coord);
	bool Move(std::string nextCoord) override;
};

class QueenFigure : public ChessFigure
{
public:
	QueenFigure (std::string coord);
	bool Move(std::string nextCoord) override;
};


#endif