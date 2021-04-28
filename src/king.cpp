#include "king.hpp"
#include <string>

King::King(const std::string &coord){
    current_coord_ = coord;
}

bool King::Move(const std::string &nextCoord){
    if (!IsValidCoordinate(nextCoord)){
        return false;
    }
    const int horizontal_distance = Distance(nextCoord[0], current_coord_[0]);
    const int vertical_distance = Distance(nextCoord[1], current_coord_[1]);
    if (1 < horizontal_distance){
        return false;
    }
    if(1 < vertical_distance){
        return false;
    }
    return true;
}
