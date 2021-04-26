#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

namespace monopoly::constannts {
static const int START_BALANCE_ = 6000;
static const int COMPANY_START_BALANCE_ = 0;
}

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
	enum Type
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};

    Monopoly(std::string names[COMPANY_NUMBER_],int);
	std::list<std::tuple<std::string,int>> *	GetPlayersList();
	std::list<std::tuple<std::string, Type, int,bool>> * GetFieldsList();
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::list<std::tuple<std::string, int>> Players;
	std::tuple<std::string, int>  GetPlayerInfo(int);	 
	bool Buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	
	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);
	
};

#endif
