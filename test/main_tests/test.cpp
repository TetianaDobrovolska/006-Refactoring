#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

TEST(MonopolyTest, GetPlayersReturnsCorrectResult) {
    vector<string> players = { "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    auto x = monopoly.getPlayers();
    int i = 0;
    for (auto c : x) {
        ASSERT_STREQ(get<0>(c).c_str(), players[i++].c_str());
        ASSERT_EQ(get<1>(c), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(MonopolyTest, GetFieldsReturnsCorrectResult) {
    tuple<string, Monopoly::FieldType,int,bool> expectedCompanies[]{
        make_tuple("Ford",Monopoly::AUTO ,0,false),
        make_tuple("MCDonald",Monopoly::FOOD,0,false),
        make_tuple("Lamoda",Monopoly::CLOTHES,0,false),
        make_tuple("Air Baltic",Monopoly::TRAVEL,0,false),
        make_tuple("Nordavia",Monopoly::TRAVEL,0,false),
        make_tuple("Prison",Monopoly::PRISON,0,false),
        make_tuple("MCDonald",Monopoly::FOOD,0,false),
        make_tuple("TESLA",Monopoly::AUTO,0,false)
    };

    vector<string> players = { "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
   auto actualCompanies = monopoly.getFields();
   int i = 0;
   for (auto x : actualCompanies)
   {
       ASSERT_EQ(x, expectedCompanies[i++]);
   }
   ASSERT_TRUE(i);   
}

TEST(MonopolyTest, PlayerBuyNoOwnedCompanies)
{
    vector<string> players = { "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto x = monopoly.getFieldByName("Ford");
    monopoly.buy(1, x);

    auto player = monopoly.getPlayer(1);
    ASSERT_EQ(get<1>(player), 5500);
    x = monopoly.getFieldByName("Ford");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST(MonopolyTest, RentShouldBeCorrectTransferMoney)
{
    vector<string> players = { "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto x = monopoly.getFieldByName("Ford");
    monopoly.buy(1, x);

    x = monopoly.getFieldByName("Ford");
    monopoly.rent(2, x);
    auto player1 = monopoly.getPlayer(1);
    ASSERT_EQ(get<1>(player1), 5750);

    auto player2 = monopoly.getPlayer(2);
    ASSERT_EQ(get<1>(player2), 5750);    
}

bool operator== (std::tuple<std::string, Monopoly::FieldType, int, bool> & a , std::tuple<std::string, Monopoly::FieldType, int, bool> & b)
{
    return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b);
}
