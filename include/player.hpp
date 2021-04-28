#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
public:
	Player();
	Player(const std::string&, const char);
	std::string getName() const;
	char getSymbol() const;
private:
	char m_symbol;
	std::string m_name;
};

#endif // !PLAYER_HPP
