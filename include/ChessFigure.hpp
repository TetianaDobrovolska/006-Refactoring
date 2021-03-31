#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
public:
    static constexpr char FIRST_COL = 'A';
    static constexpr char LAST_COL = 'H';
    static constexpr char FIRST_ROW = '1';
    static constexpr char LAST_ROW = '8';

    ChessFigure(const std::string& initialCoord);
    virtual ~ChessFigure();
    virtual bool Move(const std::string& nextCoord) = 0;

protected:
    bool CheckMovementBoundary(const std::string& nextCoord);

    int GetColSteps(const std::string& nextCoord);
    int GetRowSteps(const std::string& nextCoord);
    bool ColChanged(const std::string& nextCoord);
    bool RowChanged(const std::string& nextCoord);
    bool OrthogonalMove(const std::string &nextCoord);
    bool DiagonalMove(const std::string &nextCoord);

    std::string currentCoord;
};

class Rook : public ChessFigure
{
public:
    Rook(const std::string& initialCoord) : ChessFigure(initialCoord)
    {
    }

    bool Move(const std::string& nextCoord) override
    {
        if (!CheckMovementBoundary(nextCoord))
            return false;
        return OrthogonalMove(nextCoord);
    }
};

class Knight : public ChessFigure
{
public:
    Knight(const std::string& initialCoord) : ChessFigure(initialCoord)
    {
    }

    bool Move(const std::string& nextCoord) override
    {
        if (!CheckMovementBoundary(nextCoord))
            return false;

        int colSteps = GetColSteps(nextCoord);
        int rawSteps = GetRowSteps(nextCoord);

        return (colSteps == 1 && rawSteps == 2 || colSteps == 2 && rawSteps == 1);
    }
};

class Bishop : public ChessFigure
{
public:
    Bishop(const std::string& initialCoord) : ChessFigure(initialCoord)
    {
    }

    bool Move(const std::string& nextCoord) override
    {
        if (!CheckMovementBoundary(nextCoord))
            return false;

        return DiagonalMove(nextCoord);
    }
};

class King : public ChessFigure
{
public:
    King(const std::string& initialCoord) : ChessFigure(initialCoord)
    {
    }

    bool Move(const std::string& nextCoord) override
    {
        if (!CheckMovementBoundary(nextCoord))
            return false;

        int colSteps = GetColSteps(nextCoord);
        int rawSteps = GetRowSteps(nextCoord);

        return (colSteps <= 1 && rawSteps <= 1);
    }
};

class Queen : public ChessFigure
{
public:
    Queen(const std::string& initialCoord) : ChessFigure(initialCoord)
    {
    }

    bool Move(const std::string& nextCoord) override
    {
        if (!CheckMovementBoundary(nextCoord))
            return false;

        bool colChanged = ColChanged(nextCoord);
        bool rawChanged = RowChanged(nextCoord);

        return (DiagonalMove(nextCoord) || !colChanged || !rawChanged);
    }
};

class Pawn : public ChessFigure
{
public:
    Pawn(const std::string& initialCoord) : ChessFigure(initialCoord)
    {
    }

    bool Move(const std::string& nextCoord) override
    {
        if (!CheckMovementBoundary(nextCoord))
            return false;

        bool colChanged = ColChanged(nextCoord);
        int rawSteps = GetRowSteps(nextCoord);

        if (colChanged || nextCoord[1] <= currentCoord[1] ||
           (rawSteps != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
            return false;
        else
            return true;
    }
};

#endif
