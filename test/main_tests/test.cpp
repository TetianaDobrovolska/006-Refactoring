#include "gtest/gtest.h"
#include "monopoly.hpp"
#include "auto.hpp"
#include "bank.hpp"
#include "clothes.hpp"
#include "food.hpp"
#include "prison.hpp"
#include "travel.hpp"

using namespace ::std;

TEST(MonopolyTest, GetPlayersReturnsCorrectResult) {
    vector<string> expected_players = { "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(expected_players);

    auto actual_players = monopoly.getPlayers();
    int i = 0;
    for (auto p : actual_players) {
        ASSERT_STREQ(p->getName().c_str(), expected_players[i++].c_str());
        ASSERT_EQ(p->getBalance(), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(MonopolyTest, GetOrganisationsReturnsCorrectResult) {
    std::vector<std::shared_ptr<Organisation>> expected_companies {
        make_shared<Auto>("Ford"),
        make_shared<Food>("MCDonald"),
        make_shared<Clothes>("Lamoda"),
        make_shared<Travel>("Air Baltic"),
        make_shared<Travel>("Nordavia"),
        make_shared<Prison>(),
        make_shared<Auto>("TESLA")
    };

    vector<string> players = { "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players);

    auto actual_companies = monopoly.getOrganisations();
    int i = 0;
    for (const auto& x : actual_companies) {
        ASSERT_EQ(x->getName(), expected_companies[i]->getName());
        ASSERT_EQ(x->getOwner(), expected_companies[i]->getOwner());
        ASSERT_EQ(x->getRent(), expected_companies[i]->getRent());
        ASSERT_EQ(x->getValue(), expected_companies[i]->getValue());
        ASSERT_EQ(x->isForRent(), expected_companies[i]->isForRent());
        ASSERT_EQ(x->isForSale(), expected_companies[i]->isForSale());
        i++;
    }
    ASSERT_TRUE(i);
}

TEST(MonopolyTest, PlayerBuyNoOwnedCompanies)
{
    vector<string> players = { "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players);
    auto x = monopoly.getOrganisationByName("Ford");
    monopoly.buy("Peter", "Ford");

    auto player = monopoly.getPlayerByName("Peter");
    ASSERT_EQ(player->getBalance(), 5500);
    ASSERT_TRUE(!x->getOwner().empty());
}

TEST(MonopolyTest, RentShouldBeCorrectTransferMoney)
{
    vector<string> players = { "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players);
    ASSERT_TRUE(monopoly.buy("Peter", "Ford"));
    ASSERT_TRUE(monopoly.rent("Ekaterina", "Ford"));
    auto peter = monopoly.getPlayerByName("Peter");
    ASSERT_EQ(peter->getBalance(), 5750);

    auto ekaterina = monopoly.getPlayerByName("Ekaterina");
    ASSERT_EQ(ekaterina->getBalance(), 5750);
}
