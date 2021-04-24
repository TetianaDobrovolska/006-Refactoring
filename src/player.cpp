#include "player.hpp"

Player::Player()
{
	m_name = "";
	m_money = 0;
}

Player::Player(const std::string& name, int money) : m_name(name), m_money(money) {}

std::string Player::GetName() const
{
	return m_name;
}

int Player::GetMoney() const
{
	return m_money;
}
