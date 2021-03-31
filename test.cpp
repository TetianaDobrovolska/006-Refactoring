#include "monolopy.hpp"

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string playerNames[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(playerNames, 3);

    const Monopoly::PlayerVector* players = monopoly.GetPlayers();
    int i = 0;
    for (auto player : *players) {
        ASSERT_STREQ(player.getPlayerName().c_str(), playerNames[i++].c_str());
        ASSERT_EQ(player.getPlayerBalance(), 6000);
    }
    ASSERT_TRUE(i);
}

//TEST(LAB2, GetPlayersListReturnCorrectList_emptyString) {
//    string players[]{ "" };
//
//    Monopoly monopoly(players, 1);
//
//    list<tuple<string, int>>* x = monopoly.GetPlayers();
//    int i = 0;
//    for (auto c : *x) {
//        ASSERT_STREQ(get<0>(c).c_str(), players[i++].c_str());
//        ASSERT_EQ(get<1>(c), 6000);
//    }
//    ASSERT_TRUE(i);
//}
//
//TEST(LAB2, GetPlayersListReturnCorrectList_MoreThan10Player) {
//    string players[]{ "one", "two", "three", "four", "five",
//        "six", "seven", "eight", "nine", "ten", "eleven" };
//
//    Monopoly monopoly(players, 11);
//
//    list<tuple<string, int>>* x = monopoly.GetPlayers();
//    int i = 0;
//    for (auto c : *x) {
//        ASSERT_STREQ(get<0>(c).c_str(), players[i++].c_str());
//        ASSERT_EQ(get<1>(c), 6000);
//    }
//    ASSERT_TRUE(i);
//}
TEST(LAB2, GetFieldsListReturnCorrectList) {
    Monopoly::FieldList expectedCompanies{
        new Auto("Ford"),
        new Food("MCDonald"),
        new Clother("Lamoda"),
        new Travel("Air Baltic"),
        new Travel("Nordavia"),
        new Prison("Prison"),
        new Food("MCDonald"),
        new Auto("TESLA")
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto actualCompanies = monopoly.GetFields();
    for (auto x : *actualCompanies)
    {
        ASSERT_EQ(x->getFieldName(), expectedCompanies.front()->getFieldName());
        expectedCompanies.pop_front();
    }
}
//
//TEST(LAB2, PlayerBuyNoOwnedCompanies)
//{
//    string players[]{ "Peter","Ekaterina","Alexander" };
//    Monopoly monopoly(players, 3);
//    Player player;
//    for (auto p : *monopoly.GetPlayers())
//    {
//        if (p.getPlayerName()
//    }
//    monopoly.Buy("Ekaterina", "Ford");
//
//    ASSERT_EQ(player->getPlayerBalance(), 5500);
//    x = monopoly.GetFieldByName("Ford");
//    ASSERT_TRUE(get<2>(x) != 0);
//}
//
//TEST(LAB2, DISABLED_PlayerWantToBuyNotExistingField)
//{
//    string players[]{ "Peter","Ekaterina","Alexander" };
//
//    Monopoly monopoly(players, 3);
//    auto x = monopoly.GetFieldByName("BMW");
//    monopoly.Buy(1, x);
//
//    auto player = monopoly.GetPlayerInfo(1);
//    ASSERT_EQ(get<1>(player), 6000);
//    x = monopoly.GetFieldByName("Ford");
//    ASSERT_TRUE(get<2>(x) == 0);
//}
//
//TEST(LAB2, DISABLED_GetPlayerInfo_WrongIndex)
//{
//    string players[]{ "Peter","Ekaterina","Alexander" };
//
//    Monopoly monopoly(players, 3);
//    auto player = monopoly.GetPlayerInfo(0);
//    string expectedString = "";
//    int    expectedInt = 0;
//
//    ASSERT_EQ(get<0>(player), expectedString);
//    ASSERT_EQ(get<1>(player), expectedInt);
//}
//
//TEST(LAB2, RentaShouldBeCorrectTransferMoney)
//{
//    string players[]{ "Peter","Ekaterina","Alexander" };
//    Monopoly monopoly(players, 3);
//    auto x = monopoly.GetFieldByName("Ford");
//    monopoly.Buy(1, x);
//
//    x = monopoly.GetFieldByName("Ford");
//    monopoly.Renta(2, x);
//    auto player1 = monopoly.GetPlayerInfo(1);
//    ASSERT_EQ(get<1>(player1), 5750);
//
//    auto player2 = monopoly.GetPlayerInfo(2);
//    ASSERT_EQ(get<1>(player2), 5750);
//}
//
//
//// MATCHER ?
//bool operator== (std::tuple<std::string, Monopoly::FieldType, int, bool>& a, std::tuple<std::string, Monopoly::FieldType, int, bool>& b)
//{
//    return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b);
//}