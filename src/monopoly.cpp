#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlayers)
{
	const std::string fieldFord = "Ford";
	const std::string fieldMCDonald = "MCDonald";
	const std::string fieldLamoda = "Lamoda";
	const std::string fieldAirBaltic = "Air Baltic";
	const std::string fieldNordavia = "Nordavia";
	const std::string fieldPrison = "Prison";
	const std::string fieldTesla = "TESLA";

	const int initialPlayer = 0;

	for (int i = 0; i < countPlayers; i++)
	{
		Players.push_back(make_tuple(names[i], PLAYER_START_MONEY));
	}
	Fields.push_back(make_tuple(fieldFord, Monopoly::AUTO, initialPlayer, false));
	Fields.push_back(make_tuple(fieldMCDonald, Monopoly::FOOD, initialPlayer, false));
	Fields.push_back(make_tuple(fieldLamoda, Monopoly::CLOTHER, initialPlayer, false));
	Fields.push_back(make_tuple(fieldAirBaltic, Monopoly::TRAVEL, initialPlayer, false));
	Fields.push_back(make_tuple(fieldNordavia, Monopoly::TRAVEL, initialPlayer, false));
	Fields.push_back(make_tuple(fieldPrison, Monopoly::PRISON, initialPlayer, false));
	Fields.push_back(make_tuple(fieldMCDonald, Monopoly::FOOD, initialPlayer, false));
	Fields.push_back(make_tuple(fieldTesla, Monopoly::AUTO, initialPlayer, false));
}

std::list<std::tuple<std::string, int>>::const_iterator Monopoly::GetPlayersListCbegin()
{
	return Players.cbegin();
}

std::list<std::tuple<std::string, int>>::const_iterator Monopoly::GetPlayersListCend()
{
	return Players.cend();
}

std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::const_iterator Monopoly::GetFieldsListCbegin()
{
	return Fields.cbegin();
}

std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::const_iterator Monopoly::GetFieldsListCend()
{
	return Fields.cend();
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
	switch (get<1>(k))
	{
	case AUTO:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - AUTO_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case FOOD:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - FOOD_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case TRAVEL:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - TRAVEL_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case CLOTHER:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - CLOTHER_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	default:
		return false;
	};
	i = find_if(Fields.begin(), Fields.end(), [k](auto x) { return get<0>(x) == get<0>(k); });
	*i = k;
    advance(j, z-1);
	*j = p;
	return true;
}

std::tuple<std::string, Monopoly::Type, int, bool>  Monopoly::GetFieldByName(std::string l)
{
	std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::iterator i = find_if(Fields.begin(), Fields.end(),[l] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return get<0>(x) == l;
	});
	return *i;
}

bool Monopoly::Renta(int m, std::tuple<std::string, Type, int, bool> c)
{
	tuple<string, int> z = GetPlayerInfo(m);
	tuple<string, int> o;

	switch (get<1>(c))
	{
	case AUTO:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + AUTO_RENTA);
		z = make_tuple(get<0>(z), get<1>(z) - AUTO_RENTA);
		break;
	case FOOD:
		if (!get<2>(c))
			return false;
	case TRAVEL:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + TRAVEL_RENTA);
		z = make_tuple(get<0>(z), get<1>(z) - TRAVEL_RENTA);
		break;
	case CLOTHER:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + CLOTHER_RENTA);
		z = make_tuple(get<0>(z), get<1>(z) - CLOTHER_RENTA);
		break;
	case PRISON:
		z = make_tuple(get<0>(z), get<1>(z) - PRISON_PAYMENT);
		break;
	case BANK:
		z = make_tuple(get<0>(z), get<1>(z) - BANK_PAYMENT);
		break;
	default:
		return false;
	}
	list<tuple<string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	*i = z;
	i = find_if(Players.begin(), Players.end(), [o](auto x) { return get<0>(x) == get<0>(o); });
	*i = o;
	return true;
}


