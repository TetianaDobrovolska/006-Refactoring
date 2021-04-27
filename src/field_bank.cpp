#include "field_bank.hpp"

FieldBank::FieldBank(const std::string& name){
    name_ = name;
    type_ = Field::Type::BANK;
    rent_ = RENT_BANK_;
}
