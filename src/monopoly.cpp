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

bool Monopoly::Buy(int playerIndex, const Field& field)
{
	if (field.GetOwnerIndex())
	{
		return false;
	}

	Player player = GetPlayerInfo(playerIndex);
	Player newPlayer;

	switch (field.GetType())
	{
	case Field::AUTO:
		newPlayer = Player(player.GetName(), player.GetMoney() - AUTO_PRICE);
		break;
	case Field::FOOD:
		newPlayer = Player(player.GetName(), player.GetMoney() - FOOD_PRICE);
		break;
	case Field::TRAVEL:
		newPlayer = Player(player.GetName(), player.GetMoney() - TRAVEL_PRICE);
		break;
	case Field::CLOTHER:
		newPlayer = Player(player.GetName(), player.GetMoney() - CLOTHER_PRICE);
		break;
	default:
		return false;
	};
	Field newField(field.GetCompanyName(), field.GetType(), playerIndex, field.GetOwnerIndex());
	auto fieldsIterator = find_if(Fields.begin(), Fields.end(), [newField](auto x) { return x.GetCompanyName() == newField.GetCompanyName(); });
	*fieldsIterator = newField;
	auto playersIterator = Players.begin();
	advance(playersIterator, playerIndex - 1);
	*playersIterator = newPlayer;
	return true;
}

Field Monopoly::GetFieldByName(const std::string& companyName)
{
	std::list<Field>::const_iterator i = find_if(Fields.cbegin(), Fields.cend(), [companyName](Field x) {
		return x.GetCompanyName() == companyName;
	});
	return *i;
}

bool Monopoly::Renta(int playerIndex, const Field& field)
{
	if ((field.GetType() == Field::AUTO ||
		field.GetType() == Field::FOOD ||
		field.GetType() == Field::TRAVEL ||
		field.GetType() == Field::CLOTHER) &&
		!field.GetOwnerIndex())
	{
		return false;
	}

	Player player = GetPlayerInfo(playerIndex);
	Player newPlayer;

	switch (field.GetType())
	{
	case Field::AUTO:
		CalcRenta(player, newPlayer, field, AUTO_RENTA);
		break;
	case Field::FOOD:
		break;
	case Field::TRAVEL:
		CalcRenta(player, newPlayer, field, TRAVEL_RENTA);
		break;
	case Field::CLOTHER:
		CalcRenta(player, newPlayer, field, CLOTHER_RENTA);
		break;
	case Field::PRISON:
		player = Player(player.GetName(), player.GetMoney() - PRISON_PAYMENT);
		break;
	case Field::BANK:
		player = Player(player.GetName(), player.GetMoney() - BANK_PAYMENT);
		break;
	default:
		return false;
	}
	auto iterator = Players.begin();
	advance(iterator, playerIndex - 1);
	*iterator = player;
	iterator = find_if(Players.begin(), Players.end(), [newPlayer](auto player) { return player.GetName() == newPlayer.GetName(); });
	*iterator = newPlayer;
	return true;
}

void Monopoly::CalcRenta(Player& player, Player& newPlayer, const Field& field, const int renta)
{
	newPlayer = GetPlayerInfo(field.GetOwnerIndex());
	newPlayer = Player(newPlayer.GetName(), newPlayer.GetMoney() + renta);
	player = Player(player.GetName(), player.GetMoney() - renta);
}
