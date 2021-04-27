#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
    Player();
    Player(const std::string& name_, const int& money);
    std::string getName() const;
    int getMoney() const;
    void setMoney(const int&);
private:
    std::string name_;
    int money_;
};

#endif // PLAYER_HPP
