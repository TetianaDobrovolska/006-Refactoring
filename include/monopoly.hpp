#ifndef MONOPOLY_HPP

#define MONOPOLY_HPP



#include <list>

#include <tuple>

#include <string>


#define MAX_PLAYERS_COUNT 10


class Monopoly

{

public:
	static constexpr const int INITIAL_CAPITAL = 6000;
	static constexpr const int INITIAL_OWNER = 0;

	static constexpr const int SELL_PRICE_AUTO = 500;
	static constexpr const int SELL_PRICE_FOOD = 250;
	static constexpr const int SELL_PRICE_TRAVEL = 700;
	static constexpr const int SELL_PRICE_CLOTHER = 100;

	static constexpr const int RENT_PRICE_AUTO = 250;
	static constexpr const int RENT_PRICE_TRAVEL = 250;
	static constexpr const int RENT_PRICE_CLOTHER = 250;
	static constexpr const int RENT_PRICE_PRISON = 1000;
	static constexpr const int RENT_PRICE_BANK = 700;


	enum Type

	{

		AUTO,

		FOOD,

		TRAVEL,

		CLOTHER,

		PRISON,

		BANK

	};

	Monopoly(std::string names[MAX_PLAYERS_COUNT], int);

	std::list<std::tuple<std::string,int>>* 	GetPlayersList();

	std::list<std::tuple<std::string, Type, int,bool>>*  GetFieldsList();

	std::tuple<std::string, int>  GetPlayerInfo(int);	 

	bool Buy(int p,std::tuple<std::string, Type, int, bool>);

	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	

	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);

private:

	std::list<std::tuple<std::string, int>> Players;

	std::list<std::tuple<std::string, Type, int, bool>> Fields;

	

};



#endif