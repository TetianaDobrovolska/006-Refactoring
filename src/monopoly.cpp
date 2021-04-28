#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(const string names[], const int& countPlayers)
{
    for (int i = 0; i < countPlayers; i++)
    {
        Players.push_back(Player(names[i], startupCapital));
    }
    Fields.push_back(Field("Ford", Field::AUTO, 0));
    Fields.push_back(Field("MCDonald", Field::FOOD, 0));
    Fields.push_back(Field("Lamoda", Field::CLOTHES, 0));
    Fields.push_back(Field("Air Baltic", Field::TRAVEL, 0));
    Fields.push_back(Field("Nordavia", Field::TRAVEL, 0));
    Fields.push_back(Field("Prison", Field::PRISON, 0));
    Fields.push_back(Field("MCDonald", Field::FOOD, 0));
    Fields.push_back(Field("TESLA", Field::AUTO, 0));
}

const std::list<Player>& Monopoly::GetPlayersList() const
{
    return Players;
}

const std::list<Field>& Monopoly::GetFieldsList() const
{
    return Fields;
}

const Player& Monopoly::GetPlayerInfo(const int& playerId) const
{
    std::list<Player>::const_iterator i = Players.cbegin();
    advance(i, playerId - 1);
    return *i;
}

bool Monopoly::Buy(const int& playerId, Field& field)
{
    Player player = GetPlayerInfo(playerId);

    switch (field.GetBusinessType())
    {
    case Field::AUTO:
        if (field.GetOwnerIndex())
            return false;
        player = Player(player.GetName(), player.GetMoney() - sellPriceAuto);
        field = Field(field.GetCompanyName(), field.GetBusinessType(), playerId);
        break;
    case Field::FOOD:
        if (field.GetOwnerIndex())
            return false;
        player = Player(player.GetName(), player.GetMoney() - sellPriceFood);
        field = Field(field.GetCompanyName(), field.GetBusinessType(), playerId);
        break;
    case Field::TRAVEL:
        if (field.GetOwnerIndex())
            return false;
        player = Player(player.GetName(), player.GetMoney() - sellPriceTravel);
        field = Field(field.GetCompanyName(), field.GetBusinessType(), playerId);
        break;
    case Field::CLOTHES:
        if (field.GetOwnerIndex())
            return false;
        player = Player(player.GetName(), player.GetMoney() - sellPriceClothes);
        field = Field(field.GetCompanyName(), field.GetBusinessType(), playerId);
        break;
    default:
        return false;
    };
    auto i = find_if(Fields.begin(), Fields.end(), [field](auto x) { return x.GetCompanyName() == field.GetCompanyName(); });
    *i = field;
    auto j = Players.begin();
    advance(j, playerId-1);
    *j = player;
    return true;
}

const Field& Monopoly::GetFieldByName(const std::string& companyName) const
{
    auto i = find_if(Fields.begin(), Fields.end(),[companyName] (Field field) {
        return field.GetCompanyName() == companyName;
	});
	return *i;
}

bool Monopoly::Renta(const int& playerIndex, Field& field)
{
    Player player = GetPlayerInfo(playerIndex);
    Player owner;

    int ownerId = field.GetOwnerIndex();

    switch (field.GetBusinessType())
    {
    case Field::AUTO:
        owner = GetPlayerInfo(ownerId);
        owner = Player(owner.GetName(), owner.GetMoney() + rentalPriceAuto);
        player = Player(player.GetName(), player.GetMoney() - rentalPriceAuto);
        break;
    case Field::FOOD:
        if (ownerId)
            return false;
        break;
    case Field::TRAVEL:
        owner = GetPlayerInfo(ownerId);
        owner = Player(owner.GetName(), owner.GetMoney() + rentalPriceTravel);
        player = Player(player.GetName(), player.GetMoney() - rentalPriceTravel);
        break;
    case Field::CLOTHES:
        owner = GetPlayerInfo(ownerId);
        owner = Player(owner.GetName(), owner.GetMoney() + rentalPriceClothes);
        player = Player(player.GetName(), player.GetMoney() - rentalPriceClothes);
        break;
    case Field::PRISON:
        player = Player(player.GetName(), player.GetMoney() - rentalPricePrison);
        break;
    case Field::BANK:
        player = Player(player.GetName(), player.GetMoney() - rentalPriceBank);
        break;
    default:
        return false;
    }
    auto iterator = Players.begin();
    advance(iterator, playerIndex - 1);
    *iterator = player;
    iterator = find_if(Players.begin(), Players.end(), [owner](auto player) { return player.GetName() == owner.GetName(); });
    *iterator = owner;
    return true;
}
