#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord) : type(type),
currentCoord(coord)
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::check_coordinates(const char letter, const char number)
{
    const bool letter_is_valid = letter >= 'A' && letter <= 'H';
    const bool number_is_valid = number >= '1' && number <= '8';
    return letter_is_valid && number_is_valid;
}

bool ChessFigure::Move(string nextCoord)
{
    const char x = nextCoord.at(0);
    const char y = nextCoord.at(1);
    if (!check_coordinates(x, y)) {
        return false;
    }

    const char current_x = currentCoord.at(0);
    const char current_y = currentCoord.at(1);

    int dx = abs(x - current_x);
    int dy = abs(y - current_y);
    const bool diagonal_move = dx == dy;
    const bool x_changed = x != current_x;
    const bool y_changed = y != current_y;

	if (type == PAWN)
	{
        return !(x_changed || nextCoord[1] <= current_y || (y - current_y != 1 && (current_y != '2' || y != '4')));
	}
	
	else if (type == ROOK)
	{
        return !((x_changed && y != current_y) || (!x_changed && !y_changed));
	}
	else if (type == KNIGHT)
	{
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
	
	else if (type == BISHOP)
	{
        return diagonal_move;
	}
	
	else if (type == KING)
	{
        return dx <= 1 && dy <= 1;
	}
	else if (type == QUEEN)
	{
        return diagonal_move || !x_changed || !y_changed;
	}
	else
		return false;
}
