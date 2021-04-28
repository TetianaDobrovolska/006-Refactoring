#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
//#include <tuple>
#include <string>

class Player
{
public:
    Player();
    Player (const std::string& name, const int& money);
    const std::string& GetName() const;
    const int& GetMoney() const;
private:
    std::string name;
    int money;

};

#endif
