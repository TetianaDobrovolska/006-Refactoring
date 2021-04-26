#include "gtest/gtest.h"

#include "auto_field.h"
#include "bank_field.h"
#include "cloth_field.h"
#include "food_field.h"
#include "monopoly.hpp"
#include "prison_field.h"
#include "travel_field.h"

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
        AutoField(Field::FORD, 0),
        FoodField(Field::MCDONALD, 0),
        ClothField(Field::LAMODA, 0),
        TravelField(Field::AIR_BALTIC, 0),
        TravelField(Field::NORDAVIA, 0),
        PrisonField(Field::BPRISON, 0),
        FoodField(Field::MCDONALD, 0),
        AutoField(Field::TESLA, 0),
    };
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto actualCompanies = monopoly.GetFieldsList();
    int i = 0;
    for (auto x : actualCompanies)
    {
        ASSERT_EQ(*x, expectedCompanies[i++]);
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

    BankField resource(Field::eBrand::UKRSIBBANK, 0);
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
    BankField resource(Field::UKRSIBBANK, 0);
    monopoly.Renta(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 5300);
}

bool operator== (const Field & a, const Field & b)
{
    return a.getBrand() == b.getBrand() &&
            a.getOwnerIndex() == b.getOwnerIndex();
}
