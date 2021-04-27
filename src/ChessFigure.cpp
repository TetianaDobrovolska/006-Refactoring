#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(const std::string& coord) : currentCoord(coord)
{    
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::are_coordinates_inside_board(const string& nextCoord)
{
    Coordinates next(nextCoord);
	bool is_valid_x = next.getRow() >= BOARD_X_MIN && next.getRow() <= BOARD_X_MAX;
	bool is_valid_y = next.getColumn() >= BOARD_Y_MIN && next.getColumn() <= BOARD_Y_MAX;
	return is_valid_x && is_valid_y;
}

bool ChessFigure::Move(const std::string& nextCoord) {
    if (!are_coordinates_inside_board(nextCoord))
        return false;
    if (is_valid_step(nextCoord))
        return true;
    return false;
}

bool RookFigure::is_valid_step(const std::string& nextCoord){
    Coordinates next(nextCoord);
    bool is_same_row = next.getRow() == currentCoord.getRow();
    bool is_same_column = next.getColumn() == currentCoord.getColumn();
    bool is_same_row_or_column = is_same_row && is_same_column;
    
    return (is_same_row || is_same_column) && !is_same_row_or_column;
}

bool KnightFigure::is_valid_step(const std::string& nextCoord){
    Coordinates next(nextCoord);
    int dx, dy;
    dx = abs(next.getRow() - currentCoord.getRow());
    dy = abs(next.getColumn() - currentCoord.getColumn());
    
    return (dx == 1 && dy == 2 || dx == 2 && dy == 1);
}

bool BishopFigure::is_valid_step(const std::string& nextCoord){
    Coordinates next(nextCoord);
    int dx, dy;
    dx = abs(next.getRow() - currentCoord.getRow());
    dy = abs(next.getColumn() - currentCoord.getColumn());
    
    return dx == dy;
}

bool PawnFigure::is_valid_step(const std::string& nextCoord) {
    Coordinates next(nextCoord);
    bool is_same_row = next.getRow() == currentCoord.getRow();
    bool is_same_column = next.getColumn() == currentCoord.getColumn();
    bool is_step_forward = next.getColumn() > currentCoord.getColumn();
    bool is_step_forward_in_one_step = next.getColumn() - currentCoord.getColumn() == 1;
    bool is_double_step_from_initial = currentCoord.getColumn() == INITIAL_STEP.first && next.getColumn() == INITIAL_STEP.second;
    return is_same_row && is_step_forward && (is_step_forward_in_one_step || is_double_step_from_initial);
}

bool KingFigure::is_valid_step(const std::string& nextCoord) {
    Coordinates next(nextCoord);
    int dx, dy;
    dx = abs(next.getRow() - currentCoord.getRow());
    dy = abs(next.getColumn() - currentCoord.getColumn());
    
    return dx <= 1 && dy <= 1;
}

bool QueenFigure::is_valid_step(const std::string& nextCoord) {
    Coordinates next(nextCoord);
    int dx, dy;
    dx = abs(next.getRow() - currentCoord.getRow());
    dy = abs(next.getColumn() - currentCoord.getColumn());
    
    bool is_same_row = next.getRow() == currentCoord.getRow();
    bool is_same_column = next.getColumn() == currentCoord.getColumn();
    
    return dx == dy || is_same_row || is_same_column;
}