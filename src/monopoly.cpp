#include "monopoly.hpp"
#include "utils.hpp"
#include <algorithm>

using namespace std;

Monopoly::Monopoly(std::vector<std::string> names, int startMoney)
{
	for (auto n : names)
	{
		m_players.push_back(new Player(n, startMoney));
	}

	m_fields.push_back(new Field("Ford", Field::AUTO, NULL, false));
	m_fields.push_back(new Field("MCDonald", Field::FOOD, NULL, false));
	m_fields.push_back(new Field("Lamoda", Field::CLOTHER, NULL, false));
	m_fields.push_back(new Field("Air Baltic", Field::TRAVEL, NULL, false));
	m_fields.push_back(new Field("Nordavia", Field::TRAVEL, NULL, false));
	m_fields.push_back(new Field("Prison", Field::PRISON, NULL, true));
	m_fields.push_back(new Field("Bank", Field::BANK, NULL, true));
	m_fields.push_back(new Field("TESLA", Field::AUTO, NULL, false));

}

Monopoly::~Monopoly()
{
	for (auto i : m_players)
	{
		delete i;
	}

	for (auto i : m_fields)
	{
		delete i;
	}
	
	
}

bool Monopoly::byuField(Player *buyer, Field *desiredField) {
	if(desiredField->specialField())
		return false;
	
	Field::Types desireFieldType = desiredField->fieldType();
	int fieldCost = Utils::buyPrice[desireFieldType];

	desiredField->setFieldOwner(buyer);
	buyer->setMoney(buyer->money() - fieldCost);
	return true;
}

bool Monopoly::rentField(Player *activePlayer, Field *targetField) {
	Field::Types targetFieldType = targetField->fieldType();
	int penaltyCost = Utils::rentPrice[targetFieldType];

	Player *fieldOwner = targetField->fieldOwner();

	if (!targetField->specialField())
	{
		fieldOwner->setMoney(fieldOwner->money() + penaltyCost);
	}

	activePlayer->setMoney(activePlayer->money() - penaltyCost);

	return true;
}
