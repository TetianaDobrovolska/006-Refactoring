#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
	
public:
    ChessFigure(const std::string& coord);
	bool Move(std::string nextCoord);
	virtual ~ChessFigure();

protected:
    char currentX() const { return currentCoord.at(0); }
    char currentY() const { return currentCoord.at(1); }

    struct MoveData {
        const char nextX;
        const char nextY;
        int dx;
        int dy;
        const bool isXchanged;
        const bool isYchanged;

        bool isDiagonal() const { return dx == dy; }
    };

private:
	std::string currentCoord;
    static bool check_coordinates(const char letter, const char number);
    virtual bool moveFigure(const MoveData& data) = 0;

};

class RookFigure : public ChessFigure {
public:
    RookFigure(const std::string& coord) :
        ChessFigure(coord){}
private:
    bool moveFigure(const MoveData& data) override;
};

class KnightFigure : public ChessFigure {
public:
    KnightFigure(const std::string& coord) :
        ChessFigure(coord){}
private:
    bool moveFigure(const MoveData& data) override;
};

class BishopFigure : public ChessFigure {
public:
    BishopFigure(const std::string& coord) :
        ChessFigure(coord){}
private:
    bool moveFigure(const MoveData& data) override;
};

class PawnFigure : public ChessFigure {
public:
    PawnFigure(const std::string& coord) :
        ChessFigure(coord){}
private:
    bool moveFigure(const MoveData& data) override;
};

class KingFigure : public ChessFigure {
public:
    KingFigure(const std::string& coord) :
        ChessFigure(coord){}
private:
    bool moveFigure(const MoveData& data) override;
};

class QueenFigure : public ChessFigure {
public:
    QueenFigure(const std::string& coord) :
        ChessFigure(coord){}
private:
    bool moveFigure(const MoveData& data) override;
};

#endif
