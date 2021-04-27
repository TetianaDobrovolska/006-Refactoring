#include "field_travel.hpp"

FieldTravel::FieldTravel(const std::string& name){
    name_ = name;
    type_ = Field::Type::TRAVEL;
    price_ = PRICE_TRAVEL_;
    rent_ = RENT_TRAVEL_;
}
