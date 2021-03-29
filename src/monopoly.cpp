#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

const int BEGIN_BUDGET = 6000;

const int FREI_ID = 0;

const int DEFAULT_AUTO_PRICE = 500;
const int DEFAULT_AUTO_RENTA = 250;
const int DEFAULT_FOOD_PRICE = 250;
const int DEFAULT_FOOD_RENTA = 0;
const int DEFAULT_TRAVEL_PRICE = 700;
const int DEFAULT_TRAVEL_RENTA = 250;
const int DEFAULT_CLOTHER_PRICE = 100;
const int DEFAULT_CLOTHER_RENTA = 250;

const int PAYMENT_PRISON = 1000;
const int PAYMENT_BANK = 700;

Player::Player()
{
    name = "";
    playerId = FREI_ID;
    budget = 0;
}

Player::Player(std::string name, int playerId, int budget)
{
    this->name = name;
    this->playerId = playerId;
    this->budget = budget;
}

std::string Player::getName() const
{
    return name;
}

int Player::getPlayerId() const
{
    return playerId;
}

void Player::addMoney(int value)
{
    budget += value;
}

void Player::deductMoney(int value)
{
    budget = value >= budget ? 0 : budget - value;
}

int Player::getBudget() const
{
    return budget;
}

Company::Company(std::string name, Type companyType, int buyPrice, int rentaPrice)
{
    this->name = name;
    this->companyType = companyType;
    this->buyPrice = buyPrice;
    this->rentaPrice = rentaPrice;
    ownerId = FREI_ID;
}

std::string Company::getName() const
{
    return name;
}

Company::Type Company::getType() const
{
    return companyType;
}

int Company::getBuyPrice() const
{
    return buyPrice;
}

int Company::getRentaPrice() const
{
    return rentaPrice;
}

int Company::getOwnerId() const
{
    return ownerId;
}

void Company::setOwnerId(int ownerId)
{
    this->ownerId = ownerId;
}

Monopoly::Monopoly(string names[10],int countPlaers)
{
    for (int i = 0; i < countPlaers; i++)
    {
        Players.push_back(Player(names[i], i + 1, BEGIN_BUDGET));
    }
    Fields.push_back(Company("Ford", Company::AUTO, DEFAULT_AUTO_PRICE, DEFAULT_AUTO_RENTA));
    Fields.push_back(Company("MCDonald", Company::FOOD, DEFAULT_FOOD_PRICE, DEFAULT_FOOD_RENTA));
    Fields.push_back(Company("Lamoda", Company::CLOTHER, DEFAULT_CLOTHER_PRICE, DEFAULT_CLOTHER_RENTA));
    Fields.push_back(Company("Air Baltic", Company::TRAVEL, DEFAULT_TRAVEL_PRICE, DEFAULT_TRAVEL_RENTA));
    Fields.push_back(Company("Nordavia", Company::TRAVEL, DEFAULT_TRAVEL_PRICE, DEFAULT_TRAVEL_RENTA));
    Fields.push_back(Company("Prison", Company::PRISON, PAYMENT_PRISON, PAYMENT_PRISON));
    Fields.push_back(Company("MCDonald", Company::FOOD, DEFAULT_FOOD_PRICE, DEFAULT_FOOD_RENTA));
    Fields.push_back(Company("TESLA", Company::AUTO, DEFAULT_AUTO_PRICE, DEFAULT_AUTO_RENTA));
}

std::list<Player> Monopoly::GetPlayersList()
{
    std::list<Player> copiedPlayersList(Players);
    return copiedPlayersList;
}

std::list<Company> Monopoly::GetFieldsList()
{
    std::list<Company> copiedFieldList(Fields);
    return copiedFieldList;
}

Player Monopoly::GetPlayerInfo(int m)
{
    list<Player>::iterator i = Players.begin();
    advance(i, m - 1);
    return *i;
}

bool Monopoly::Buy(int z, Company k)
{
    auto x = GetPlayerInfo(z);
    
    if (k.getOwnerId() != FREI_ID) return false;
    
    switch (k.getType())
    {
    case Company::AUTO:
    case Company::FOOD:
    case Company::TRAVEL:
    case Company::CLOTHER:
        x.deductMoney(k.getBuyPrice());
        k.setOwnerId(x.getPlayerId());
        break;
    default:
        return false;
    };

    list<Company>::iterator i;
    i = find_if(Fields.begin(), Fields.end(), [k](auto c) { return c.getName() == k.getName(); });
    *i = k;

    list<Player>::iterator j = Players.begin();
    advance(j, z-1);
    *j = x;
    return true;
}

Company Monopoly::GetFieldByName(std::string l)
{
    std::list<Company>::iterator i = find_if(Fields.begin(), Fields.end(),[l] (Company x) {
        return x.getName() == l;
    });
    return *i;
}

bool Monopoly::Renta(int m, Company c)
{
    Player z = GetPlayerInfo(m);
    Player o;

    switch (c.getType())
    {
    case Company::AUTO:
    case Company::FOOD:
    case Company::TRAVEL:
    case Company::CLOTHER:
        if (c.getOwnerId() == FREI_ID)
            return false;
        o = GetPlayerInfo(c.getOwnerId());
        o.addMoney(c.getRentaPrice());
        z.deductMoney(c.getRentaPrice());
        break;
    case Company::PRISON:
    case Company::BANK:
        z.deductMoney(c.getRentaPrice());
        break;
    default:
        return false;
    }

    list<Player>::iterator i = Players.begin();
    advance(i, m - 1);
    *i = z;
    i = find_if(Players.begin(), Players.end(), [o](auto x) { return x.getPlayerId() == o.getPlayerId(); });
    *i = o;
    return true;
}



