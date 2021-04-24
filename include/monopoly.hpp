#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

#include "player.hpp"
#include "field.hpp"

class Monopoly
{
public:
	Monopoly(std::string names[10], int);
	std::list<Player>::const_iterator GetPlayersListCbegin();
	std::list<Player>::const_iterator GetPlayersListCend();
	std::list<Field>::const_iterator GetFieldsListCbegin();
	std::list<Field>::const_iterator GetFieldsListCend();
	Player GetPlayerInfo(int);
	bool Buy(int, const Field&);
	Field GetFieldByName(const std::string&);
	bool Renta(int, const Field&);
private:
	static constexpr int PLAYER_START_MONEY = 6000;
	static const int AUTO_PRICE = 500;
	static const int FOOD_PRICE = 250;
	static const int TRAVEL_PRICE = 700;
	static const int CLOTHER_PRICE = 100;
	static const int AUTO_RENTA = 250;
	static const int TRAVEL_RENTA = 250;
	static const int CLOTHER_RENTA = 250;
	static const int PRISON_PAYMENT = 1000;
	static const int BANK_PAYMENT = 700;

	std::list<Field> Fields;
	std::list<Player> Players;

	void CalcRenta(Player&, Player&, const Field&, const int);
};

#endif