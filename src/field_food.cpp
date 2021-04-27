#include "field_food.hpp"

FieldFood::FieldFood(const std::string& name){
    name_ = name;
    type_ = Field::Type::FOOD;
    price_ = PRICE_FOOD_;
}
