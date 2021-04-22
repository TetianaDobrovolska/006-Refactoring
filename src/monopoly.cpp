#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

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

Monopoly::Monopoly(string names[kMaxPlayerCount],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		Players.push_back(std::make_tuple(names[i], kStartMoney));
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

std::list<std::tuple<std::string, int>> * Monopoly::GetPlayersList()
{
	return &Players;
}

std::list<std::tuple<std::string, Monopoly::Type,int,bool>> * Monopoly::GetFieldsList()
{
	return &Fields;
}

std::tuple<std::string, int> Monopoly::GetPlayerInfo(int m)
{
	list<std::tuple<std::string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	return *i;
}

bool Monopoly::Buy(int z, std::tuple<std::string, Type, int, bool> k)
{
	auto x = GetPlayerInfo(z);
	tuple<string, int> p;
	list<tuple<std::string, Type, int, bool>>::iterator i;
	list<tuple<string, int>>::iterator j = Players.begin();
	switch (get<1>(k))
	{
	case AUTO:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - kAutoFieldCost);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case FOOD:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - kFoodFieldCost);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case TRAVEL:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - kTravelFieldCost);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case CLOTHER:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - kClotherFieldCost);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	default:
		return false;
	};
	i = find_if(Fields.begin(), Fields.end(), [k](auto x) { return get<0>(x) == get<0>(k); });
	*i = k;
    advance(j, z-1);
	*j = p;
	return true;
}

std::tuple<std::string, Monopoly::Type, int, bool>  Monopoly::GetFieldByName(std::string l)
{
	std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::iterator i = find_if(Fields.begin(), Fields.end(),[l] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return get<0>(x) == l;
	});
	return *i;
}

bool Monopoly::Renta(int m, std::tuple<std::string, Type, int, bool> c)
{
	tuple<string, int> z = GetPlayerInfo(m);
	tuple<string, int> o;

	switch (get<1>(c))
	{
	case AUTO:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + kRentCost);
		z = make_tuple(get<0>(z), get<1>(z) - kRentCost);
		break;
	case FOOD:
		if (!get<2>(c))
			return false;
	case TRAVEL:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + kRentCost);
		z = make_tuple(get<0>(z), get<1>(z) - kRentCost);
		break;
	case CLOTHER:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + kRentCost);
		z = make_tuple(get<0>(z), get<1>(z) - kRentCost);
		break;
	case PRISON:
		z = make_tuple(get<0>(z), get<1>(z) - kPrisonRansomCost);
		break;
	case BANK:
		z = make_tuple(get<0>(z), get<1>(z) - kBankPaymant);
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


