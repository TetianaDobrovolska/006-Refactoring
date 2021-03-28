#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10], int countPlayers) {
    for (int i = 0; i < countPlayers; i++) {
        players.push_back(make_tuple(names[i], 6000));
	}

    fields.push_back(make_tuple("Ford", Monopoly::AUTO, 0, false));
    fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
    fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHES, 0, false));
    fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, 0, false));
    fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, 0, false));
    fields.push_back(make_tuple("Prison", Monopoly::PRISON, 0, false));
    fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
    fields.push_back(make_tuple("TESLA", Monopoly::AUTO, 0, false));
}

bool Monopoly::buy(int playerId, std::tuple<std::string, Type, int, bool> field) {
    auto buyer = getPlayerInfo(playerId);
    tuple<string, int> player;
    switch (get<1>(field)) {
    case AUTO:
        if (get<2>(field))
            return false;
        player = make_tuple(get<0>(buyer), get<1>(buyer) - 500);
        field = make_tuple(get<0>(field), get<1>(field), playerId, get<2>(field));
        break;
    case FOOD:
        if (get<2>(field))
            return false;
        player = make_tuple(get<0>(buyer), get<1>(buyer) - 250);
        field = make_tuple(get<0>(field), get<1>(field), playerId, get<2>(field));
        break;
    case TRAVEL:
        if (get<2>(field))
            return false;
        player = make_tuple(get<0>(buyer), get<1>(buyer) - 700);
        field = make_tuple(get<0>(field), get<1>(field), playerId, get<2>(field));
        break;
    case CLOTHES:
        if (get<2>(field))
            return false;
        player = make_tuple(get<0>(buyer), get<1>(buyer) - 100);
        field = make_tuple(get<0>(field), get<1>(field), playerId, get<2>(field));
        break;
    default:
        return false;
    };

    list<tuple<std::string, Type, int, bool>>::iterator i;
    i = find_if(fields.begin(), fields.end(), [field](auto x) { return get<0>(x) == get<0>(field); });
    *i = field;
    list<tuple<string, int>>::iterator j = players.begin();
    advance(j, playerId-1);
    *j = player;

    return true;
}

bool Monopoly::rent(int playerId, std::tuple<std::string, Type, int, bool> field) {
    tuple<string, int> renter = getPlayerInfo(playerId);
    tuple<string, int> owner;

    switch (get<1>(field))
    {
    case AUTO:
        if (!get<2>(field))
            return false;
        owner = getPlayerInfo(get<2>(field));
        owner = make_tuple(get<0>(owner), get<1>(owner) + 250);
        renter = make_tuple(get<0>(renter), get<1>(renter) - 250);
        break;
    case FOOD:
        if (!get<2>(field))
            return false;
    case TRAVEL:
        if (!get<2>(field))
            return false;
        owner = getPlayerInfo(get<2>(field));
        owner = make_tuple(get<0>(owner), get<1>(owner) + 250);
        renter = make_tuple(get<0>(renter), get<1>(renter) - 250);
        break;
    case CLOTHES:
        if (!get<2>(field))
            return false;
        owner = getPlayerInfo(get<2>(field));
        owner = make_tuple(get<0>(owner), get<1>(owner) + 250);
        renter = make_tuple(get<0>(renter), get<1>(renter) - 250);
        break;
    case PRISON:
        renter = make_tuple(get<0>(renter), get<1>(renter) - 1000);
        break;
    case BANK:
        renter = make_tuple(get<0>(renter), get<1>(renter) - 700);
        break;
    default:
        return false;
    }

    list<tuple<string, int>>::iterator i = players.begin();
    advance(i, playerId - 1);
    *i = renter;
    i = find_if(players.begin(), players.end(), [owner](auto x) { return get<0>(x) == get<0>(owner); });
    *i = owner;
    return true;
}

std::list<std::tuple<std::string, int>>* Monopoly::getPlayersList() {
    return &players;
}

std::list<std::tuple<std::string, Monopoly::Type,int,bool>>* Monopoly::getFieldsList() {
    return &fields;
}

std::tuple<std::string, int> Monopoly::getPlayerInfo(int playerIndex) {
    list<std::tuple<std::string, int>>::iterator i = players.begin();
    advance(i, playerIndex - 1);
	return *i;
}

std::tuple<std::string, Monopoly::Type, int, bool>  Monopoly::getFieldByName(std::string field) {
    std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::iterator i = find_if(fields.begin(), fields.end(),[field] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
        return get<0>(x) == field;
	});
	return *i;
}
