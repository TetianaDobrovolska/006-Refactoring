#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
	Player();
	Player(const std::string&, int);
	std::string GetName() const;
	int GetMoney() const;
private:
	std::string m_name;
	int m_money;
};

#endif
