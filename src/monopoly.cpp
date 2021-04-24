#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10], int countPlayers)
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
		Players.push_back(Player(names[i], PLAYER_START_MONEY));
	}
	Fields.push_back(Field(fieldFord, Field::AUTO, initialPlayer, false));
	Fields.push_back(Field(fieldMCDonald, Field::FOOD, initialPlayer, false));
	Fields.push_back(Field(fieldLamoda, Field::CLOTHER, initialPlayer, false));
	Fields.push_back(Field(fieldAirBaltic, Field::TRAVEL, initialPlayer, false));
	Fields.push_back(Field(fieldNordavia, Field::TRAVEL, initialPlayer, false));
	Fields.push_back(Field(fieldPrison, Field::PRISON, initialPlayer, false));
	Fields.push_back(Field(fieldMCDonald, Field::FOOD, initialPlayer, false));
	Fields.push_back(Field(fieldTesla, Field::AUTO, initialPlayer, false));
}

std::list<Player>::const_iterator Monopoly::GetPlayersListCbegin()
{
	return Players.cbegin();
}

std::list<Player>::const_iterator Monopoly::GetPlayersListCend()
{
	return Players.cend();
}

std::list<Field>::const_iterator Monopoly::GetFieldsListCbegin()
{
	return Fields.cbegin();
}

std::list<Field>::const_iterator Monopoly::GetFieldsListCend()
{
	return Fields.cend();
}

Player Monopoly::GetPlayerInfo(int index)
{
	list<Player>::iterator i = Players.begin();
	advance(i, index - 1);
	return *i;
}

bool Monopoly::Buy(int index, Field& k)
{
	auto x = GetPlayerInfo(index);
	Player p;
	list<Field>::iterator i;
	list<Player>::iterator j = Players.begin();
	switch (k.GetType())
	{
	case Field::AUTO:
		if (k.GetOwnerIndex())
			return false;
		p = Player(x.GetName(), x.GetMoney() - AUTO_PRICE);
		k = Field(k.GetCompanyName(), k.GetType(), index, k.GetOwnerIndex());
		break;
	case Field::FOOD:
		if (k.GetOwnerIndex())
			return false;
		p = Player(x.GetName(), x.GetMoney() - FOOD_PRICE);
		k = Field(k.GetCompanyName(), k.GetType(), index, k.GetOwnerIndex());
		break;
	case Field::TRAVEL:
		if (k.GetOwnerIndex())
			return false;
		p = Player(x.GetName(), x.GetMoney() - TRAVEL_PRICE);
		k = Field(k.GetCompanyName(), k.GetType(), index, k.GetOwnerIndex());
		break;
	case Field::CLOTHER:
		if (k.GetOwnerIndex())
			return false;
		p = Player(x.GetName(), x.GetMoney() - CLOTHER_PRICE);
		k = Field(k.GetCompanyName(), k.GetType(), index, k.GetOwnerIndex());
		break;
	default:
		return false;
	};
	i = find_if(Fields.begin(), Fields.end(), [k](auto x) { return x.GetCompanyName() == k.GetCompanyName(); });
	*i = k;
    advance(j, index-1);
	*j = p;
	return true;
}

Field Monopoly::GetFieldByName(const std::string& l)
{
	std::list<Field>::const_iterator i = find_if(Fields.cbegin(), Fields.cend(), [l](Field x) {
		return x.GetCompanyName() == l;
	});
	return *i;
}

bool Monopoly::Renta(int m, const Field& c)
{
	Player z = GetPlayerInfo(m);
	Player o;

	switch (c.GetType())
	{
	case Field::AUTO:
		if (!c.GetOwnerIndex())
			return false;
		o = GetPlayerInfo(c.GetOwnerIndex());
		o = Player(o.GetName(), o.GetMoney() + AUTO_RENTA);
		z = Player(z.GetName(), z.GetMoney() - AUTO_RENTA);
		break;
	case Field::FOOD:
		if (!c.GetOwnerIndex())
			return false;
	case Field::TRAVEL:
		if (!c.GetOwnerIndex())
			return false;
		o = GetPlayerInfo(c.GetOwnerIndex());
		o = Player(o.GetName(), o.GetMoney() + TRAVEL_RENTA);
		z = Player(z.GetName(), z.GetMoney() - TRAVEL_RENTA);
		break;
	case Field::CLOTHER:
		if (!c.GetOwnerIndex())
			return false;
		o = GetPlayerInfo(c.GetOwnerIndex());
		o = Player(o.GetName(), o.GetMoney() + CLOTHER_RENTA);
		z = Player(z.GetName(), z.GetMoney() - CLOTHER_RENTA);
		break;
	case Field::PRISON:
		z = Player(z.GetName(), z.GetMoney() - PRISON_PAYMENT);
		break;
	case Field::BANK:
		z = Player(z.GetName(), z.GetMoney() - BANK_PAYMENT);
		break;
	default:
		return false;
	}
	list<Player>::iterator i = Players.begin();
	advance(i, m - 1);
	*i = z;
	i = find_if(Players.begin(), Players.end(), [o](auto x) { return x.GetName() == o.GetName(); });
	*i = o;
	return true;
}
