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

const std::string kFord = "Ford";
const std::string kMCDonald = "MCDonald";
const std::string kLamoda = "Lamoda";
const std::string kAirBalti = "Air Baltic";
const std::string kNorvadia = "Nordavia";
const std::string kPrison = "Prison";
const std::string kTesla = "TESLA";

}

Monopoly::Monopoly(const std::string names[kMaxPlayerCount], const int& countPlayers)
{
	for (int i = 0; i < countPlayers; i++)
	{
        Players.push_back(Player(names[i], kStartMoney));
	}
	Fields.push_back(std::make_tuple(kFord, Monopoly::AUTO, kBankIndex, false));
	Fields.push_back(std::make_tuple(kMCDonald, Monopoly::FOOD, kBankIndex, false));
	Fields.push_back(std::make_tuple(kLamoda, Monopoly::CLOTHER, kBankIndex, false));
	Fields.push_back(std::make_tuple(kAirBalti, Monopoly::TRAVEL, kBankIndex, false));
	Fields.push_back(std::make_tuple(kNorvadia, Monopoly::TRAVEL, kBankIndex, false));
	Fields.push_back(std::make_tuple(kPrison, Monopoly::PRISON, kBankIndex, false));
	Fields.push_back(std::make_tuple(kMCDonald, Monopoly::FOOD, kBankIndex, false));
	Fields.push_back(std::make_tuple(kTesla, Monopoly::AUTO, kBankIndex, false));
}

const std::list<Player>& Monopoly::GetPlayersList() const
{
    return Players;
}

const std::list<std::tuple<std::string, Monopoly::Type,int,bool>>& Monopoly::GetFieldsList() const
{
    return Fields;
}

const Player& Monopoly::GetPlayerInfo(const int& playerIndex) const
{
    std::list<Player>::const_iterator i = Players.cbegin();
	std::advance(i, playerIndex - 1);
    return *i;
}

bool Monopoly::Buy(const int& playerIndex, std::tuple<std::string, Type, int, bool>& resource)
{
    std::list<Player>::iterator curPlayerIterator = Players.begin();
    std::advance(curPlayerIterator, playerIndex - 1);
	std::list<std::tuple<std::string, Type, int, bool>>::iterator iterResource;
	switch (std::get<1>(resource))
	{
	case AUTO:
		if (std::get<2>(resource))
			return false;
        curPlayerIterator->calcBalance(-kAutoFieldCost);
		resource = std::make_tuple(std::get<0>(resource), std::get<1>(resource), playerIndex, std::get<2>(resource));
		break;
	case FOOD:
		if (std::get<2>(resource))
			return false;
        curPlayerIterator->calcBalance(-kFoodFieldCost);
		resource = std::make_tuple(std::get<0>(resource), std::get<1>(resource), playerIndex, std::get<2>(resource));
		break;
	case TRAVEL:
		if (std::get<2>(resource))
			return false;
        curPlayerIterator->calcBalance(-kTravelFieldCost);
		resource = std::make_tuple(std::get<0>(resource), std::get<1>(resource), playerIndex, std::get<2>(resource));
		break;
	case CLOTHER:
		if (std::get<2>(resource))
			return false;
        curPlayerIterator->calcBalance(-kClotherFieldCost);
		resource = std::make_tuple(std::get<0>(resource), std::get<1>(resource), playerIndex, std::get<2>(resource));
		break;
	default:
		return false;
	};

	iterResource = std::find_if(Fields.begin(), Fields.end(), [resource](auto x) { return std::get<0>(x) == std::get<0>(resource); });
	if (Fields.end() == iterResource)
	{
		return false;
	}
	*iterResource = resource;

	return true;
}

const std::tuple<std::string, Monopoly::Type, int, bool>&  Monopoly::GetFieldByName(const std::string& playerName) const
{
	auto i = std::find_if(Fields.begin(), Fields.end(), [playerName] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return std::get<0>(x) == playerName;
	});
	return *i;
}

bool Monopoly::Renta(const int& playerIndex, std::tuple<std::string, Type, int, bool>& resource)
{
    std::list<Player>::iterator curPlayerIterator = Players.begin();
    std::advance(curPlayerIterator, playerIndex - 1);
    Player ownerPlayer = GetPlayerInfo(std::get<2>(resource));

	switch (std::get<1>(resource))
	{
	case AUTO:
		if (!std::get<2>(resource))
			return false;
        ownerPlayer.calcBalance(kRentCost);
        curPlayerIterator->calcBalance(-kRentCost);
		break;
	case FOOD:
		if (!std::get<2>(resource))
			return false;
	case TRAVEL:
		if (!std::get<2>(resource))
			return false;
        ownerPlayer.calcBalance(kRentCost);
        curPlayerIterator->calcBalance(-kRentCost);
		break;
	case CLOTHER:
		if (!std::get<2>(resource))
			return false;
        ownerPlayer.calcBalance(kRentCost);
        curPlayerIterator->calcBalance(-kRentCost);
		break;
	case PRISON:
        curPlayerIterator->calcBalance(-kPrisonRansomCost);
		break;
	case BANK:
        curPlayerIterator->calcBalance(-kBankPaymant);
		break;
	default:
		return false;
	}

    std::list<Player>::iterator i = Players.begin();
    i = find_if(Players.begin(), Players.end(), [ownerPlayer](auto x) { return x.getName() == ownerPlayer.getName(); });
    *i = ownerPlayer;
    return true;
}
