#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

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
	Monopoly(std::string names[10],int);
	std::list<std::tuple<std::string,int>> *	GetPlayersList();
	std::list<std::tuple<std::string, Type, int,bool>> * GetFieldsList();
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::list<std::tuple<std::string, int>> Players;
	std::tuple<std::string, int>  GetPlayerInfo(int);	 
	bool Buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	
	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);
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
};

#endif