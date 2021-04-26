#include "player.h"

Player::Player()
    : Name("")
    , Balance(6000)
{

}

Player::Player(const std::string& name, const int& balance)
    : Name(name)
    , Balance(balance)
{

}

const int& Player::getBalance() const
{
    return Balance;
}

void Player::calcBalance(const int &delta)
{
    Balance += delta;
}

const std::string &Player::getName() const
{
    return Name;
}
