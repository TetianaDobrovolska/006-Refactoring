#include "player.hpp"
#include <string>

Player::Player()
    :name_(""), money_(0)
{}

Player::Player(const std::string &name, const int& money)
    :name_(name), money_(money)
{}

int Player::getMoney() const {
    return money_;
}

void Player::setMoney(const int& number){
    money_ = number;
}

std::string Player::getName() const {
    return name_;
}
