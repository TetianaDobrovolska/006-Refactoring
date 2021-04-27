#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(const string names[], const int& countPlayers)
{
    for (int i = 0; i < countPlayers; i++)
    {
        Players.push_back(Player(names[i], startupCapital));
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

const std::list<Player>& Monopoly::GetPlayersList() const
{
    return Players;
}

const std::list<std::tuple<std::string, Monopoly::Type,int,bool>> & Monopoly::GetFieldsList() const
{
    return Fields;
}

const Player& Monopoly::GetPlayerInfo(const int& m) const
{
    std::list<Player>::const_iterator i = Players.cbegin();
    advance(i, m - 1);
    return *i;
}

bool Monopoly::Buy(const int z, std::tuple<string, Type, int, bool>& k)
{
    auto x = GetPlayerInfo(z);
    Player p;
    list<tuple<std::string, Type, int, bool>>::iterator i;
    list<Player>::iterator j = Players.begin();
    switch (get<1>(k))
    {
    case AUTO:
        if (get<2>(k))
            return false;
        p = Player(x.GetName(), x.GetMoney() - sellPriceAuto);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
        break;
	case FOOD:
		if (get<2>(k))
			return false;
        p = Player(x.GetName(), x.GetMoney() - sellPriceFood);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
    case TRAVEL:
        if (get<2>(k))
            return false;
        p = Player(x.GetName(), x.GetMoney() - sellPriceTravel);
    k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
        break;
    case CLOTHES:
        if (get<2>(k))
            return false;
        p = Player(x.GetName(), x.GetMoney() - sellPriceClothes);
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
    Player z = GetPlayerInfo(m);
    Player o;

	switch (get<1>(c))
	{
	case AUTO:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
        o = Player(o.GetName(), o.GetMoney() + rentalPriceAuto);
        z = Player(z.GetName(), z.GetMoney() - rentalPriceAuto);
		break;
	case FOOD:
		if (!get<2>(c))
			return false;
	case TRAVEL:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
        o = Player(o.GetName(), o.GetMoney() + rentalPriceTravel);
        z = Player(z.GetName(), z.GetMoney() - rentalPriceTravel);
		break;
    case CLOTHES:
		if (!get<2>(c))
            return false;
		o = GetPlayerInfo(get<2>(c));
        o = Player(o.GetName(), o.GetMoney() + rentalPriceClothes);
        z = Player(z.GetName(), z.GetMoney() - rentalPriceClothes);
		break;
	case PRISON:
        z = Player(z.GetName(), z.GetMoney() - rentalPricePrison);
		break;
	case BANK:
        z = Player(z.GetName(), z.GetMoney() - rentalPriceBank);
		break;
	default:
		return false;
	}
    list<Player>::iterator i = Players.begin();
	advance(i, m - 1);
	*i = z;
    i = find_if(Players.begin(), Players.end(), [o](auto x) { return x.GetName() == o.GetName(); });
	*i = o;
	return true;
}
