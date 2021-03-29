#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

class Player {
public:
    Player();
    Player(std::string name, int playerId, int budget);

    std::string getName() const;
    int getPlayerId() const;
    void addMoney(int value);
    void deductMoney(int value);
    int getBudget() const;
private:
    std::string name;
    int playerId;
    int budget;
};

class Company {
public:
    enum Type
    {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHER,
        PRISON,
        BANK
    };

    Company(std::string name, Type companyType, int buyPrice, int rentaPrice);
    std::string getName() const;
    Type getType() const;
    int getBuyPrice() const;
    int getRentaPrice() const;
    int getOwnerId() const;
    void setOwnerId(int ownerId);

private:
    int buyPrice;
    int rentaPrice;
    std::string name;
    Type companyType;
    int ownerId;
};

class Monopoly
{
public:

    Monopoly(std::string names[10],int);

    std::list<Player> GetPlayersList();
    std::list<Company> GetFieldsList();

    Player GetPlayerInfo(int);	 
    Company GetFieldByName(std::string);

    bool Buy(int p, Company c);
    bool Renta(int p, Company c);
private: 
    std::list<Company> Fields;
    std::list<Player> Players;
	
};

#endif
