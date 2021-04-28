#include "queen.hpp"
#include <string>
#include <cmath>

Queen::Queen(const std::string &coord){
    current_coord_ = coord;
}

bool Queen::Move(const std::string &nextCoord){
    if (!IsValidCoordinate(nextCoord)){
        return false;
    }

    const int horizontal_distance = Distance(nextCoord[0], current_coord_[0]);
    const int vertical_distance = Distance(nextCoord[1], current_coord_[1]);

    if(horizontal_distance == 0 && vertical_distance >0){
        return true;
    }
    if(vertical_distance == 0 && horizontal_distance > 1){
        return true;
    }
    if(horizontal_distance == vertical_distance){
        return true;
    }
    return false;
}
