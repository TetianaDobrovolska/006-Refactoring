#include "bishop.hpp"
#include <string>

Bishop::Bishop(const std::string &coord){
    current_coord_ = coord;
}

bool Bishop::Move(const std::string &nextCoord){
    if (!IsValidCoordinate(nextCoord)){
        return false;
    }
    const int horizontal_distance = Distance(nextCoord[0], current_coord_[0]);
    const int vertical_distance = Distance(nextCoord[1], current_coord_[1]);
    return horizontal_distance == vertical_distance ? true : false;

}
