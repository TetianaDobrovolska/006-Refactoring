#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(const string names[], const int countPlayers)
{
    for (int i = 0; i < countPlayers; i++)
    {
        Players.push_back(make_tuple(names[i], startupCapital));
    }
    Fields.push_back(make_tuple("Ford", Monopoly::AUTO, 0, false));
    Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
    Fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHES, 0, false));
    Fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, 0, false));
    Fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, 0, false));
    Fields.push_back(make_tuple("Prison", Monopoly::PRISON, 0, false));
    Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
    Fields.push_back(make_tuple("TESLA", Monopoly::AUTO, 0, false));
}

const std::list<std::tuple<std::string, int>> & Monopoly::GetPlayersList() const
{
    return Players;
}

const std::list<std::tuple<std::string, Monopoly::Type,int,bool>> & Monopoly::GetFieldsList() const
{
    return Fields;
}

const std::tuple<std::string, int>& Monopoly::GetPlayerInfo(const int& m) const
{
    std::list<std::tuple<std::string, int>>::const_iterator i = Players.cbegin();
    advance(i, m - 1);
    return *i;
}

bool Monopoly::Buy(const int z, std::tuple<string, Type, int, bool>& k)
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
        p = make_tuple(get<0>(x), get<1>(x) - sellPriceAuto);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
        break;
	case FOOD:
		if (get<2>(k))
			return false;
        p = make_tuple(get<0>(x), get<1>(x) - sellPriceFood);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
    case TRAVEL:
        if (get<2>(k))
            return false;
        p = make_tuple(get<0>(x), get<1>(x) - sellPriceTravel);
    k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
        break;
    case CLOTHES:
        if (get<2>(k))
            return false;
        p = make_tuple(get<0>(x), get<1>(x) - sellPriceClothes);
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

const std::tuple<std::string, Monopoly::Type, int, bool>& Monopoly::GetFieldByName(const std::string& l) const
{
    const std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::const_iterator i = find_if(Fields.begin(), Fields.end(),[l] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return get<0>(x) == l;
	});
	return *i;
}

bool Monopoly::Renta(const int m, const std::tuple<std::string, Type, int, bool>& c)
{
	tuple<string, int> z = GetPlayerInfo(m);
	tuple<string, int> o;

	switch (get<1>(c))
	{
	case AUTO:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
        o = make_tuple(get<0>(o), get<1>(o) + rentalPriceAuto);
        z = make_tuple(get<0>(z), get<1>(z) - rentalPriceAuto);
		break;
	case FOOD:
		if (!get<2>(c))
			return false;
	case TRAVEL:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
        o = make_tuple(get<0>(o), get<1>(o) + rentalPriceTravel);
        z = make_tuple(get<0>(z), get<1>(z) - rentalPriceTravel);
		break;
    case CLOTHES:
		if (!get<2>(c))
            return false;
		o = GetPlayerInfo(get<2>(c));
        o = make_tuple(get<0>(o), get<1>(o) + rentalPriceClothes);
        z = make_tuple(get<0>(z), get<1>(z) - rentalPriceClothes);
		break;
	case PRISON:
        z = make_tuple(get<0>(z), get<1>(z) - rentalPricePrison);
		break;
	case BANK:
        z = make_tuple(get<0>(z), get<1>(z) - rentalPriceBank);
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
