#include "field_clother.hpp"

FieldClother::FieldClother(const std::string& name){
    name_ = name;
    type_ = Field::Type::CLOTHER;
    price_ = PRICE_CLOTHER_;
    rent_ = RENT_CLOTHER_;
}
