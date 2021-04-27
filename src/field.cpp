#include "field.hpp"

Field::Field(){
    name_ = "";
    type_ = Field::Type::PRISON;
}

Field::Field(const std::string& name, const Type& type){
    name_ = name;
    type_ = type;
}

PlayerIterator Field::getPlayer() const {
    return player_owner_;
}

std::string Field::getName() const {
    return name_;
}

Field::Type Field::getType() const {
    return type_;
}

int Field::getPrice() const {
    return price_;
}

int Field::getRent() const {
    return rent_;
}

bool Field::sellTo(PlayerIterator player){
    player_owner_ = player;
    return true;
}
