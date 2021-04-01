#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure {
public:
    virtual bool move(const std::string& nextCoord) = 0;
	virtual ~ChessFigure();

protected:
    ChessFigure(const std::string& coord);
    virtual bool isValidMove(const std::string& nextCoord) = 0;

    std::string _currentCoord;
};

#endif
