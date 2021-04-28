#include "gtest/gtest.h"

#include "auto_field.h"
#include "bank_field.h"
#include "cloth_field.h"
#include "food_field.h"
#include "monopoly.hpp"
#include "prison_field.h"
#include "travel_field.h"

TEST(LAB2, GetPlayersListReturnCorrectList) {
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players,3);
    auto playersList = monopoly.GetPlayersList();

    int i = 0;
    for (auto player : playersList) {
        ASSERT_STREQ(player.getName().c_str(), players[i++].c_str());
        ASSERT_EQ(monopoly.GetPlayerBalance(i), 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
    Field expectedCompanies [] {
        AutoField(Field::FORD, 0),
        FoodField(Field::MCDONALD, 0),
        ClothField(Field::LAMODA, 0),
        TravelField(Field::AIR_BALTIC, 0),
        TravelField(Field::NORDAVIA, 0),
        PrisonField(Field::BPRISON, 0),
        FoodField(Field::MCDONALD, 0),
        AutoField(Field::TESLA, 0),
    };
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    auto actualCompanies = monopoly.GetFieldsList();
    int i = 0;
    for (auto x : actualCompanies)
    {
        ASSERT_EQ(*x, expectedCompanies[i++]);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    const Field* resource = monopoly.GetFieldByName(Field::FORD);
    monopoly.Buy(1, resource);
    ASSERT_EQ(monopoly.GetPlayerBalance(1), 5500);

    resource = monopoly.GetFieldByName(Field::FORD);
    ASSERT_TRUE(resource->getOwnerIndex() != 0);

    delete []resource;
}

TEST(LAB2, PlayerBuyPrison)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    const Field* resource = monopoly.GetFieldByName(Field::BPRISON);
    monopoly.Buy(1, resource);
    ASSERT_EQ(monopoly.GetPlayerBalance(1), 6000);

    resource = monopoly.GetFieldByName(Field::BPRISON);
    ASSERT_TRUE(resource->getOwnerIndex() == 0);

    delete []resource;
}

TEST(LAB2, PlayerBuyUndefinedField)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    const Field* resource = new BankField(Field::eBrand::UKRSIBBANK, 0);
    ASSERT_FALSE(monopoly.Buy(1, resource));
    ASSERT_EQ(monopoly.GetPlayerBalance(1), 6000);

    delete []resource;
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    const Field* resource = monopoly.GetFieldByName(Field::FORD);
    monopoly.Buy(1, resource);

    resource = monopoly.GetFieldByName(Field::FORD);
    monopoly.Renta(2, resource);

    ASSERT_EQ(monopoly.GetPlayerBalance(1), 5750);
    ASSERT_EQ(monopoly.GetPlayerBalance(2), 5750);

    delete []resource;
}

TEST(LAB2, RentaPrison)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    const Field* resource = monopoly.GetFieldByName(Field::BPRISON);
    monopoly.Renta(1, resource);
    ASSERT_EQ(monopoly.GetPlayerBalance(1), 5000);

    delete []resource;
}

TEST(LAB2, RentaBank)
{
    std::string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    const Field* resource = new BankField(Field::UKRSIBBANK, 0);
    ASSERT_FALSE(monopoly.Renta(1, resource));
    ASSERT_EQ(monopoly.GetPlayerBalance(1), 6000);

    delete []resource;
}

bool operator== (const Field & a, const Field & b)
{
    return a.getBrand() == b.getBrand() &&
            a.getOwnerIndex() == b.getOwnerIndex();
}
