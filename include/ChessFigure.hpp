#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class Coordinates{
    private:
        char row;
        char column;
    public:
        Coordinates(const std::string& coord):row(coord[0]), column(coord[1]){}
    char getRow() {return row;}
    char getColumn() {return column;}
};

class ChessFigure
{
	
public:
	ChessFigure(const std::string& coord);
	bool Move(const std::string& nextCoord);
	virtual ~ChessFigure();
protected:
	Coordinates currentCoord;
    virtual bool is_valid_step(const std::string& nextCoord) = 0;
	bool are_coordinates_inside_board(const std::string& nextCoord);
private:	
	static constexpr char BOARD_X_MIN = 'A';
	static constexpr char BOARD_X_MAX = 'H';
	static constexpr char BOARD_Y_MIN = '1';
	static constexpr char BOARD_Y_MAX = '8';
};

class RookFigure: public ChessFigure
{
private:
    bool is_valid_step(const std::string& nextCoord) override;
public:
	RookFigure(const std::string& coord): ChessFigure(coord){}
};
class KnightFigure: public ChessFigure
{
private:
    bool is_valid_step(const std::string& nextCoord) override;
public:
	KnightFigure(const std::string& coord): ChessFigure(coord){}
};
class BishopFigure: public ChessFigure
{
private:
    bool is_valid_step(const std::string& nextCoord) override;
public:
	BishopFigure(const std::string& coord): ChessFigure(coord){}
};

class PawnFigure: public ChessFigure
{
private:
    std::pair<char,char>INITIAL_STEP;
    bool is_valid_step(const std::string& nextCoord) override;
    
public:
	PawnFigure(const std::string& coord): ChessFigure(coord){INITIAL_STEP.first  = '2';INITIAL_STEP.second  = '4';}
};

class KingFigure: public ChessFigure
{
private:
    bool is_valid_step(const std::string& nextCoord) override;
public:
	KingFigure(const std::string& coord): ChessFigure(coord){}
};

class QueenFigure: public ChessFigure
{
private:
    bool is_valid_step(const std::string& nextCoord) override;
public:
	QueenFigure(const std::string& coord): ChessFigure(coord){}
};
#endif