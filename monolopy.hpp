#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>
#include <map>

#define MAX_PLAYERS 10

class Monopoly
{
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

    Monopoly(std::string names[MAX_PLAYERS],int);
    std::list<std::tuple<std::string,int>> GetPlayersList();
    std::list<std::tuple<std::string, Type, int,bool>> GetFieldsList();
    std::tuple<std::string, int>  GetPlayerInfo(int);
    bool Buy(int p,std::tuple<std::string, Type, int, bool>);
    std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);
    bool Renta(int p, std::tuple<std::string, Type, int, bool>c);

    static const int INITIAL_MONEY = 6000;
    static const int NOT_OWNED = 0;

    static const int SELL_PRICE_AUTO = 500;
    static const int SELL_PRICE_FOOD = 250;
    static const int SELL_PRICE_TRAVEL = 700;
    static const int SELL_PRICE_CLOTHER = 100;

    static const int RENT_PRICE_AUTO = 250;
    static const int RENT_PRICE_TRAVEL = 250;
    static const int RENT_PRICE_CLOTHER = 250;
    static const int RENT_PRICE_PRISON = 1000;
    static const int RENT_PRICE_BANK = 700;

private:
    std::list<std::tuple<std::string, Type, int, bool>> Fields;
    std::list<std::tuple<std::string, int>> Players;
};

#endif
