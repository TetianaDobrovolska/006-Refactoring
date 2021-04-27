#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    PlayerIterator player_it = monopoly.GetPlayersList();
    int i = 0;
    for (auto c = player_it; c != monopoly.PlayersEnd(); ++c) {
        ASSERT_STREQ(c->getName().c_str(), players[i++].c_str());
        ASSERT_EQ(c->getMoney(), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    Field expectedCompanies[]{
        FieldAuto("Ford"),
        FieldFood("MCDonald"),
        FieldClother("Lamoda"),
        FieldTravel("Air Baltic"),
        FieldTravel("Nordavia"),
        FieldPrison("Prison"),
        FieldFood("MCDonald"),
        FieldAuto("TESLA")
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
   auto actualCompanies = monopoly.GetFieldsList();
   int i = 0;
   for (auto x = actualCompanies; x != monopoly.FieldsEnd(); ++x)
   {
       ASSERT_EQ(*x, expectedCompanies[i++]);
   }
   ASSERT_TRUE(i);   
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    auto player = monopoly.GetPlayer(1);
    monopoly.Buy(player, *x);

    ASSERT_EQ(player->getMoney(), 5500);
    x = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(x->getPlayer()->getName() == "Peter");
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    auto player1 = monopoly.GetPlayer(1);
    monopoly.Buy(player1, *x);

    x = monopoly.GetFieldByName("Ford");
    monopoly.Renta(monopoly.GetPlayer(2), *x);
    ASSERT_EQ(player1->getMoney(), 5750);

    auto player2 = monopoly.GetPlayer(2);
    ASSERT_EQ(player2->getMoney(), 5750);
}


bool operator== (const Field & a, const Field & b)
{
    return a.getName() == b.getName() && a.getType() == b.getType() && a.getPlayer() == b.getPlayer();
}
