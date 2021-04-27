#include "monopoly.hpp"
#include <algorithm>

using namespace std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	int startMoney = 6000;

	for (int i = 0; i < countPlaers; i++)
	{
		Players.push_back(make_tuple(names[i], startMoney));
	}
	Fields.push_back(make_tuple("Ford", Monopoly::AUTO, 0, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
	Fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHER, 0, false));
	Fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, 0, false));
	Fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, 0, false));
	Fields.push_back(make_tuple("Prison", Monopoly::PRISON, 0, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
	Fields.push_back(make_tuple("TESLA", Monopoly::AUTO, 0, false));
}

const list<tuple<string, int>> * Monopoly::GetPlayersList()
{
	return &Players;
}

const list<tuple<string, Monopoly::Type,int,bool>> * Monopoly::GetFieldsList()
{
	return &Fields;
}

tuple<string, int> Monopoly::GetPlayerInfo(int m)
{
	list<tuple<string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	return *i;
}

bool Monopoly::Buy(int playerId, tuple<string, Type, int, bool> field)
{
	auto player = GetPlayerInfo(playerId);

	int autoPrice = 500;
	int foodPrice = 250;
	int travelPrice = 700;
	int clotherPrice = 100;

	if (get<2>(field))
			return false;

	switch (get<1>(field))
	{
	case AUTO:
		UpdatePlayerCash(playerId, get<1>(player) - autoPrice);
		break;
	case FOOD:
		UpdatePlayerCash(playerId, get<1>(player) - foodPrice);
		break;
	case TRAVEL:
		UpdatePlayerCash(playerId, get<1>(player) - travelPrice);
		break;
	case CLOTHER:
		UpdatePlayerCash(playerId, get<1>(player) - clotherPrice);
		break;
	default:
		return false;
	};
	UpdateFieldOwner(get<0>(field), playerId);

	return true;
}

tuple<string, Monopoly::Type, int, bool>  Monopoly::GetFieldByName(string l)
{
	list<tuple<string, Monopoly::Type, int, bool>>::iterator i = find_if(Fields.begin(), Fields.end(),[l] (tuple<string, Monopoly::Type, int, bool> x) {
		return get<0>(x) == l;
	});
	return *i;
}

bool Monopoly::Renta(int playerPayerId, tuple<string, Type, int, bool> field)
{
	int playerOwnerId = get<2>(field);
	tuple<string, int> playerPayer = GetPlayerInfo(playerPayerId);
	tuple<string, int> playerOwner = GetPlayerInfo(playerOwnerId);

	int autoRentPrice = 250;
	int foodRentPrice = 250;
	int travelRentPrice = 250;
	int clotherRentPrice = 250;
	int prisonRentPrice = 1000;
	int bankRentPrice = 700;

	if (!playerOwnerId)
			return false;

	switch (get<1>(field))
	{
	case AUTO:
		UpdatePlayerCash(playerPayerId, get<1>(playerPayer) - autoRentPrice);
		UpdatePlayerCash(playerOwnerId, get<1>(playerOwner) + autoRentPrice);
		break;
	case FOOD:
		UpdatePlayerCash(playerPayerId, get<1>(playerPayer) - foodRentPrice);
		UpdatePlayerCash(playerOwnerId, get<1>(playerOwner) + foodRentPrice);
		break;
	case TRAVEL:
		UpdatePlayerCash(playerPayerId, get<1>(playerPayer) - travelRentPrice);
		UpdatePlayerCash(playerOwnerId, get<1>(playerOwner) + travelRentPrice);
		break;
	case CLOTHER:
		UpdatePlayerCash(playerPayerId, get<1>(playerPayer) - clotherRentPrice);
		UpdatePlayerCash(playerOwnerId, get<1>(playerOwner) + clotherRentPrice);
		break;
	case PRISON:
		UpdatePlayerCash(playerPayerId, get<1>(playerPayer) - prisonRentPrice);
		break;
	case BANK:
		UpdatePlayerCash(playerPayerId, get<1>(playerPayer) - bankRentPrice);
		break;
	default:
		return false;
	}

	return true;
}

void Monopoly::UpdatePlayerCash(int playerId, int newPlayerCash)
{
	list<tuple<string, int>>::iterator p = Players.begin();
	advance(p, playerId-1);

	tuple<string, int> newPlayerInfo = make_tuple(get<0>(*p), newPlayerCash);
	*p = newPlayerInfo;

}

void Monopoly::UpdateFieldOwner(string fieldName, int ownerId)
{
	list<tuple<string, Type, int, bool>>::iterator i;
	i = find_if(Fields.begin(), Fields.end(), [fieldName](auto x) { return get<0>(x) == fieldName; });
	*i = make_tuple(get<0>(*i), get<1>(*i), ownerId, get<3>(*i));
}
