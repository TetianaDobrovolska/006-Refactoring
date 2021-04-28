#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    auto x = monopoly.GetPlayersList();

    int i = 0;
    for (auto c : x) {
        ASSERT_STREQ(c.GetName().c_str(), players[i++].c_str());
        ASSERT_EQ(c.GetMoney(), Monopoly::startupCapital);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList)
{
    Field expectedCompanies[]{
        //make_tuple(company name, company industry type, owner id)
        Field("Ford", Field::AUTO ,0),
        Field("MCDonald", Field::FOOD,0),
        Field("Lamoda", Field::CLOTHES,0),
        Field("Air Baltic", Field::TRAVEL,0),
        Field("Nordavia", Field::TRAVEL,0),
        Field("Prison", Field::PRISON,0),
        Field("MCDonald", Field::FOOD,0),
        Field("TESLA", Field::AUTO,0)
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

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


bool operator== (const Field & a , const Field & b)
{
    return a.GetCompanyName() == b.GetCompanyName() && a.GetBusinessType() == b.GetBusinessType() && a.GetOwnerIndex() == b.GetOwnerIndex();
}
