#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

class Monopoly {
public:
    enum Type {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHES,
        PRISON,
        BANK
	};

    Monopoly(std::string names[10], int countPlayers);
    bool buy(int playerId, std::tuple<std::string, Type, int, bool> field);
    bool rent(int playerId, std::tuple<std::string, Type, int, bool> field);

    std::list<std::tuple<std::string,int>>* getPlayersList();
    std::list<std::tuple<std::string, Type, int,bool>>* getFieldsList();
    std::tuple<std::string, int> getPlayerInfo(int playerIndex);
    std::tuple<std::string, Type, int, bool> getFieldByName(std::string field);

private:
    std::list<std::tuple<std::string, Type, int, bool>> fields;
    std::list<std::tuple<std::string, int>> players;
};

#endif
