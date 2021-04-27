#include "field_auto.hpp"

FieldAuto::FieldAuto(const std::string& name){
    name_ = name;
    type_ = Field::Type::AUTO;
    price_ = PRICE_AUTO_;
    rent_ = RENT_AUTO_;
}
