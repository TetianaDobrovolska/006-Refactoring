#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

class Monopoly
{
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

public:
	enum class FieldType : uint8_t
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};
	using FieldTuple = std::tuple<std::string, Monopoly::FieldType, int, bool>;
	using PlayerTuple = std::tuple<std::string, int>;
	using PlayerList = std::list<PlayerTuple>;
	using FieldList = std::list<FieldTuple>;

	Monopoly(std::string names[MAX_PLAYER], int);
	bool Buy(int playerIndex, FieldTuple field);
	bool Renta(int playerIndex, FieldTuple field);
	PlayerList* GetPlayersList();
	FieldList* GetFieldsList();
	FieldTuple GetFieldByName(std::string);
	PlayerTuple  GetPlayerInfo(int);

private:

	FieldList _fields;
	PlayerList _players;
};
#endif