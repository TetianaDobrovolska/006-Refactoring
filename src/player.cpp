#include "player.hpp"

Player::Player()
{
}

Player::Player(const std::string& name, const char playerSymbol) : 
	m_name(name), 
	m_symbol(playerSymbol)
{
}

std::string Player::getName() const
{
	return m_name;
}

char Player::getSymbol() const
{
	return m_symbol;
}
