#include "monopoly.hpp"
#include <algorithm>
#include <iostream>

using namespace ::std;

Monopoly::Monopoly(string names[MAX_PLAYERS],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		Players.push_back(new Person(names[i], INITIAL_CAPITAL));
	}
	const int owner = 0;
	
    Fields.push_back(new AutoField("Ford", owner, false));
	Fields.push_back(new FoodField("MCDonald", owner, false));
	Fields.push_back(new ClotherField("Lamoda", owner, false));
	Fields.push_back(new TravelField("Air Baltic", owner, false));
	Fields.push_back(new TravelField("Nordavia", owner, false));
	Fields.push_back(new PrisonField("Prison", owner, false));
	Fields.push_back(new FoodField("MCDonald", owner, false));
	Fields.push_back(new AutoField("TESLA", owner, false));
}

std::list<Person*>::const_iterator Monopoly::GetPlayersListBegin()
{
	return Players.cbegin();
}

std::list<Person*>::const_iterator Monopoly::GetPlayersListEnd()
{
	return Players.cend();
}

std::list<BaseField*>::const_iterator Monopoly::GetFieldsListBegin()
{
	return Fields.cbegin();
}

std::list<BaseField*>::const_iterator Monopoly::GetFieldsListEnd()
{
	return Fields.cend();
}

Person* Monopoly::GetPlayerInfo(int m)
{
    if (m ==0 ) return nullptr;
	list<Person*>::iterator i = Players.begin();
	advance(i, m - 1);
	return *i;
}

bool Monopoly::Buy(int z, BaseField* k)
{
    auto x = GetPlayerInfo(z);
	if (k->getOwner())
        return false;
    x->setMoney(x->getMoney() - k->getPrice());
    return k->Buy(z);
}

BaseField* Monopoly::GetFieldByName(const std::string& l)
{
	auto i = find_if(Fields.cbegin(), Fields.cend(),[l] (auto x) {
		return x->getName() == l;
	});
	return *i;
}

bool Monopoly::Renta(int m, BaseField* c)
{
	auto getMoneyFrom = GetPlayerInfo(m);
    auto owner = GetPlayerInfo(c->getOwner());
    return c->Renta(getMoneyFrom, owner);
}


