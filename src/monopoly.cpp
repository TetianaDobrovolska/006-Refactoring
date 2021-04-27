#include "monopoly.hpp"
#include <algorithm>

Monopoly::Monopoly(std::string names[COMPANY_NUMBER_],int countPlaers)
{
    const int START_BALANCE = 6000;
	for (int i = 0; i < countPlaers; i++)
	{
        players_.push_back(Player(names[i], START_BALANCE));
	}

    fields_.push_back(FieldAuto("Ford"));
    fields_.push_back(FieldFood("MCDonald"));
    fields_.push_back(FieldClother("Lamoda"));
    fields_.push_back(FieldTravel("Air Baltic"));
    fields_.push_back(FieldTravel("Nordavia"));
    fields_.push_back(FieldPrison("Prison"));
    fields_.push_back(FieldFood("MCDonald"));
    fields_.push_back(FieldAuto("TESLA"));
}

PlayerIterator Monopoly::GetPlayersList()
{
    return players_.begin();
}

FieldIterator Monopoly::GetFieldsList()
{
    return fields_.begin();
}

PlayerIterator Monopoly::GetPlayer(int id)
{
    auto player_it = GetPlayersList();
    for(int it = 1; it < id; it++){
        ++player_it;
    }
    return player_it;
}

bool Monopoly::Buy(PlayerIterator player_id, Field& field)
{
    bool field_result = field.sellTo(player_id);
    if(!field_result){
        return false;
    }

    FieldIterator field_it = find_if(fields_.begin(), fields_.end(), [field](Field x) {
            return x.getName() == field.getName(); });
    if(field_it == fields_.end()){
        return false;
    }
    player_id->setMoney(player_id->getMoney() - field.getPrice());
	return true;
}

FieldIterator Monopoly::GetFieldByName(const std::string& name)
{
    FieldIterator i = find_if(fields_.begin(), fields_.end(),[name] (Field field) {
        return field.getName() == name;
    });
    return i;
}

bool Monopoly::Renta(PlayerIterator player, const Field& field)
{
    if(player == players_.end()){
        return false;
    }
    player->setMoney(player->getMoney() - field.getRent());
    auto field_player = field.getPlayer();
    field_player->setMoney(field_player->getMoney() + field.getRent());
	return true;
}

Fields::iterator Monopoly::FieldsEnd(){
    return fields_.end();
}

PlayerIterator Monopoly::PlayersEnd(){
    return players_.end();
}
