#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>

#include "field.h"
#include "player.h"

class Monopoly
{
private:
    static constexpr int kMaxPlayerCount = 10;
    static constexpr int kBankIndex = 0;
    static constexpr int kStartMoney = 6000;
public:
    Monopoly(const std::string names[kMaxPlayerCount], const int&);

    const std::list<Player>& GetPlayersList() const;
    const std::list<Field*>& GetFieldsList() const;
    const Player& GetPlayerInfo(const int&) const;
    const Field& GetFieldByName(const Field::eBrand brand) const;

    bool Buy(const int& p, Field&);
    bool Renta(const int& p, Field&);

private:
    std::list<Player> Players;
    std::list<Field*> Fields;
};

#endif
