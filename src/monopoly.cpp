#include "monopoly.hpp"
#include <algorithm>

#include "auto_field.h"
#include "cloth_field.h"
#include "food_field.h"
#include "prison_field.h"
#include "travel_field.h"

Monopoly::Monopoly(const std::string names[kMaxPlayerCount], const int& countPlayers)
{
    for (int i = 0; i < countPlayers; i++)
    {
        Players.push_back(Player(names[i], kStartMoney));
    }
    Fields.push_back(new AutoField(Field::FORD, kBankIndex));
    Fields.push_back(new FoodField(Field::MCDONALD, kBankIndex));
    Fields.push_back(new ClothField(Field::LAMODA, kBankIndex));
    Fields.push_back(new TravelField(Field::AIR_BALTIC, kBankIndex));
    Fields.push_back(new TravelField(Field::NORDAVIA, kBankIndex));
    Fields.push_back(new PrisonField(Field::BPRISON, kBankIndex));
    Fields.push_back(new FoodField(Field::MCDONALD, kBankIndex));
    Fields.push_back(new AutoField(Field::TESLA, kBankIndex));
}

const std::list<Player>& Monopoly::GetPlayersList() const
{
    return Players;
}

const std::list<Field*>& Monopoly::GetFieldsList() const
{
    return Fields;
}

const int Monopoly::GetPlayerBalance(const int& playerIndex) const
{
    return GetPlayerInfo(playerIndex).getBalance();
}

const Player& Monopoly::GetPlayerInfo(const int& playerIndex) const
{
    std::list<Player>::const_iterator i = Players.cbegin();
    std::advance(i, playerIndex - 1);
    return *i;
}

std::list<Player>::iterator Monopoly::GetPlayer(const int& playerIndex)
{
    std::list<Player>::iterator i = Players.begin();
    std::advance(i, playerIndex - 1);
    return i;
}

const Field* Monopoly::GetFieldByName(const Field::eBrand brand) const
{
    auto i = std::find_if(Fields.cbegin(), Fields.cend(), [brand] (Field* x) {
        return x->getBrand() == brand;
    });
    return *i;
}

std::list<Field*>::const_iterator Monopoly::getFieldIterator(const Field* resource)
{
    return std::find_if(Fields.cbegin(), Fields.cend(),
                        [resource](auto x) { return x->getBrand() == resource->getBrand(); });
}

bool Monopoly::Buy(const int& playerIndex, const Field* resource)
{
    auto iterResource = getFieldIterator(resource);
    if (Fields.end() == iterResource)
    {
        return false;
    }

    auto iterPlayer = GetPlayer(playerIndex);
    if(!(*iterResource)->buy(*iterPlayer))
    {
        return false;
    }

    (*iterResource)->setOwnerIndex(playerIndex);

    return true;
}

bool Monopoly::Renta(const int& playerIndex, const Field* resource)
{

    auto iterResource = getFieldIterator(resource);
    if (Fields.end() == iterResource)
    {
        return false;
    }

    auto curPlayer = GetPlayer(playerIndex);
    auto ownerPlayer = GetPlayer((*iterResource)->getOwnerIndex());
    if(!(*iterResource)->renta(*curPlayer, *ownerPlayer))
    {
        return false;
    }

    return true;
}
