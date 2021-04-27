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

Player::Player()
    :name_(""), money_(0)
{}

Player::Player(const string &name, const int& money)
    :name_(name), money_(money)
{}

int Player::getMoney() const {
    return money_;
}

std::string Player::getName() const {
    return name_;
}

Monopoly::Monopoly(string names[COMPANY_NUMBER_],int countPlaers)
{
    const int START_BALANCE = 6000;
	for (int i = 0; i < countPlaers; i++)
	{
        players_.push_back(Player(names[i], START_BALANCE));
	}

    const int INITIAL_CAPITAL = 0;
    fields_.push_back(Field("Ford", Field::Type::AUTO, INITIAL_CAPITAL));
    fields_.push_back(Field("MCDonald", Field::Type::FOOD, INITIAL_CAPITAL));
    fields_.push_back(Field("Lamoda", Field::Type::CLOTHER, INITIAL_CAPITAL));
    fields_.push_back(Field("Air Baltic", Field::Type::TRAVEL, INITIAL_CAPITAL));
    fields_.push_back(Field("Nordavia", Field::Type::TRAVEL, INITIAL_CAPITAL));
    fields_.push_back(Field("Prison", Field::Type::PRISON, INITIAL_CAPITAL));
    fields_.push_back(Field("MCDonald", Field::Type::FOOD, INITIAL_CAPITAL));
    fields_.push_back(Field("TESLA", Field::Type::AUTO, INITIAL_CAPITAL));
}

PlayerIterator Monopoly::GetPlayersList()
{
    return players_.begin();
}

FieldIterator Monopoly::GetFieldsList()
{
    return fields_.begin();
}

Player Monopoly::GetPlayerInfo(int id)
{
    PlayerIterator i = players_.begin();
    advance(i, id - 1);
	return *i;
}

bool Monopoly::Buy(int player_id, Field& field)
{
    auto player = GetPlayerInfo(player_id);
    Player player_tmp;
    PlayerIterator player_it = players_.begin();
    switch (field.getType())
	{
    case Field::Type::AUTO:
        if (field.getId())
			return false;
        player_tmp = Player(player.getName(), player.getMoney() - PRICE_AUTO_);
        field = Field(field.getName(), field.getType(), player_id);
		break;
    case Field::Type::FOOD:
        if (field.getId())
			return false;
        player_tmp = Player(player.getName(), player.getMoney() - PRICE_FOOD_);
        field = Field(field.getName(), field.getType(), player_id);
		break;
    case Field::Type::TRAVEL:
        if (field.getId())
			return false;
        player_tmp = Player(player.getName(), player.getMoney() - PRICE_TRAVEL_);
        field = Field(field.getName(), field.getType(), player_id);
		break;
    case Field::Type::CLOTHER:
        if (field.getId())
			return false;
        player_tmp = Player(player.getName(), player.getMoney() - PRICE_CLOTHER_);
        field = Field(field.getName(), field.getType(), player_id);
		break;
	default:
		return false;
	};
    FieldIterator i = find_if(fields_.begin(), fields_.end(), [field](Field x) {
            return x.getName() == field.getName(); });
    *i = field;
    advance(player_it, player_id-1);
    *player_it = player_tmp;
	return true;
}

FieldIterator Monopoly::GetFieldByName(const std::string& name)
{
    FieldIterator i = find_if(fields_.begin(), fields_.end(),[name] (Field field) {
        return field.getName() == name;
    });
    return i;
}

bool Monopoly::Renta(int player, const Field& field)
{
    Player player_tmp = GetPlayerInfo(player);
    Player player_result;

    switch (field.getType())
	{
    case Field::Type::AUTO:
        if (!field.getId())
			return false;
        player_result = GetPlayerInfo(field.getId());
        player_result = Player(player_result.getName(), player_result.getMoney() + RENT_AUTO_);
        player_tmp = Player(player_tmp.getName(), player_tmp.getMoney() - RENT_AUTO_);
		break;
    case Field::Type::FOOD:
        if (!field.getId())
			return false;
    case Field::Type::TRAVEL:
        if (!field.getId())
			return false;
        player_result = GetPlayerInfo(field.getId());
        player_result = Player(player_result.getName(), player_result.getMoney() + RENT_TRAVEL_);
        player_tmp = Player(player_tmp.getName(), player_tmp.getMoney() - RENT_TRAVEL_);
		break;
    case Field::Type::CLOTHER:
        if (!field.getId())
			return false;
        player_result = GetPlayerInfo(field.getId());
        player_result = Player(player_result.getName(), player_result.getMoney() + RENT_CLOTHER_);
        player_tmp = Player(player_tmp.getName(), player_tmp.getMoney() - RENT_CLOTHER_);
		break;
    case Field::Type::PRISON:
        player_tmp = Player(player_tmp.getName(), player_tmp.getMoney() - RENT_PRISON_);
		break;
    case Field::Type::BANK:
        player_tmp = Player(player_tmp.getName(), player_tmp.getMoney() - RENT_BANK_);
		break;
	default:
		return false;
	}
    PlayerIterator i = players_.begin();
    advance(i, player - 1);
    *i = player_tmp;
    i = find_if(players_.begin(), players_.end(), [player_result](Player player) {
        return player.getName() == player_result.getName();
    });
    *i = player_result;
	return true;
}

Fields::iterator Monopoly::FieldsEnd(){
    return fields_.end();
}

PlayerIterator Monopoly::PlayersEnd(){
    return players_.end();
}
