#include <vector>
#include "gtest/gtest.h"
#include "monopoly.hpp"

using namespace ::std;

class LAB2 : public ::testing::Test
{
protected:
    vector<std::string> playersName;

    int startMoney = 6000;

    void SetUp()
    {
        playersName.push_back("Peter");
        playersName.push_back("Ekaterina");
        playersName.push_back("Alexander");

        monopoly = new Monopoly(playersName, startMoney);
    }

    void TearDown()
    {
        delete monopoly;
    }

    Monopoly *monopoly;
};

TEST_F(LAB2, returnCorrectPlayerList)
{
    size_t i = 0;

    for (auto p : monopoly->players())
    {
        string name = p->name();
        string actualName = playersName[i++];

        ASSERT_STREQ(name.c_str(), actualName.c_str());
        ASSERT_EQ(p->money(), startMoney);
    }
    ASSERT_TRUE(i);
}

TEST_F(LAB2, returnCorrectFieldList)
{
    size_t i = 0;

    vector<string> actualFieldName{"Ford", "MCDonald", "Lamoda", "Air Baltic",
                                   "Nordavia", "Prison", "Bank", "TESLA"};

    vector<Field::Types> actualFieldType { Field::AUTO, Field::FOOD, Field::CLOTHER, Field::TRAVEL,
                                           Field::TRAVEL, Field::PRISON, Field::BANK, Field::AUTO };

    for (auto f : monopoly->fields())
    {

        ASSERT_STREQ(f->fieldName().c_str(), actualFieldName[i].c_str());
        ASSERT_EQ(f->fieldType(), actualFieldType[i]);
        ASSERT_TRUE(f->noOwner());
        i++;
    }
    ASSERT_TRUE(i);
}


TEST_F(LAB2, PlayerBuyNoOwnedAutoCompany)
{
    Player *p = monopoly->players()[0];
    Field *f = monopoly->fields()[0];

    ASSERT_TRUE(monopoly->byuField(p, f));

    const int restOfMoney = 5500;
    ASSERT_EQ(p->money(), restOfMoney);

    ASSERT_EQ(f->fieldOwner(), p);
}

TEST_F(LAB2, PlayerPayRentToPlayer)
{
    Player *p = monopoly->players()[0];
    Field *f = monopoly->fields()[0];
    Player *fieldOwner = f->fieldOwner();

    ASSERT_TRUE(monopoly->rentField(p, f));

    const int activePlayerMoney = 5750;
    const int ownerFieldMoney = 6250;
    ASSERT_EQ(p->money(), activePlayerMoney);
    ASSERT_EQ(fieldOwner->money(), ownerFieldMoney);
}

TEST_F(LAB2, PlayerPayRentToSpecial)
{
    Player *p = monopoly->players()[0];
    Field *f = monopoly->fields()[5];

    ASSERT_TRUE(f->specialField());

    ASSERT_TRUE(monopoly->rentField(p, f));

    const int activePlayerMoney = 5000;

    ASSERT_EQ(p->money(), activePlayerMoney);
}
