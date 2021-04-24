#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players, 3);

    int i = 0;
    for (auto iterator = monopoly.GetPlayersListCbegin(); iterator != monopoly.GetPlayersListCend(); ++iterator)
    {
        ASSERT_STREQ(iterator->GetName().c_str(), players[i++].c_str());
        ASSERT_EQ(iterator->GetMoney(), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    Field expectedCompanies[]{
        Field("Ford",Field::AUTO ,0,false),
        Field("MCDonald",Field::FOOD,0,false),
        Field("Lamoda",Field::CLOTHER,0,false),
        Field("Air Baltic",Field::TRAVEL,0,false),
        Field("Nordavia",Field::TRAVEL,0,false),
        Field("Prison",Field::PRISON,0,false),
        Field("MCDonald",Field::FOOD,0,false),
        Field("TESLA",Field::AUTO,0,false)
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    int i = 0;
    for (auto iterator = monopoly.GetFieldsListCbegin(); iterator != monopoly.GetFieldsListCend(); ++iterator)
    {
        ASSERT_EQ(*iterator, expectedCompanies[i++]);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.GetMoney(), 5500);
    x = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(x.GetOwnerIndex() != 0);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    x = monopoly.GetFieldByName("Ford");
    monopoly.Renta(2, x);
    auto player1 = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player1.GetMoney(), 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(player2.GetMoney(), 5750);
}
