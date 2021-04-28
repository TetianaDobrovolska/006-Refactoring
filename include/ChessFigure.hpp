#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
	
public:
    ChessFigure();
    ChessFigure(const std::string& coord);
    virtual bool Move(const std::string& nextCoord);
	virtual ~ChessFigure();
protected:
    std::string current_coord_;
    bool IsValidCoordinate(const std::string&);
    int Distance(const char&, const char&);
};

#endif
