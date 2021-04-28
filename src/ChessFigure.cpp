#include "ChessFigure.hpp"
#include <string>
#include <cmath>

ChessFigure::ChessFigure(){}

ChessFigure::ChessFigure(const std::string& coord)
    : current_coord_(coord)
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(const std::string& nextCoord)
{
		return false;
}

bool ChessFigure::IsValidCoordinate(const std::string & coord){
    if(coord[0] < 'A'){
        return false;
    }
    if(coord[0] > 'H'){
        return false;
    }
    if(coord[1] < '1'){
        return false;
    }
    if(coord[1] > '8'){
        return false;
    }
    return true;
}

int ChessFigure::Distance(const char & a, const char & b){
    return abs(a - b);
}
