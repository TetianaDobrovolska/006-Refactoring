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

        static constexpr char FIRST_COL = 'A';
        static constexpr char LAST_COL = 'H';
        static constexpr char FIRST_ROW = '1';
        static constexpr char LAST_ROW = '8';

	ChessFigure(FigureType type,std::string coord);
	bool Move(std::string nextCoord);
	virtual ~ChessFigure();
private:
        bool CheckMovementBoundary(const std::string& nextCoord);

	FigureType type;
	std::string currentCoord;
};

#endif
