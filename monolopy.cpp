#include "monolopy.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[MAX_PLAYER], int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		Players.push_back(make_tuple(names[i], 6000));
	}
	Fields.push_back(make_tuple("Ford", Monopoly::AUTO, AVAILABLE, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, AVAILABLE, false));
	Fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHER, AVAILABLE, false));
	Fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, AVAILABLE, false));
	Fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, AVAILABLE, false));
	Fields.push_back(make_tuple("Prison", Monopoly::PRISON, AVAILABLE, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, AVAILABLE, false));
	Fields.push_back(make_tuple("TESLA", Monopoly::AUTO, AVAILABLE, false));
}

std::list<std::tuple<std::string, int>>* Monopoly::GetPlayersList()
{
	return &Players;
}

std::list<std::tuple<std::string, Monopoly::Type, int, bool>>* Monopoly::GetFieldsList()
{
	return &Fields;
}

std::tuple<std::string, int> Monopoly::GetPlayerInfo(int m)
{
	list<std::tuple<std::string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	return *i;
}

bool Monopoly::Buy(int z, std::tuple<std::string, Type, int, bool> k)
{
	auto x = GetPlayerInfo(z);
	tuple<string, int> p;
	list<tuple<std::string, Type, int, bool>>::iterator i;
	list<tuple<string, int>>::iterator j = Players.begin();
	switch (get<FIELD_TYPE_INDEX>(k))
	{
	case AUTO:
		if (get<FIELD_OWNERSHIP_INDEX>(k))
			return false;
		p = make_tuple(get<PLAYER_NAME_INDEX>(x), get<PLAYER_MONEY_INDEX>(x) - AUTO_BUY_PRICE);
		k = make_tuple(get<FIELD_NAME_INDEX>(k), get<FIELD_TYPE_INDEX>(k), z, get<FIELD_OWNERSHIP_INDEX>(k));
		break;
	case FOOD:
		if (get<FIELD_OWNERSHIP_INDEX>(k))
			return false;
		p = make_tuple(get<PLAYER_NAME_INDEX>(x), get<PLAYER_MONEY_INDEX>(x) - FOOD_BUY_PRICE);
		k = make_tuple(get<FIELD_NAME_INDEX>(k), get<FIELD_TYPE_INDEX>(k), z, get<FIELD_OWNERSHIP_INDEX>(k));
		break;
	case TRAVEL:
		if (get<FIELD_OWNERSHIP_INDEX>(k))
			return false;
		p = make_tuple(get<PLAYER_NAME_INDEX>(x), get<PLAYER_MONEY_INDEX>(x) - TRAVEL_BUY_PRICE);
		k = make_tuple(get<FIELD_NAME_INDEX>(k), get<FIELD_TYPE_INDEX>(k), z, get<FIELD_OWNERSHIP_INDEX>(k));
		break;
	case CLOTHER:
		if (get<FIELD_OWNERSHIP_INDEX>(k))
			return false;
		p = make_tuple(get<PLAYER_NAME_INDEX>(x), get<PLAYER_MONEY_INDEX>(x) - CLOTHER_BUY_PRICE);
		k = make_tuple(get<FIELD_NAME_INDEX>(k), get<FIELD_TYPE_INDEX>(k), z, get<FIELD_OWNERSHIP_INDEX>(k));
		break;
	default:
		return false;
	};
	i = find_if(Fields.begin(), Fields.end(), [k](auto x) { return get<PLAYER_NAME_INDEX>(x) == get<FIELD_NAME_INDEX>(k); });
	*i = k;
	advance(j, z - 1);
	*j = p;
	return true;
}

std::tuple<std::string, Monopoly::Type, int, bool>  Monopoly::GetFieldByName(std::string l)
{
	std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::iterator i = find_if(Fields.begin(), Fields.end(), [l](std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return get<FIELD_NAME_INDEX>(x) == l;
		});
	return *i;
}

bool Monopoly::Renta(int m, std::tuple<std::string, Type, int, bool> c)
{
	tuple<string, int> z = GetPlayerInfo(m);
	tuple<string, int> o;

	switch (get<FIELD_TYPE_INDEX>(c))
	{
	case AUTO:
		if (!get<FIELD_OWNERSHIP_INDEX>(c))
			return false;
		o = GetPlayerInfo(get<FIELD_OWNERSHIP_INDEX>(c));
		o = make_tuple(get<PLAYER_NAME_INDEX>(o), get<PLAYER_MONEY_INDEX>(o) + AUTO_RENTAL_CHARGE);
		z = make_tuple(get<PLAYER_NAME_INDEX>(z), get<PLAYER_MONEY_INDEX>(z) - AUTO_RENTAL_CHARGE);
		break;
	case FOOD:
		if (!get<FIELD_OWNERSHIP_INDEX>(c))
			return false;
	case TRAVEL:
		if (!get<FIELD_OWNERSHIP_INDEX>(c))
			return false;
		o = GetPlayerInfo(get<FIELD_OWNERSHIP_INDEX>(c));
		o = make_tuple(get<PLAYER_NAME_INDEX>(o), get<PLAYER_MONEY_INDEX>(o) + TRAVEL_RENTAL_CHARGE);
		z = make_tuple(get<PLAYER_NAME_INDEX>(z), get<PLAYER_MONEY_INDEX>(z) - TRAVEL_RENTAL_CHARGE);
		break;
	case CLOTHER:
		if (!get<FIELD_OWNERSHIP_INDEX>(c))
			return false;
		o = GetPlayerInfo(get<FIELD_OWNERSHIP_INDEX>(c));
		o = make_tuple(get<PLAYER_NAME_INDEX>(o), get<PLAYER_MONEY_INDEX>(o) + CLOTHER_RENTAL_CHARGE);
		z = make_tuple(get<PLAYER_NAME_INDEX>(z), get<PLAYER_MONEY_INDEX>(z) - CLOTHER_RENTAL_CHARGE);
		break;
	case PRISON:
		z = make_tuple(get<PLAYER_NAME_INDEX>(z), get<PLAYER_MONEY_INDEX>(z) - PRISON_RENTAL_CHARGE);
		break;
	case BANK:
		z = make_tuple(get<PLAYER_NAME_INDEX>(z), get<PLAYER_MONEY_INDEX>(z) - BANK_RENTAL_CHARGE);
		break;
	default:
		return false;
	}
	list<tuple<string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	*i = z;
	i = find_if(Players.begin(), Players.end(), [o](auto x) { return get<PLAYER_NAME_INDEX>(x) == get<PLAYER_NAME_INDEX>(o); });
	*i = o;
	return true;
}



