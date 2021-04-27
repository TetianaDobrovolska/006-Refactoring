#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

class Field;
class Player;
using Fields = std::list<Field>;
using Players = std::list<Player>;
using FieldIterator = std::list<Field>::iterator;
using PlayerIterator = std::list<Player>::iterator;

class Field {
public:
    enum class Type
    {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHER,
        PRISON,
        BANK
    };

    Field();
    Field(const std::string& name, const Type& type, const int& owner);
    std::string getName() const;
    Type getType() const;
    int getId() const;

private:
    std::string name_;
    Type type_;
    int id_;
};

class Player {
public:
    Player();
    Player(const std::string& name_, const int& money);
    std::string getName() const;
    int getMoney() const;
private:
    std::string name_;
    int money_;
};

class Monopoly
{
private:
    static const int COMPANY_NUMBER_ = 10;

    static const int PRICE_AUTO_ = 500;
    static const int PRICE_FOOD_ = 250;
    static const int PRICE_TRAVEL_ = 700;
    static const int PRICE_CLOTHER_ = 100;

    static const int RENT_AUTO_ = 250;
    static const int RENT_TRAVEL_ = 250;
    static const int RENT_CLOTHER_ = 250;
    static const int RENT_PRISON_ = 1000;
    static const int RENT_BANK_ = 700;

public:
    Monopoly(std::string names[COMPANY_NUMBER_],int);
    FieldIterator GetFieldsList();
    Fields::iterator FieldsEnd();
    Fields fields_;
    Players players_;
    PlayerIterator GetPlayersList();
    PlayerIterator PlayersEnd();
    Player  GetPlayerInfo(int);
    bool Buy(int, Field&);
    FieldIterator GetFieldByName(const std::string&);
    bool Renta(int, const Field&);
	
};

#endif
