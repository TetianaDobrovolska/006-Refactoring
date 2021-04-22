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
        CLOTHES,
		PRISON,
		BANK
	};

    static constexpr const int startupCapital = 6000;

    static constexpr const int maxPlayersCount = 10;

    static constexpr const int rentalPriceAuto = 250;
    static constexpr const int rentalPriceTravel = 250;
    static constexpr const int rentalPriceClothes = 250;
    static constexpr const int rentalPricePrison = 1000;
    static constexpr const int rentalPriceBank = 700;

    static constexpr const int sellPriceAuto = 500;
    static constexpr const int sellPriceTravel = 700;
    static constexpr const int sellPriceClothes = 100;
    static constexpr const int sellPriceFood = 250;



	Monopoly(std::string names[10],int);
	std::list<std::tuple<std::string,int>> *	GetPlayersList();
    std::list<std::tuple<std::string, Type, int, bool>> * GetFieldsList();
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::list<std::tuple<std::string, int>> Players;
	std::tuple<std::string, int>  GetPlayerInfo(int);	 
	bool Buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	
	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);
};

#endif
