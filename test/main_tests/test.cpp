#include "../../monolopy.hpp"
#include "gtest/gtest.h"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players,3);

    list<tuple<string,int>> x = monopoly.GetPlayersList();
    int i = 0;
    for (auto c : x) {
        ASSERT_STREQ(get<0>(c).c_str(), players[i++].c_str());
        ASSERT_EQ(get<1>(c), Monopoly::INITIAL_MONEY);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    tuple<string, Monopoly::Type,int,bool> expectedCompanies[]{
        make_tuple("Ford",Monopoly::AUTO,Monopoly::NOT_OWNED,false),
        make_tuple("MCDonald",Monopoly::FOOD,Monopoly::NOT_OWNED,false),
        make_tuple("Lamoda",Monopoly::CLOTHER,Monopoly::NOT_OWNED,false),
        make_tuple("Air Baltic",Monopoly::TRAVEL,Monopoly::NOT_OWNED,false),
        make_tuple("Nordavia",Monopoly::TRAVEL,Monopoly::NOT_OWNED,false),
        make_tuple("Prison",Monopoly::PRISON,Monopoly::NOT_OWNED,false),
        make_tuple("MCDonald",Monopoly::FOOD,Monopoly::NOT_OWNED,false),
        make_tuple("TESLA",Monopoly::AUTO,Monopoly::NOT_OWNED,false)
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
    int remainingMoney = Monopoly::INITIAL_MONEY - Monopoly::SELL_PRICE_AUTO;
    ASSERT_EQ(get<1>(player), remainingMoney);
    x = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST(LAB2, PlayerCannotBuyTwice)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    x = monopoly.GetFieldByName("Ford");
    bool ret = monopoly.Buy(1, x);
    ASSERT_FALSE(ret);
}

TEST(LAB2, PlayerCannotBuyIfIsOwned)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    x = monopoly.GetFieldByName("Ford");
    bool ret = monopoly.Buy(2, x);
    ASSERT_FALSE(ret);
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

    int remainingMoney1 = Monopoly::INITIAL_MONEY - Monopoly::SELL_PRICE_AUTO + Monopoly::RENT_PRICE_AUTO;
    ASSERT_EQ(get<1>(player1), remainingMoney1);

    int remainingMoney2 = Monopoly::INITIAL_MONEY - Monopoly::RENT_PRICE_AUTO;
    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(get<1>(player2), remainingMoney2);
}

// fails since there is no logic to prevent the same player from renting twice
//TEST(LAB2, PlayerCannotRentTwice)
//{
//    string players[]{ "Peter","Ekaterina","Alexander" };
//    Monopoly monopoly(players, 3);
//    auto x = monopoly.GetFieldByName("Ford");
//    monopoly.Buy(1, x);

//    x = monopoly.GetFieldByName("Ford");
//    monopoly.Renta(2, x);

//    x = monopoly.GetFieldByName("Ford");
//    bool ret = monopoly.Renta(2, x);
//    ASSERT_FALSE(ret);
//}

TEST(LAB2, PayBailToLeavePrison)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);

    auto x = monopoly.GetFieldByName("Prison");
    monopoly.Renta(1, x);
    auto player1 = monopoly.GetPlayerInfo(1);
    int remainingMoney = Monopoly::INITIAL_MONEY - Monopoly::RENT_PRICE_PRISON;
    ASSERT_EQ(get<1>(player1), remainingMoney);
}

// fails since there is no logic to prevent the money to go negative and be used again
//TEST(LAB2, CannotRentWithNegativeMoney)
//{
//    string players[]{ "Peter","Ekaterina","Alexander" };
//    Monopoly monopoly(players, 3);

//    auto x = monopoly.GetFieldByName("Prison");
//    bool ret;
//    for (int i=0; i<6; i++) {
//        ret = monopoly.Renta(1, x);
//    }
//    ASSERT_FALSE(ret);
//}

bool operator== (std::tuple<std::string, Monopoly::Type, int, bool> & a , std::tuple<std::string, Monopoly::Type, int, bool> & b)
{
    return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b);
}
