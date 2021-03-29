#include "monolopy.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[MAX_PLAYER], int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		_players.push_back(make_tuple(names[i], 6000));
	}
	_fields.push_back(make_tuple("Ford", FieldType::AUTO, AVAILABLE, false));
	_fields.push_back(make_tuple("MCDonald", FieldType::FOOD, AVAILABLE, false));
	_fields.push_back(make_tuple("Lamoda", FieldType::CLOTHER, AVAILABLE, false));
	_fields.push_back(make_tuple("Air Baltic", FieldType::TRAVEL, AVAILABLE, false));
	_fields.push_back(make_tuple("Nordavia", FieldType::TRAVEL, AVAILABLE, false));
	_fields.push_back(make_tuple("Prison", FieldType::PRISON, AVAILABLE, false));
	_fields.push_back(make_tuple("MCDonald", FieldType::FOOD, AVAILABLE, false));
	_fields.push_back(make_tuple("TESLA", FieldType::AUTO, AVAILABLE, false));
}

std::list<std::tuple<std::string, int>>* Monopoly::GetPlayersList()
{
	return &_players;
}

std::list<std::tuple<std::string, Monopoly::FieldType, int, bool>>* Monopoly::GetFieldsList()
{
	return &_fields;
}

Monopoly::PlayerTuple Monopoly::GetPlayerInfo(int playerIndex)
{
	PlayerList::iterator playerIterator = _players.begin();
	advance(playerIterator, playerIndex - 1);
	return *playerIterator;
}

bool Monopoly::Buy(int playerIndex, FieldTuple field)
{
	auto player = GetPlayerInfo(playerIndex);
	tuple<string, int> tempPlayer;
	FieldList::iterator fieldIterator;
	PlayerList::iterator playerIterator = _players.begin();
	switch (get<FIELD_TYPE_INDEX>(field))
	{
	case FieldType::AUTO:
		if (get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		tempPlayer = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - AUTO_BUY_PRICE);
		field = make_tuple(get<FIELD_NAME_INDEX>(field), get<FIELD_TYPE_INDEX>(field), playerIndex, get<FIELD_OWNERSHIP_INDEX>(field));
		break;
	case FieldType::FOOD:
		if (get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		tempPlayer = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - FOOD_BUY_PRICE);
		field = make_tuple(get<FIELD_NAME_INDEX>(field), get<FIELD_TYPE_INDEX>(field), playerIndex, get<FIELD_OWNERSHIP_INDEX>(field));
		break;
	case FieldType::TRAVEL:
		if (get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		tempPlayer = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - TRAVEL_BUY_PRICE);
		field = make_tuple(get<FIELD_NAME_INDEX>(field), get<FIELD_TYPE_INDEX>(field), playerIndex, get<FIELD_OWNERSHIP_INDEX>(field));
		break;
	case FieldType::CLOTHER:
		if (get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		tempPlayer = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - CLOTHER_BUY_PRICE);
		field = make_tuple(get<FIELD_NAME_INDEX>(field), get<FIELD_TYPE_INDEX>(field), playerIndex, get<FIELD_OWNERSHIP_INDEX>(field));
		break;
	default:
		return false;
	};
	fieldIterator = find_if(_fields.begin(), _fields.end(), [field](auto player) { return get<PLAYER_NAME_INDEX>(player) == get<FIELD_NAME_INDEX>(field); });
	*fieldIterator = field;
	advance(playerIterator, playerIndex - 1);
	*playerIterator = tempPlayer;
	return true;
}

Monopoly::FieldTuple  Monopoly::GetFieldByName(std::string fieldName)
{
	FieldList::iterator fieldListIterator = find_if(_fields.begin(), _fields.end(), [fieldName](FieldTuple field) {
		return get<FIELD_NAME_INDEX>(field) == fieldName;
		});
	return *fieldListIterator;
}

bool Monopoly::Renta(int playerIndex, FieldTuple field)
{
	tuple<string, int> player = GetPlayerInfo(playerIndex);
	tuple<string, int> ownerPlayer;

	switch (get<FIELD_TYPE_INDEX>(field))
	{
	case FieldType::AUTO:
		if (!get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		ownerPlayer = GetPlayerInfo(get<FIELD_OWNERSHIP_INDEX>(field));
		ownerPlayer = make_tuple(get<PLAYER_NAME_INDEX>(ownerPlayer), get<PLAYER_MONEY_INDEX>(ownerPlayer) + AUTO_RENTAL_CHARGE);
		player = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - AUTO_RENTAL_CHARGE);
		break;
	case FieldType::FOOD:
		if (!get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
	case FieldType::TRAVEL:
		if (!get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		ownerPlayer = GetPlayerInfo(get<FIELD_OWNERSHIP_INDEX>(field));
		ownerPlayer = make_tuple(get<PLAYER_NAME_INDEX>(ownerPlayer), get<PLAYER_MONEY_INDEX>(ownerPlayer) + TRAVEL_RENTAL_CHARGE);
		player = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - TRAVEL_RENTAL_CHARGE);
		break;
	case FieldType::CLOTHER:
		if (!get<FIELD_OWNERSHIP_INDEX>(field))
			return false;
		ownerPlayer = GetPlayerInfo(get<FIELD_OWNERSHIP_INDEX>(field));
		ownerPlayer = make_tuple(get<PLAYER_NAME_INDEX>(ownerPlayer), get<PLAYER_MONEY_INDEX>(ownerPlayer) + CLOTHER_RENTAL_CHARGE);
		player = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - CLOTHER_RENTAL_CHARGE);
		break;
	case FieldType::PRISON:
		player = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - PRISON_RENTAL_CHARGE);
		break;
	case FieldType::BANK:
		player = make_tuple(get<PLAYER_NAME_INDEX>(player), get<PLAYER_MONEY_INDEX>(player) - BANK_RENTAL_CHARGE);
		break;
	default:
		return false;
	}
	PlayerList::iterator playerIterator = _players.begin();
	advance(playerIterator, playerIndex - 1);
	*playerIterator = player;
	playerIterator = find_if(_players.begin(), _players.end(), [ownerPlayer](auto player) { return get<PLAYER_NAME_INDEX>(x) == get<PLAYER_NAME_INDEX>(ownerPlayer); });
	*playerIterator = ownerPlayer;
	return true;
}



