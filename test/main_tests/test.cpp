#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    list<Player> x = monopoly.GetPlayersList();
    int i = 0;
    for (auto c : x) {
        ASSERT_STREQ(c.getName().c_str(), players[i++].c_str());
        ASSERT_EQ(c.getBudget(), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetPlayersList_Modify_ValueOfClassUnchanged) {

    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);
    list<Player> x = monopoly.GetPlayersList();
    x.push_back(Player("NewPlayer", 4, 6000));
    list<Player> y = monopoly.GetPlayersList();
    ASSERT_TRUE(x.size() != y.size());
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    Company expectedCompanies[]{
        Company("Ford",Company::AUTO,500,250),
        Company("MCDonald",Company::FOOD,250,0),
        Company("Lamoda",Company::CLOTHER,100,250),
        Company("Air Baltic",Company::TRAVEL,700,250),
        Company("Nordavia",Company::TRAVEL,700,250),
        Company("Prison",Company::PRISON,1000,1000),
        Company("MCDonald",Company::FOOD,250,0),
        Company("TESLA",Company::AUTO,500,250)
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

TEST(LAB2, GetFieldsList_Modify_ValueOfClassUnchanged) {
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
   auto companiesList = monopoly.GetFieldsList();
   companiesList.push_back(Company("NEWCOMPANY",Company::AUTO,500,250));
   auto actualCompanies = monopoly.GetFieldsList();
   ASSERT_TRUE(actualCompanies.size() != companiesList.size());
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBudget(), 5500);
    x = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(x.getOwnerId() == player.getPlayerId());
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
    ASSERT_EQ(player1.getBudget(), 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(player2.getBudget(), 5750);    
}


bool operator== (const Company & a , const Company b)
{
    return a.getName() == b.getName() && a.getType() == b.getType() && a.getOwnerId() == b.getOwnerId() && a.getBuyPrice() == b.getBuyPrice();
}
