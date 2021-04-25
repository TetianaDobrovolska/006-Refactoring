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

    list<tuple<string,int>>* x = monopoly->GetPlayersList();
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

   auto actualCompanies = monopoly->GetFieldsList();
   int i = 0;
   for (auto x : *actualCompanies)
   {
       ASSERT_EQ(x, expectedCompanies[i++]);
   }
   ASSERT_TRUE(i);   
}

TEST_F(LAB2, PlayerBuyNoOwnedCompanies)
{
    auto x = monopoly->GetFieldByName("Ford");
    monopoly->Buy(idPlayer1, x);

    const int restOfMoney = 5500;

    auto player = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player), restOfMoney);
    x = monopoly->GetFieldByName("Ford");
    ASSERT_TRUE(get<2>(x) != 0);
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney)
{
const int restOfMoney = 5750;

    auto x = monopoly->GetFieldByName("Ford");
    monopoly->Buy(idPlayer1, x);

    x = monopoly->GetFieldByName("Ford");
    monopoly->Renta(2, x);
    auto player1Info = monopoly->GetPlayerInfo(idPlayer1);
    ASSERT_EQ(get<1>(player1Info), restOfMoney);

    auto player2Info = monopoly->GetPlayerInfo(idPlayer2);
    ASSERT_EQ(get<1>(player2Info), restOfMoney);    
}


bool operator== (std::tuple<std::string, Monopoly::Type, int, bool> & a , std::tuple<std::string, Monopoly::Type, int, bool> & b)
{
    return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b);
}