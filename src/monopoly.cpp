#include "monopoly.hpp"
#include <algorithm>
#include <iostream>

namespace {

constexpr int kBankIndex = 0;
constexpr int kStartMoney = 6000;

constexpr int kAutoFieldCost = 500;
constexpr int kClotherFieldCost = 100;
constexpr int kFoodFieldCost = 250;
constexpr int kTravelFieldCost = 700;

constexpr int kBankPaymant = 700;
constexpr int kPrisonRansomCost = 1000;
constexpr int kRentCost = 250;

}

Monopoly::Monopoly(const std::string names[kMaxPlayerCount], const int& countPlayers)
{
    for (int i = 0; i < countPlayers; i++)
    {
        Players.push_back(Player(names[i], kStartMoney));
    }
    Fields.push_back(Field(Field::FORD, Field::AUTO, kBankIndex));
    Fields.push_back(Field(Field::MCDONALD, Field::FOOD, kBankIndex));
    Fields.push_back(Field(Field::LAMODA, Field::CLOTHER, kBankIndex));
    Fields.push_back(Field(Field::AIR_BALTIC, Field::TRAVEL, kBankIndex));
    Fields.push_back(Field(Field::NORDAVIA, Field::TRAVEL, kBankIndex));
    Fields.push_back(Field(Field::BPRISON, Field::PRISON, kBankIndex));
    Fields.push_back(Field(Field::MCDONALD, Field::FOOD, kBankIndex));
    Fields.push_back(Field(Field::TESLA, Field::AUTO, kBankIndex));
}

const std::list<Player>& Monopoly::GetPlayersList() const
{
    return Players;
}

const std::list<Field>& Monopoly::GetFieldsList() const
{
    return Fields;
}

const Player& Monopoly::GetPlayerInfo(const int& playerIndex) const
{
    std::list<Player>::const_iterator i = Players.cbegin();
    std::advance(i, playerIndex - 1);
    return *i;
}

const Field&  Monopoly::GetFieldByName(const Field::eBrand brand) const
{
    auto i = std::find_if(Fields.cbegin(), Fields.cend(), [brand] (Field x) {
        return x.getBrand() == brand;
    });
    return *i;
}

bool Monopoly::Buy(const int& playerIndex, Field& resource)
{
    std::list<Player>::iterator curPlayerIterator = Players.begin();
    std::advance(curPlayerIterator, playerIndex - 1);

    auto iterResource = std::find_if(Fields.begin(), Fields.end(),
                                    [resource](auto x) { return x.getBrand() == resource.getBrand(); });
    if (Fields.end() == iterResource)
    {
        return false;
    }
    switch (resource.getType())
    {
    case Field::AUTO:
        if (resource.getOwnerIndex())
            return false;
        curPlayerIterator->calcBalance(-kAutoFieldCost);
        break;
    case Field::FOOD:
        if (resource.getOwnerIndex())
            return false;
        curPlayerIterator->calcBalance(-kFoodFieldCost);
        break;
    case Field::TRAVEL:
        if (resource.getOwnerIndex())
            return false;
        curPlayerIterator->calcBalance(-kTravelFieldCost);
        break;
    case Field::CLOTHER:
        if (resource.getOwnerIndex())
            return false;
        curPlayerIterator->calcBalance(-kClotherFieldCost);
        break;
    default:
        return false;
    };
    iterResource->setOwnerIndex(playerIndex);

    return true;
}

bool Monopoly::Renta(const int& playerIndex, Field& resource)
{
    Player curPlayer = GetPlayerInfo(playerIndex);
    Player ownerPlayer;

    switch (resource.getType())
    {
    case Field::AUTO:
        if (!resource.getOwnerIndex())
            return false;
        ownerPlayer = GetPlayerInfo(resource.getOwnerIndex());
        ownerPlayer.calcBalance(kRentCost);
        curPlayer.calcBalance(-kRentCost);
        break;
    case Field::FOOD:
        if (!resource.getOwnerIndex())
            return false;
    case Field::TRAVEL:
        if (!resource.getOwnerIndex())
            return false;
        ownerPlayer = GetPlayerInfo(resource.getOwnerIndex());
        ownerPlayer.calcBalance(kRentCost);
        curPlayer.calcBalance(-kRentCost);
        break;
    case Field::CLOTHER:
        if (!resource.getOwnerIndex())
            return false;
        ownerPlayer = GetPlayerInfo(resource.getOwnerIndex());
        ownerPlayer.calcBalance(kRentCost);
        curPlayer.calcBalance(-kRentCost);
        break;
    case Field::PRISON:
        curPlayer.calcBalance(-kPrisonRansomCost);
        break;
    case Field::BANK:
        curPlayer.calcBalance(-kBankPaymant);
        break;
    default:
        return false;
    }
    std::list<Player>::iterator i = Players.begin();
    std::advance(i, playerIndex - 1);
    *i = curPlayer;
    i = find_if(Players.begin(), Players.end(),
                [ownerPlayer](auto x) { return x.getName() == ownerPlayer.getName(); });
    if (Players.end() != i)
    {
        *i = ownerPlayer;
    }

    return true;
}
