#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

class LAB2 : public ::testing::Test
{
    protected:

        string players[3] = {"Peter","Ekaterina","Alexander"};

        const int idPlayer1 = 1;
        const int idPlayer2 = 2;

        void SetUp()
        {
            size_t playersCount = sizeof(players)/sizeof(*players);
            
            monopoly = new Monopoly(players, playersCount);
        }

        void TearDown()
        {
            delete monopoly;
        }

        Monopoly *monopoly;
};

TEST_F(LAB2, GetPlayersListReturnCorrectList) {

    const list<tuple<string,int>>* x = monopoly->GetPlayersList();
    const int startMoney = 6000;
    int i = 0;
    for (auto c : *x) {
        ASSERT_STREQ(get<0>(c).c_str(), players[i++].c_str());
        ASSERT_EQ(get<1>(c), startMoney);
    }
    ASSERT_TRUE(i);
}

TEST_F(LAB2, GetFieldsListReturnCorrectList) {
    tuple<string, Monopoly::Type,int,bool> expectedCompanies[]{
        make_tuple("Ford",Monopoly::AUTO ,0,false),
        make_tuple("MCDonald",Monopoly::FOOD,0,false),
        make_tuple("Lamoda",Monopoly::CLOTHER,0,false),
        make_tuple("Air Baltic",Monopoly::TRAVEL,0,false),
        make_tuple("Nordavia",Monopoly::TRAVEL,0,false),
        make_tuple("Prison",Monopoly::PRISON,0,false),
        make_tuple("MCDonald",Monopoly::FOOD,0,false),
        make_tuple("TESLA",Monopoly::AUTO,0,false)
    };

   const auto actualCompanies = monopoly->GetFieldsList();
   int i = 0;
   for (auto x : *actualCompanies)
   {
       ASSERT_EQ(x, expectedCompanies[i++]);
   }
   ASSERT_TRUE(i);   
}

TEST_F(LAB2, UpdatePlayerCashSetCorrectValue)
{
    const int newPlayesrCashAmount = 3333;
    
    monopoly->UpdatePlayerCash(idPlayer1, newPlayesrCashAmount);

    auto player = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player), newPlayesrCashAmount);
}

TEST_F(LAB2, PlayerBuyNoOwnedAutoCompany)
{
    auto x = monopoly->GetFieldByName("Ford");
    monopoly->Buy(idPlayer1, x);

    const int restOfMoney = 5500;

    auto player = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player), restOfMoney);
    x = monopoly->GetFieldByName("Ford");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST_F(LAB2, PlayerBuyNoOwnedFoodCompany)
{
    auto x = monopoly->GetFieldByName("MCDonald");
    monopoly->Buy(idPlayer1, x);

    const int restOfMoney = 5750;

    auto player = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player), restOfMoney);
    x = monopoly->GetFieldByName("MCDonald");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST_F(LAB2, PlayerBuyNoOwnedTravelCompany)
{
    auto x = monopoly->GetFieldByName("Nordavia");
    monopoly->Buy(idPlayer1, x);

    const int restOfMoney = 5300;

    auto player = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player), restOfMoney);
    x = monopoly->GetFieldByName("Nordavia");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST_F(LAB2, PlayerBuyNoOwnedClotherCompany)
{
    auto x = monopoly->GetFieldByName("Lamoda");
    monopoly->Buy(idPlayer1, x);

    const int restOfMoney = 5900;

    auto player = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player), restOfMoney);
    x = monopoly->GetFieldByName("Lamoda");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney_AUTO)
{
    const int restOfMoneyPlayer1 = 5750;
    const int restOfMoneyPlayer2 = 5750;

    auto x = monopoly->GetFieldByName("Ford");
    monopoly->Buy(idPlayer1, x);

    x = monopoly->GetFieldByName("Ford");
    monopoly->Renta(2, x);
    auto player1Info = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player1Info), restOfMoneyPlayer1);

    auto player2Info = monopoly->GetPlayerInfo(idPlayer2);
    ASSERT_EQ(get<1>(player2Info), restOfMoneyPlayer2);    
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney_FOOD)
{
    const int restOfMoneyPlayer1 = 6000;
    const int restOfMoneyPlayer2 = 5750;

    auto x = monopoly->GetFieldByName("MCDonald");
    monopoly->Buy(idPlayer1, x);

    x = monopoly->GetFieldByName("MCDonald");
    monopoly->Renta(2, x);
    auto player1Info = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player1Info), restOfMoneyPlayer1);

    auto player2Info = monopoly->GetPlayerInfo(idPlayer2);
    ASSERT_EQ(get<1>(player2Info), restOfMoneyPlayer2);    
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney_TRAVEL)
{
    const int restOfMoneyPlayer1 = 5550;
    const int restOfMoneyPlayer2 = 5750;

    auto x = monopoly->GetFieldByName("Nordavia");
    monopoly->Buy(idPlayer1, x);

    x = monopoly->GetFieldByName("Nordavia");
    monopoly->Renta(2, x);
    auto player1Info = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player1Info), restOfMoneyPlayer1);

    auto player2Info = monopoly->GetPlayerInfo(idPlayer2);
    ASSERT_EQ(get<1>(player2Info), restOfMoneyPlayer2);    
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney_CLOTHER)
{
    const int restOfMoneyPlayer1 = 6150;
    const int restOfMoneyPlayer2 = 5750;

    auto x = monopoly->GetFieldByName("Lamoda");
    monopoly->Buy(idPlayer1, x);

    x = monopoly->GetFieldByName("Lamoda");
    monopoly->Renta(2, x);
    auto player1Info = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player1Info), restOfMoneyPlayer1);

    auto player2Info = monopoly->GetPlayerInfo(idPlayer2);
    ASSERT_EQ(get<1>(player2Info), restOfMoneyPlayer2);    
}

bool operator== (std::tuple<std::string, Monopoly::Type, int, bool> & a , std::tuple<std::string, Monopoly::Type, int, bool> & b)
{
    return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b);
}