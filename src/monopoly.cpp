#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Field::Field(){
    name_ = "";
    type_ = Field::Type::PRISON;
    id_ = 0;
}

Field::Field(const std::string& name, const Type& type, const int& owner){
    name_ = name;
    type_ = type;
    id_ = owner;
}

int Field::getId() const {
    return id_;
}

std::string Field::getName() const {
    return name_;
}

Field::Type Field::getType() const {
    return type_;
}

Monopoly::Monopoly(string names[COMPANY_NUMBER_],int countPlaers)
{
    const int START_BALANCE = 0;
	for (int i = 0; i < countPlaers; i++)
	{
        Players.push_back(make_tuple(names[i], START_BALANCE));
	}

    fields_.push_back(Field("Ford", Field::Type::AUTO, START_BALANCE));
    fields_.push_back(Field("MCDonald", Field::Type::FOOD, START_BALANCE));
    fields_.push_back(Field("Lamoda", Field::Type::CLOTHER, START_BALANCE));
    fields_.push_back(Field("Air Baltic", Field::Type::TRAVEL, START_BALANCE));
    fields_.push_back(Field("Nordavia", Field::Type::TRAVEL, START_BALANCE));
    fields_.push_back(Field("Prison", Field::Type::PRISON, START_BALANCE));
    fields_.push_back(Field("MCDonald", Field::Type::FOOD, START_BALANCE));
    fields_.push_back(Field("TESLA", Field::Type::AUTO, START_BALANCE));
}

std::list<std::tuple<std::string, int>> * Monopoly::GetPlayersList()
{
	return &Players;
}

FieldIterator Monopoly::GetFieldsList()
{
    return fields_.begin();
}

std::tuple<std::string, int> Monopoly::GetPlayerInfo(int m)
{
	list<std::tuple<std::string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	return *i;
}

bool Monopoly::Buy(int z, Field& field)
{
	auto x = GetPlayerInfo(z);
	tuple<string, int> p;
    list<tuple<string, int>>::iterator j = Players.begin();
    switch (field.getType())
	{
    case Field::Type::AUTO:
        if (field.getId())
			return false;
        p = make_tuple(get<0>(x), get<1>(x) - PRICE_AUTO_);
        field = Field(field.getName(), field.getType(), z);
		break;
    case Field::Type::FOOD:
        if (field.getId())
			return false;
        p = make_tuple(get<0>(x), get<1>(x) - PRICE_FOOD_);
        field = Field(field.getName(), field.getType(), z);
		break;
    case Field::Type::TRAVEL:
        if (field.getId())
			return false;
        p = make_tuple(get<0>(x), get<1>(x) - PRICE_TRAVEL_);
        field = Field(field.getName(), field.getType(), z);
		break;
    case Field::Type::CLOTHER:
        if (field.getId())
			return false;
        p = make_tuple(get<0>(x), get<1>(x) - PRICE_CLOTHER_);
        field = Field(field.getName(), field.getType(), z);
		break;
	default:
		return false;
	};
    FieldIterator i = find_if(fields_.begin(), fields_.end(), [field](Field x) {
            return x.getName() == field.getName(); });
    *i = field;
    advance(j, z-1);
	*j = p;
	return true;
}

FieldIterator Monopoly::GetFieldByName(const std::string& name)
{
    FieldIterator i = find_if(fields_.begin(), fields_.end(),[name] (Field field) {
        return field.getName() == name;
    });
    return i;
}

bool Monopoly::Renta(int m, const Field& field)
{
	tuple<string, int> z = GetPlayerInfo(m);
	tuple<string, int> o;

    switch (field.getType())
	{
    case Field::Type::AUTO:
        if (!field.getId())
			return false;
        o = GetPlayerInfo(field.getId());
        o = make_tuple(get<0>(o), get<1>(o) + RENT_AUTO_);
        z = make_tuple(get<0>(z), get<1>(z) - RENT_AUTO_);
		break;
    case Field::Type::FOOD:
        if (!field.getId())
			return false;
    case Field::Type::TRAVEL:
        if (!field.getId())
			return false;
        o = GetPlayerInfo(field.getId());
        o = make_tuple(get<0>(o), get<1>(o) + RENT_TRAVEL_);
        z = make_tuple(get<0>(z), get<1>(z) - RENT_TRAVEL_);
		break;
    case Field::Type::CLOTHER:
        if (!field.getId())
			return false;
        o = GetPlayerInfo(field.getId());
        o = make_tuple(get<0>(o), get<1>(o) + RENT_CLOTHER_);
        z = make_tuple(get<0>(z), get<1>(z) - RENT_CLOTHER_);
		break;
    case Field::Type::PRISON:
        z = make_tuple(get<0>(z), get<1>(z) - RENT_PRISON_);
		break;
    case Field::Type::BANK:
        z = make_tuple(get<0>(z), get<1>(z) - RENT_BANK_);
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

Fields::iterator Monopoly::FieldsEnd(){
    return fields_.end();
}

