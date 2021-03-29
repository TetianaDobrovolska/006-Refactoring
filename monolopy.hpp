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
	Monopoly(std::string names[MAX_PLAYER], int);
	std::list<std::tuple<std::string, int>>* GetPlayersList();
	std::list<std::tuple<std::string, Type, int, bool>>* GetFieldsList();
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::list<std::tuple<std::string, int>> Players;
	std::tuple<std::string, int>  GetPlayerInfo(int);
	bool Buy(int p, std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);
	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);

private:
	static constexpr uint8_t MAX_PLAYER = 10U;
	static constexpr uint8_t AVAILABLE = 0U;

	static constexpr uint8_t FIELD_NAME_INDEX = 0U;
	static constexpr uint8_t FIELD_TYPE_INDEX = 1U;
	static constexpr uint8_t FIELD_OWNERSHIP_INDEX = 2U;

	static constexpr uint8_t PLAYER_NAME_INDEX = 0U;
	static constexpr uint8_t PLAYER_MONEY_INDEX = 1U;

	static constexpr uint16_t AUTO_BUY_PRICE = 500U;
	static constexpr uint16_t AUTO_RENTAL_CHARGE = 250U;
	static constexpr uint16_t FOOD_BUY_PRICE = 250U;
	static constexpr uint16_t FOOD_RENTAL_CHARGE = 0U;
	static constexpr uint16_t TRAVEL_BUY_PRICE = 700U;
	static constexpr uint16_t TRAVEL_RENTAL_CHARGE = 250U;
	static constexpr uint16_t CLOTHER_BUY_PRICE = 100U;
	static constexpr uint16_t CLOTHER_RENTAL_CHARGE = 250U;
	//static constexpr uint16_t PRISON_BUY_PRICE = 0U;
	static constexpr uint16_t PRISON_RENTAL_CHARGE = 1000U;
	//static constexpr uint16_t BANK_BUY_PRICE = 0U;
	static constexpr uint16_t BANK_RENTAL_CHARGE = 700U;

};

#endif