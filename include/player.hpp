#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
public:
    Player(std::string, int);

    std::string name() const { return m_name; }

    int money() const { return m_money; }
    void setMoney(int money) { m_money = money; }

private:
    std::string m_name;
    int m_money;
};

#endif