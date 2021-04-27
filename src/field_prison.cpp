#include "field_prison.hpp"

FieldPrison::FieldPrison(const std::string& name){
    name_ = name;
    type_ = Field::Type::PRISON;
    rent_ = RENT_PRISON_;
}

bool FieldPrison::sellTo(PlayerIterator player){
    return false;
}
