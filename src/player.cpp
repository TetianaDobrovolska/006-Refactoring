#include "player.h"
#include <stdexcept>

namespace tictactoe {

Player::Player(char sym, player_code code, const std::string& player_name) :
    m_symbol(sym), m_id(code), m_name(player_name)
{

}

Player::~Player()
{

}

char Player::getSymbol() const
{
    return m_symbol;
}

player_code Player::getId() const
{
    return m_id;
}

const std::string& Player::getName() const
{
    return m_name;
}

bool NullPlayer::isNull() const
{
    return true;
}

bool Player::isNull() const
{
    return false;
}

player_code NullPlayer::getId() const
{
    throw std::logic_error("Using null object");
}

char NullPlayer::getSymbol() const
{
    throw std::logic_error("Using null object");
}


const std::string& NullPlayer::getName() const
{
    throw std::logic_error("Using null object");
}

}
