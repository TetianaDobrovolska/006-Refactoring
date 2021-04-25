#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

#define MAX_PLAYERS 10


class Monopoly
{
public:

	enum Type
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHES,
		PRISON,
		BANK
	};
	Monopoly(std::string names[MAX_PLAYERS], int);
	std::list<std::tuple<std::string, int>> * GetPlayersList();
	std::list<std::tuple<std::string, Type, int, bool>> * GetFieldsList();
	std::tuple<std::string, int> GetPlayerInfo(int);
	bool Buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);
	bool Rental(int p, std::tuple<std::string, Type, int, bool> c);

private:

	static constexpr const int INITIAL_CAPITAL = 6000;
	static constexpr const int SELL_AUTO_PRICE = 500;
	static constexpr const int SELL_FOOD_PRICE = 250;
	static constexpr const int SELL_TRAVEL_PRICE = 700;
	static constexpr const int SELL_CLOTHES_PRICE = 100;
	static constexpr const int RENTAL_AUTO_PRICE = 250;
	static constexpr const int RENTAL_TRAVEL_PRICE = 250;
	static constexpr const int RENTAL_CLOTHES_PRICE = 250;
	static constexpr const int RENTAL_PRISON_PRICE = 1000;
	static constexpr const int RENTAL_BANK_PRICE = 700;

	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::list<std::tuple<std::string, int>> Players;

};

#endif
