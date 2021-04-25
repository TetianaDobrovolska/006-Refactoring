#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>

#include "player.h"

class Monopoly
{
private:
	static const int kMaxPlayerCount = 10;
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
    enum Brand
    {
        FORD,
        MCDONALD,
        LAMODA,
        AIR_BALTIC,
        NORDAVIA,
        TESLA,
        PRISON
    };
    Monopoly(const std::string names[kMaxPlayerCount], const int&);

    const std::list<Player>& GetPlayersList() const;
    const std::list<std::tuple<std::string, Type, int, bool>>& GetFieldsList() const;
    const Player& GetPlayerInfo(const int&) const;
    const std::tuple<std::string, Type, int, bool>& GetFieldByName(const std::string&) const;

	bool Buy(const int& p, std::tuple<std::string, Type, int, bool>&);
	bool Renta(const int& p, std::tuple<std::string, Type, int, bool>&);

private:
    std::list<Player> Players;
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
};

#endif
