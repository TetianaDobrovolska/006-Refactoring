#include "player.h"

#include <cstring>

Player::Player(const char name[kMaxNameSize], const char symbol)
    : Symbol(symbol)
{
    strcpy(PlayerName, name);
}

const char * Player::getName() const
{
    return PlayerName;
}

const char Player::getSymbol() const
{
    return Symbol;
}
