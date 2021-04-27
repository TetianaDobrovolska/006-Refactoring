#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>
#include <memory>
#include "field.hpp"
#include "field_auto.hpp"
#include "field_food.hpp"
#include "field_travel.hpp"
#include "field_clother.hpp"
#include "field_prison.hpp"
#include "field_bank.hpp"
#include "player.hpp"

using Fields = std::list<Field>;
using Players = std::list<Player>;
using FieldIterator = std::list<Field>::iterator;



class Monopoly
{
private:
    static const int COMPANY_NUMBER_ = 10;

public:
    Monopoly(std::string names[COMPANY_NUMBER_],int);
    FieldIterator GetFieldsList();
    Fields::iterator FieldsEnd();
    Fields fields_;
    Players players_;
    PlayerIterator GetPlayersList();
    PlayerIterator PlayersEnd();
    PlayerIterator  GetPlayer(int);
    bool Buy(PlayerIterator, Field&);
    FieldIterator GetFieldByName(const std::string&);
    bool Renta(PlayerIterator, const Field&);
	
};

#endif
