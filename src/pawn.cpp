#include "pawn.hpp"
#include <string>

Pawn::Pawn(const std::string &coord){
    current_coord_ = coord;
}

int Pawn::Distance(const char & a, const char & b){
    return a - b;
}

bool Pawn::Move(const std::string &nextCoord){
    if (!IsValidCoordinate(nextCoord)){
        return false;
    }

    if(nextCoord[0] != current_coord_[0]){
        return false;
    }

    const int vertical_distance = Distance(nextCoord[1], current_coord_[1]);
    if(vertical_distance != 1){
        return false;
    }
}
