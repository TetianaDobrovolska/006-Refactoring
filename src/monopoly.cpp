#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(const vector<string>& names, const int& countPlayers) {
    for (int i = 0; i < countPlayers; i++) {
        _players.push_back(make_tuple(names[i], 6000));
	}

    _fields.push_back(make_tuple("Ford", Monopoly::AUTO, 0, false));
    _fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
    _fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHES, 0, false));
    _fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, 0, false));
    _fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, 0, false));
    _fields.push_back(make_tuple("Prison", Monopoly::PRISON, 0, false));
    _fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
    _fields.push_back(make_tuple("TESLA", Monopoly::AUTO, 0, false));
}

bool Monopoly::buy(const int& buyerId, std::tuple<string, FieldType, int, bool>& field) {
    auto buyer = getPlayer(buyerId);
    switch (get<1>(field)) {
    case AUTO:
        if (get<2>(field))
            return false;
        buyer = make_tuple(get<0>(buyer), get<1>(buyer) - 500);
        field = make_tuple(get<0>(field), get<1>(field), buyerId, get<2>(field));
        break;
    case FOOD:
        if (get<2>(field))
            return false;
        buyer = make_tuple(get<0>(buyer), get<1>(buyer) - 250);
        field = make_tuple(get<0>(field), get<1>(field), buyerId, get<2>(field));
        break;
    case TRAVEL:
        if (get<2>(field))
            return false;
        buyer = make_tuple(get<0>(buyer), get<1>(buyer) - 700);
        field = make_tuple(get<0>(field), get<1>(field), buyerId, get<2>(field));
        break;
    case CLOTHES:
        if (get<2>(field))
            return false;
        buyer = make_tuple(get<0>(buyer), get<1>(buyer) - 100);
        field = make_tuple(get<0>(field), get<1>(field), buyerId, get<2>(field));
        break;
    default:
        return false;
    };

    auto i = find_if(_fields.begin(), _fields.end(), [field](auto x) { return get<0>(x) == get<0>(field); });
    *i = field;

    _players[buyerId] = buyer;

    return true;
}

bool Monopoly::rent(const int& renterId, std::tuple<string, FieldType, int, bool>& field) {
    tuple<string, int> renter = getPlayer(renterId);
    tuple<string, int> owner;
    int ownerId = get<2>(field);

    switch (get<1>(field))
    {
    case AUTO:
        if (!ownerId)
            return false;
        owner = getPlayer(ownerId);
        owner = make_tuple(get<0>(owner), get<1>(owner) + 250);
        renter = make_tuple(get<0>(renter), get<1>(renter) - 250);
        break;
    case FOOD:
        if (!ownerId)
            return false;
    case TRAVEL:
        if (!ownerId)
            return false;
        owner = getPlayer(get<2>(field));
        owner = make_tuple(get<0>(owner), get<1>(owner) + 250);
        renter = make_tuple(get<0>(renter), get<1>(renter) - 250);
        break;
    case CLOTHES:
        if (!ownerId)
            return false;
        owner = getPlayer(get<2>(field));
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

    _players[renterId] = renter;
    _players[ownerId] = owner;
    return true;
}

std::vector<std::tuple<std::string, int>> Monopoly::getPlayers() const {
    return _players;
}

std::vector<std::tuple<std::string, Monopoly::FieldType,int,bool>> Monopoly::getFields() const {
    return _fields;
}

std::tuple<std::string, int> Monopoly::getPlayer(const int& index) const {
    return _players[index];
}

std::tuple<std::string, Monopoly::FieldType, int, bool>  Monopoly::getFieldByName(std::string field) {
    auto i = find_if(_fields.begin(), _fields.end(),[field] (std::tuple<std::string, Monopoly::FieldType, int, bool> x) {
        return get<0>(x) == field;
	});
	return *i;
}
