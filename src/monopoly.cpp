#include "monopoly.hpp"
#include <algorithm>

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
    Fields.push_back(Field(resource::FORD, resource::AUTO, kBankIndex));
    Fields.push_back(Field(resource::MCDONALD, resource::FOOD, kBankIndex));
    Fields.push_back(Field(resource::LAMODA, resource::CLOTHER, kBankIndex));
    Fields.push_back(Field(resource::AIR_BALTIC, resource::TRAVEL, kBankIndex));
    Fields.push_back(Field(resource::NORDAVIA, resource::TRAVEL, kBankIndex));
    Fields.push_back(Field(resource::BPRISON, resource::PRISON, kBankIndex));
    Fields.push_back(Field(resource::MCDONALD, resource::FOOD, kBankIndex));
    Fields.push_back(Field(resource::TESLA, resource::AUTO, kBankIndex));
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
    switch (iterResource->getType())
	{
    case resource::AUTO:
        if (iterResource->getOwnerIndex())
			return false;
        curPlayerIterator->calcBalance(-kAutoFieldCost);
        iterResource->setOwnerIndex(playerIndex);
		break;
    case resource::FOOD:
        if (iterResource->getOwnerIndex())
			return false;
        curPlayerIterator->calcBalance(-kFoodFieldCost);
        iterResource->setOwnerIndex(playerIndex);
		break;
    case resource::TRAVEL:
        if (iterResource->getOwnerIndex())
			return false;
        curPlayerIterator->calcBalance(-kTravelFieldCost);
        iterResource->setOwnerIndex(playerIndex);
		break;
    case resource::CLOTHER:
        if (iterResource->getOwnerIndex())
			return false;
        curPlayerIterator->calcBalance(-kClotherFieldCost);
        iterResource->setOwnerIndex(playerIndex);
		break;
	default:
		return false;
	};

	return true;
}

const Field&  Monopoly::GetFieldByName(const resource::eBrand brand) const
{
    auto i = std::find_if(Fields.cbegin(), Fields.cend(), [brand] (Field x) {
        return x.getBrand() == brand;
	});
	return *i;
}

bool Monopoly::Renta(const int& playerIndex, Field& resource)
{
    std::list<Player>::iterator curPlayerIterator = Players.begin();
    std::advance(curPlayerIterator, playerIndex - 1);
    Player ownerPlayer = GetPlayerInfo(resource.getOwnerIndex());

    switch (resource.getType())
	{
    case resource::AUTO:
        if (!resource.getOwnerIndex())
			return false;
        ownerPlayer.calcBalance(kRentCost);
        curPlayerIterator->calcBalance(-kRentCost);
		break;
    case resource::FOOD:
        if (!resource.getOwnerIndex())
			return false;
    case resource::TRAVEL:
        if (!resource.getOwnerIndex())
			return false;
        ownerPlayer.calcBalance(kRentCost);
        curPlayerIterator->calcBalance(-kRentCost);
		break;
    case resource::CLOTHER:
        if (!resource.getOwnerIndex())
			return false;
        ownerPlayer.calcBalance(kRentCost);
        curPlayerIterator->calcBalance(-kRentCost);
		break;
    case resource::PRISON:
        curPlayerIterator->calcBalance(-kPrisonRansomCost);
		break;
    case resource::BANK:
        curPlayerIterator->calcBalance(-kBankPaymant);
		break;
	default:
		return false;
	}
    std::list<Player>::iterator i = Players.begin();
    i = find_if(Players.begin(), Players.end(),
                                     [ownerPlayer](auto x) { return x.getName() == ownerPlayer.getName(); });
    *i = ownerPlayer;

    return true;
}
