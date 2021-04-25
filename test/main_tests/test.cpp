#include "gtest/gtest.h"
#include "monopoly.hpp"

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
        Field(resource::FOOD, resource::AUTO, 0),
        Field(resource::MCDONALD, resource::FOOD, 0),
        Field(resource::LAMODA, resource::CLOTHER, 0),
        Field(resource::AIR_BALTIC, resource::TRAVEL, 0),
        Field(resource::NORDAVIA, resource::TRAVEL, 0),
        Field(resource::BPRISON, resource::PRISON, 0),
        Field(resource::MCDONALD, resource::FOOD, 0),
        Field(resource::TESLA, resource::AUTO, 0)
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

    auto resource = monopoly.GetFieldByName(resource::FORD);
    monopoly.Buy(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 5500);

    resource = monopoly.GetFieldByName(resource::FORD);
    ASSERT_TRUE(resource.getOwnerIndex() != 0);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto resource = monopoly.GetFieldByName(resource::FORD);
    monopoly.Buy(1, resource);

    resource = monopoly.GetFieldByName(resource::FORD);
    monopoly.Renta(2, resource);

    auto player1 = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player1.getBalance(), 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(player2.getBalance(), 5750);
}


bool operator== (const Field & a, const Field & b)
{
    return a.getBrand() == b.getBrand() &&
            a.getType() == b.getType() &&
            a.getOwnerIndex() == b.getOwnerIndex();
}
