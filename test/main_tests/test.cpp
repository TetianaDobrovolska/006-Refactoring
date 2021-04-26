#include "gtest/gtest.h"
#include "monopoly.hpp"

#include <iostream>

TEST(LAB2, GetPlayersListReturnCorrectList) {
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players,3);
    auto playersList = monopoly.GetPlayersList();

    int i = 0;
    for (auto player : playersList) {
        ASSERT_STREQ(player.getName().c_str(), players[i++].c_str());
        ASSERT_EQ(player.getBalance(), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    Field expectedCompanies [] {
        Field(Field::FORD, Field::AUTO, 0),
        Field(Field::MCDONALD, Field::FOOD, 0),
        Field(Field::LAMODA, Field::CLOTHER, 0),
        Field(Field::AIR_BALTIC, Field::TRAVEL, 0),
        Field(Field::NORDAVIA, Field::TRAVEL, 0),
        Field(Field::BPRISON, Field::PRISON, 0),
        Field(Field::MCDONALD, Field::FOOD, 0),
        Field(Field::TESLA, Field::AUTO, 0)
    };
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto actualCompanies = monopoly.GetFieldsList();
    int i = 0;
    for (auto x : actualCompanies)
    {
        ASSERT_EQ(x, expectedCompanies[i++]);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto resource = monopoly.GetFieldByName(Field::FORD);
    monopoly.Buy(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 5500);

    resource = monopoly.GetFieldByName(Field::FORD);
    ASSERT_TRUE(resource.getOwnerIndex() != 0);
}

TEST(LAB2, PlayerBuyPrison)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto resource = monopoly.GetFieldByName(Field::BPRISON);
    monopoly.Buy(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 6000);

    resource = monopoly.GetFieldByName(Field::BPRISON);
    ASSERT_TRUE(resource.getOwnerIndex() == 0);
}

TEST(LAB2, PlayerBuyUndefinedField)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    Field resource(Field::UKRSIBBANK, Field::BANK, 0);
    ASSERT_FALSE(monopoly.Buy(1, resource));

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 6000);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto resource = monopoly.GetFieldByName(Field::FORD);
    monopoly.Buy(1, resource);

    resource = monopoly.GetFieldByName(Field::FORD);
    monopoly.Renta(2, resource);

    auto player1 = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player1.getBalance(), 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(player2.getBalance(), 5750);
}

TEST(LAB2, RentaPrison)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto resource = monopoly.GetFieldByName(Field::BPRISON);
    monopoly.Renta(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 5000);
}

TEST(LAB2, RentaBank)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    Field resource(Field::UKRSIBBANK, Field::BANK, 0);
    monopoly.Renta(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 5300);
}

bool operator== (const Field & a, const Field & b)
{
    return a.getBrand() == b.getBrand() &&
            a.getType() == b.getType() &&
            a.getOwnerIndex() == b.getOwnerIndex();
}
