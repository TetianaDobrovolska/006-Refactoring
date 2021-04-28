#include "knight.hpp"
#include <string>
#include <cmath>

Knight::Knight(const std::string& coord){
    current_coord_ = coord;
}

bool Knight::Move(const std::string &nextCoord){
    if (!IsValidCoordinate(nextCoord)){
        return false;
    }

    const int horizontal_distance = Distance(nextCoord[0], current_coord_[0]);
    const int vertical_distance = Distance(nextCoord[1], current_coord_[1]);

    if(horizontal_distance == 1 && vertical_distance == 2){
        return true;
    }
    if(horizontal_distance == 2 && vertical_distance == 1){
        return true;
    }
    return false;
}
