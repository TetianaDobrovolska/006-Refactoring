#include "gtest/gtest.h"
#include "monopoly.hpp"

TEST(LAB2, GetPlayersListReturnCorrectList) {
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players,3);
    auto playersList = monopoly.GetPlayersList();

    int i = 0;
    for (auto player : playersList) {
        ASSERT_STREQ(player.getName().c_str(), players[i++].c_str());
        ASSERT_EQ(player.getBalance(), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    std::tuple<std::string, Monopoly::Type, int, bool> expectedCompanies [] {
        std::make_tuple("Ford", Monopoly::AUTO, 0, false),
        std::make_tuple("MCDonald", Monopoly::FOOD, 0, false),
        std::make_tuple("Lamoda", Monopoly::CLOTHER, 0, false),
        std::make_tuple("Air Baltic", Monopoly::TRAVEL, 0, false),
        std::make_tuple("Nordavia", Monopoly::TRAVEL, 0, false),
        std::make_tuple("Prison", Monopoly::PRISON, 0, false),
        std::make_tuple("MCDonald", Monopoly::FOOD, 0, false),
        std::make_tuple("TESLA", Monopoly::AUTO, 0, false)
    };
    std::string players[]{ "Peter","Ekaterina","Alexander" };

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
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto resource = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, resource);

    auto player = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player.getBalance(), 5500);

    resource = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(std::get<2>(resource) != 0);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto resource = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, resource);

    resource = monopoly.GetFieldByName("Ford");
    monopoly.Renta(2, resource);

    auto player1 = monopoly.GetPlayerInfo(1);
    ASSERT_EQ(player1.getBalance(), 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    ASSERT_EQ(player2.getBalance(), 5750);
}


bool operator== (std::tuple<std::string, Monopoly::Type, int, bool> & a, std::tuple<std::string, Monopoly::Type, int, bool> & b)
{
    return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
