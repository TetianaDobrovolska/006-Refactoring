#include "player.hpp"

Player::Player()
{

}

Player::Player(const std::string& name, const int& money):
    name(name),
    money(money)
{

}

const std::string& Player::GetName() const
{
    return name;
}


const int& Player::GetMoney() const
{
    return money;
}
