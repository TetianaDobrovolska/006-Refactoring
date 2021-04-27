#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    auto begin = monopoly.GetPlayersListBegin();
	auto end = monopoly.GetPlayersListEnd();
	int i = 0;
	for (auto it = begin; it != end; it++)
    {
        ASSERT_STREQ((*it)->getName().c_str(), players[i++].c_str());
        ASSERT_EQ((*it)->getMoney(), 6000);
    }
    ASSERT_TRUE(i);
}

 TEST(LAB2, GetFieldsListReturnCorrectList) {
     BaseField* expectedCompanies[]{
         new AutoField("Ford",0,false),
         new FoodField("MCDonald",0,false),
         new ClotherField("Lamoda",0,false),
         new TravelField("Air Baltic",0,false),
         new TravelField("Nordavia",0,false),
         new PrisonField("Prison",0,false),
         new FoodField("MCDonald",0,false),
         new AutoField("TESLA",0,false)
     };
     string players[]{ "Peter","Ekaterina","Alexander" };

     Monopoly monopoly(players, 3);
	auto begin = monopoly.GetFieldsListBegin();
	auto end = monopoly.GetFieldsListEnd();
    int i = 0;
    for (auto it = begin; it != end; it++)
    {
        ASSERT_EQ(**it, *expectedCompanies[i++]);
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
    ASSERT_EQ(player->getMoney(), 5500);
    x = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(x->getOwner() != 0);
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
    ASSERT_EQ(player1->getMoney(), 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(player2->getMoney(), 5750);    
}


bool operator== (const BaseField& a,const BaseField& b)
{
	return a.getName() == b.getName() && a.getOwner() == b.getOwner() && a.getFlag() == b.getFlag();
}