#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

const int BEGIN_BUDGET = 6000;

const int PROPERTY_FREI = 0;

const int DEFAULT_AUTO_PRICE = 500;
const int DEFAULT_AUTO_RENTA = 250;
const int DEFAULT_FOOD_PRICE = 250;
const int DEFAULT_FOOD_RENTA = 0;
const int DEFAULT_TRAVEL_PRICE = 700;
const int DEFAULT_TRAVEL_RENTA = 250;
const int DEFAULT_CLOTHER_PRICE = 100;
const int DEFAULT_CLOTHER_RENTA = 250;

const int PAYMENT_PRISON = 1000;
const int PAYMENT_BANK = 700;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		Players.push_back(make_tuple(names[i], BEGIN_BUDGET));
	}
	Fields.push_back(make_tuple("Ford", Monopoly::AUTO, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHER, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("Prison", Monopoly::PRISON, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, PROPERTY_FREI, false));
	Fields.push_back(make_tuple("TESLA", Monopoly::AUTO, PROPERTY_FREI, false));
}

std::list<std::tuple<std::string, int>> Monopoly::GetPlayersList()
{
    std::list<std::tuple<std::string, int>> copiedPlayersList(Players);
    return copiedPlayersList;
}

std::list<std::tuple<std::string, Monopoly::Type,int,bool>> Monopoly::GetFieldsList()
{
    std::list<std::tuple<std::string, Monopoly::Type,int,bool>> copiedFieldList(Fields);
    return copiedFieldList;
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
		p = make_tuple(get<0>(x), get<1>(x) - DEFAULT_AUTO_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, true);
		break;
	case FOOD:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - DEFAULT_AUTO_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, true);
		break;
	case TRAVEL:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - DEFAULT_TRAVEL_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, true);
		break;
	case CLOTHER:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - DEFAULT_CLOTHER_PRICE);
		k = make_tuple(get<0>(k), get<1>(k), z, true);
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
		o = make_tuple(get<0>(o), get<1>(o) + DEFAULT_AUTO_RENTA);
		z = make_tuple(get<0>(z), get<1>(z) - DEFAULT_AUTO_RENTA);
		break;
	case FOOD:
		if (!get<2>(c))
			return false;
	case TRAVEL:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + DEFAULT_TRAVEL_RENTA);
		z = make_tuple(get<0>(z), get<1>(z) - DEFAULT_TRAVEL_RENTA);
		break;
	case CLOTHER:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + DEFAULT_CLOTHER_RENTA);
		z = make_tuple(get<0>(z), get<1>(z) - DEFAULT_CLOTHER_RENTA);
		break;
	case PRISON:
		z = make_tuple(get<0>(z), get<1>(z) - PAYMENT_PRISON);
		break;
	case BANK:
		z = make_tuple(get<0>(z), get<1>(z) - PAYMENT_BANK);
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



