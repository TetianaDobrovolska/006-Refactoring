#include "monolopy.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[MAX_PLAYER], int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		_players.push_back(Player(names[i]));
	}

	_fields.push_back(new Auto("Ford"));
	_fields.push_back(new Food("MCDonald"));
	_fields.push_back(new Clother("Lamoda"));
	_fields.push_back(new Travel("Air Baltic"));
	_fields.push_back(new Travel("Nordavia"));
	_fields.push_back(new Prison("Prison"));
	_fields.push_back(new Food("MCDonald"));
	_fields.push_back(new Auto("TESLA"));
}

Field* Monopoly::GetFieldByName(std::string fieldName) const
{
	for (auto element : _fields)
	{
		if (element->getFieldName() == fieldName)
		{
			return element;
		}
	}
	return nullptr;
}

Player* Monopoly::GetPlayerByName(std::string playerName) const
{
	for (auto element : _players)
	{
		if (element.getPlayerName() == playerName)
		{
			return &element;
		}
	}
	return nullptr;
}

const Monopoly::PlayerVector* Monopoly::GetPlayers() const
{
	return &_players;
}


bool Monopoly::Buy(const std::string playerName, const std::string fieldName)
{
	Field* field = GetFieldByName(fieldName);
	if (field == nullptr)
		return false;
	if (field->getOwnershipName() != "")
		return false;

	Player* player	    = GetPlayerByName(playerName);
	uint16_t fieldPrice = field->getBuyingPrice();
	if (player->getPlayerBalance() < fieldPrice)
		return false;

	player->changePlayerBalance(fieldPrice);
	field->changeOwnership(playerName);

	return true;
}

bool Monopoly::Renta(const std::string playerName, const Field* field)
{
	Player* player = GetPlayerByName(playerName);

	std::string ownerName = field->getOwnershipName();
	if (ownerName == "")
		return false;
	Player* owner = GetPlayerByName(ownerName);
	const uint16_t rentalCost = field->getRentalCost();
	player->changePlayerBalance(-rentalCost);
	owner->changePlayerBalance(rentalCost);

	return true;
}



